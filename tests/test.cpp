#define BOOST_TEST_MAIN

#if !defined(WIN32) && !defined(BOOST_TEST_DYN_LINK)
#define BOOST_TEST_DYN_LINK
#endif

#define BOOST_TEST_MODULE AllTests
#include <boost/test/unit_test.hpp>
