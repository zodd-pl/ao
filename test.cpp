
#include <iostream>
#include <thread>
#include <future>

#include <boost/coroutine2/all.hpp>

#include "gtest/gtest.h"

typedef boost::coroutines2::coroutine<void>   coro_t;

using namespace std;

int main(int argc, char **argv)
{
	coro_t::push_type coro([](coro_t::pull_type& yield)
	{
		cout << "coro: 1 " << "thread: " << this_thread::get_id() << endl;
		yield();
		cout << "coro: 2 " << "thread: " << this_thread::get_id() << endl;
		yield();
		cout << "coro: 3 " << "thread: " << this_thread::get_id() << endl;
		yield();
		cout << "coro: 4 " << "thread: " << this_thread::get_id() << endl;
		yield();
	});


	

	for (int i = 1; coro; i++)
	{
		cout << "main: " << i << endl;
		//coro();
		thread t([&]() {coro(); });
		t.join();
		//auto fut = async(std::launch::async, [&]() {coro(); });
		//fut.get();
	}

	cout << "main: return " << endl;


	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();


	//return 0;
}

