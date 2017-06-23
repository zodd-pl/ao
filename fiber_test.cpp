
#include <boost/fiber/all.hpp>


#include "gtest/gtest.h"
#include "gmock/gmock.h"

namespace fibers = boost::fibers;


TEST( fiber_basic, test )
{
	auto func = [] 
	{
		std::cout << "fiber: " << boost::this_fiber::get_id() << " enter" << std::endl;
		//boost::this_fiber::yield();
		std::cout << "fiber: " << boost::this_fiber::get_id() << " exit" << std::endl;
	};

	fibers::fiber f1(func);
	//fibers::fiber f2(func);

	f1.join();
	//f2.join();
}

