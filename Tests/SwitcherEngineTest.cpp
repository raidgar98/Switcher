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
		PRINT_TESTINFO( "TESTING: `SwitcherEngine::win` and `SwitcherEngine::operator bool`" );
		BOOST_REQUIRE( is_win() );
		BOOST_REQUIRE( eng );
		BOOST_REQUIRE( eng.win() );

		eng.shuffle();
		eng.reset();

		BOOST_REQUIRE( is_win() );
		BOOST_REQUIRE( eng );
		BOOST_REQUIRE( eng.win() );

		eng.null_swap( DUP );

		BOOST_REQUIRE( !is_win() );
		BOOST_REQUIRE( !eng );
		BOOST_REQUIRE( !eng.win() );
	}
}

BOOST_AUTO_TEST_CASE( test_case_04 )
{
	INITIALIZE_TEST( switcher_tester )
	{
		PRINT_TESTINFO( "TESTING: `SwitcherEngine::get` and `SwitcherEngine::operator[]`" );

		num value{ 1 };
		for( pos i = 0; i < BOARD_SIZE; i++ )
			for( pos j = 0; j < BOARD_SIZE; j++, value++ )
			{
				BOOST_REQUIRE_EQUAL( eng.get( i, j ), eng[i][j] );
				if( i == j && i == BOARD_SIZE - 1 ) BOOST_REQUIRE_EQUAL( eng[i][j], empty_value );
				else BOOST_REQUIRE_EQUAL( eng[i][j], value );
			}
	}
}

BOOST_AUTO_TEST_CASE( test_case_05 )
{
	INITIALIZE_TEST( switcher_tester )
	{
		PRINT_TESTINFO( "TESTING: `SwitcherEngine::null`" );
		const coord null_coord1{ eng.null() };
		for(pos i = 0; i < BOARD_SIZE; i++ )
			for( pos j = 0; j < BOARD_SIZE; j++ )
				if( eng[i][j] == empty_value )
				{
					BOOST_REQUIRE_EQUAL( null_coord1, coord(i, j) );
					break;
				}

		eng.null_swap(DUP);

		const coord null_coord2{ eng.null() };
		for( pos i = 0; i < BOARD_SIZE; i++ )
			for( pos j = 0; j < BOARD_SIZE; j++ )
				if( eng[i][j] == empty_value )
				{
					BOOST_REQUIRE_EQUAL( null_coord2, coord( i, j ) );
					break;
				}
	}
}

BOOST_AUTO_TEST_CASE( test_case_06 )
{
	INITIALIZE_TEST( switcher_tester )
	{
		PRINT_TESTINFO( "TESTING: `SwitcherEngine::reset`" );

		eng.shuffle();
		eng.reset();

		BOOST_REQUIRE( is_win() );
	}
}

BOOST_AUTO_TEST_CASE( test_case_07 )
{
	INITIALIZE_TEST( switcher_tester )
	{
		PRINT_TESTINFO( "TESTING: `SwitcherEngine::shuffle`" );

		eng.shuffle();

		BOOST_REQUIRE( !is_win() );
	}
}

BOOST_AUTO_TEST_CASE( test_case_08 )
{
	INITIALIZE_TEST( switcher_tester )
	{
		PRINT_TESTINFO( "TESTING: `SwitcherEngine::swap`" );

		coord n{ eng.null() };


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

		while( eng.null_swap( DUP ) ) {};
		while( eng.null_swap( DLEFT ) ) {};

		BOOST_REQUIRE_EQUAL( empty_value, eng[0][0] );
		BOOST_REQUIRE( !is_win() );
	}
}

BOOST_AUTO_TEST_SUITE_END()

