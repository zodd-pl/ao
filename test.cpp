
#include <iostream>
#include <thread>
#include <future>
#include <set>

#include <boost/coroutine2/all.hpp>

#include "gtest/gtest.h"
#include "gmock/gmock.h"

#include "ao/all.h"

typedef boost::coroutines2::coroutine<void>   coro_t;

using namespace std;



TEST(basic,coroutine_resumed_by_diffrent_threads)
{
	set<thread::id> resuming_threads;

	coro_t::push_type coro([&](coro_t::pull_type& yield)
	{
		cout << "coro: 0 " << "thread: " << this_thread::get_id() << endl;
		resuming_threads.insert(this_thread::get_id());
		yield();
		cout << "coro: 1 " << "thread: " << this_thread::get_id() << endl;
		resuming_threads.insert(this_thread::get_id());
		yield();
		cout << "coro: 2 " << "thread: " << this_thread::get_id() << endl;
		resuming_threads.insert(this_thread::get_id());
		yield();
		cout << "coro: 3 " << "thread: " << this_thread::get_id() << endl;
		resuming_threads.insert(this_thread::get_id());
	});

	int i;
	for (i = 0; coro; i++)
	{
		cout << "main: " << i << endl;
		//coro();
		thread t([&]() {coro(); });
		t.join();
		//auto fut = async(std::launch::async, [&]() {coro(); });
		//fut.get();
	}

	cout << "main: return " << endl;

	ASSERT_EQ(i,resuming_threads.size());
}


TEST(action, basic)
{
	auto corotuine = [&](ao::coroutine & yield)
	{
		shared_ptr<void> x = yield.get();
		cout << "coro: 0 " << "thread: " << this_thread::get_id() << endl;
		cout << "use count: " << yield.get().use_count() << endl;
		async([]() {cout << "async: 0 " << "thread: " << this_thread::get_id() << endl; });// .then(resume coro);
		yield();
		cout << "coro: 1 " << "thread: " << this_thread::get_id() << endl;
		cout << "use count: " << yield.get().use_count() << endl;
		yield();
		cout << "coro: 2 " << "thread: " << this_thread::get_id() << endl;
	};

	ao::run(corotuine);	
}


