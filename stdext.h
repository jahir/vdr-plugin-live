#ifndef VDR_LIVE_STDEXT_H
#define VDR_LIVE_STDEXT_H

#if __GNUC__ >= 4

#if __GNUC__ >= 6

#include <memory>
#include <functional>

namespace std {
namespace tr1 {

       using std::bind;
       using std::shared_ptr;
       using std::weak_ptr;

       namespace placeholders {
               using std::placeholders::_1;
               using std::placeholders::_2;
               using std::placeholders::_3;
               using std::placeholders::_4;
               using std::placeholders::_5;
               using std::placeholders::_6;
               using std::placeholders::_7;
               using std::placeholders::_8;
               using std::placeholders::_9;
       }
} // namespace tr1
} // namespace std

#else

 #      include <tr1/functional>
 #      include <tr1/memory>

# endif

#else

#	include <boost/version.hpp>

#	define BOOST_MAJOR_VERSION (BOOST_VERSION / 100000)
#	define BOOST_MINOR_VERSION ((BOOST_VERSION / 100) % 1000)

#	if BOOST_MAJOR_VERSION >= 1 && BOOST_MINOR_VERSION >= 34

#		include <boost/tr1/functional.hpp>
#		include <boost/tr1/memory.hpp>

#	elif BOOST_MAJOR_VERSION >= 1 && BOOST_MINOR_VERSION >= 32

#		include <boost/bind.hpp>
#		include <boost/shared_ptr.hpp>
#		include <boost/weak_ptr.hpp>

namespace std { 
namespace tr1 {

	using boost::bind;
	using boost::shared_ptr;
	using boost::weak_ptr;

	namespace placeholders {
		using ::_1;
		using ::_2;
		using ::_3;
		using ::_4;
		using ::_5;
		using ::_6;
		using ::_7;
		using ::_8;
		using ::_9;
	}

} // namespace std
} // namespace tr1

#	else

#		error "Your Compiler is too old and you don't have boost >= 1.32.0 installed."
#		error "Please either install boost 1.32.0 or higher (1.34.0 is recommended)"
#		error "or upgrade your compiler suite to at least GCC 4.0"

#	endif

#endif

#endif // VDR_LIVE_STDEXT_H
