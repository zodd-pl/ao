
#include <iostream>
#include <thread>
#include <future>
#include <set>

#include <boost/coroutine2/all.hpp>

#include "gtest/gtest.h"
#include "gmock/gmock.h"

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

