#define _HAS_AUTO_PTR_ETC 1
#define BOOST_TEST_MODULE switcher_test_cases

// Boost

#include <boost/test/included/unit_test.hpp>

// STL
#include <list>

// Local Includes
#include "Testers.hpp"

BOOST_AUTO_TEST_SUITE( switcher_test_cases )

BOOST_AUTO_TEST_CASE( test_case_01 )
{
	INITIALIZE_TEST( switcher_tester )
	{
		PRINT_TESTINFO( "TESTING: object dimensions" );

		BOOST_REQUIRE_EQUAL( X.eng.data().size(), BOARD_SIZE );
		for( size_t i = 0; i < BOARD_SIZE; i++ )
			BOOST_REQUIRE_EQUAL( X.eng[i].size(), BOARD_SIZE );
	}
}

BOOST_AUTO_TEST_CASE( test_case_02 )
{
	INITIALIZE_TEST( switcher_tester )
	{
		PRINT_TESTINFO(
			"TESTING: `SwitcherEngine::win` and `SwitcherEngine::operator bool`" );
	}
}

BOOST_AUTO_TEST_CASE( test_case_03 )
{
	INITIALIZE_TEST( switcher_tester )
	{
		PRINT_TESTINFO( "TESTING: `SwitcherEngine::data`" );
	}
}

BOOST_AUTO_TEST_CASE( test_case_04 )
{
	INITIALIZE_TEST( switcher_tester )
	{
		PRINT_TESTINFO(
			"TESTING: `SwitcherEngine::get` and `SwitcherEngine::operator[]`" );
	}
}

BOOST_AUTO_TEST_CASE( test_case_05 )
{
	INITIALIZE_TEST( switcher_tester )
	{
		PRINT_TESTINFO( "TESTING: `SwitcherEngine::null`" );
	}
}

BOOST_AUTO_TEST_CASE( test_case_06 )
{
	INITIALIZE_TEST( switcher_tester )
	{
		PRINT_TESTINFO( "TESTING: `SwitcherEngine::reset`" );
	}
}

BOOST_AUTO_TEST_CASE( test_case_07 )
{
	INITIALIZE_TEST( switcher_tester )
	{
		PRINT_TESTINFO( "TESTING: `SwitcherEngine::shuffle`" );
	}
}

BOOST_AUTO_TEST_CASE( test_case_08 )
{
	INITIALIZE_TEST( switcher_tester )
	{
		PRINT_TESTINFO( "TESTING: `SwitcherEngine::swap`" );
	}
}

BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE( complex_test_cases )

BOOST_AUTO_TEST_CASE( cmplx_test_01 )
{
	INITIALIZE_TEST( switcher_tester )
	{
		PRINT_TESTINFO( "TESTING: `SwitcherEngine::swap`" );
		
		BOOST_REQUIRE( is_win() );

		
		eng.shuffle();
		BOOST_REQUIRE( !is_win() );

		BOOST_REQUIRE_EQUAL(eng.null_swap( up ), true);
		BOOST_REQUIRE( !is_win() );
	}
}

BOOST_AUTO_TEST_SUITE_END()

