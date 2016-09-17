

#ifndef ALL_H_alskflaskflk
#define ALL_H_alskflaskflk

#include <boost/coroutine2/all.hpp>

namespace ao
{
	using coroutine_shared_ptr = std::shared_ptr<void>;
	using coro_t = boost::coroutines2::coroutine<const coroutine_shared_ptr &>;
	using coroutine = coro_t::pull_type;

	class action
	{

	public:
		template <typename COROUTINE>
		action(const COROUTINE & c)
		: coro(c)
		{
		}

		action(const action &) = delete;

		~action()
		{
			std::cout << "action::~action: " << std::endl;
		}

		void run(const coroutine_shared_ptr & ptr)
		{
			coro(ptr);
		}

	private:
		coro_t::push_type coro;
	};

	template <typename COROUTINE> 
	bool run(const COROUTINE &c)
	{	
		{
			auto a = make_shared<action>(c);
			a->run(a);
		}
		std::cout << "ao::run: " << std::endl;
		return true;
	}

}

#endif // !ALL_H_alskflaskflk
