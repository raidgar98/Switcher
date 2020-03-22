#pragma warning(disable : 4996)
#pragma once

// STL
#include <chrono>
#include <ctime>
#include <iostream>
#include <sstream>

// Local Includes
#include "../Engine/SwitcherEngine.hpp"

// 3'rd party
#include "../sub/include/rang.hpp"

// constexpresions
constexpr size_t BOARD_SIZE{ 5ul };

// macros
#define FUN( FUN_NAME ) auto FUN_NAME = [&X](){ return X.FUN_NAME(); };
#define FIELD( FIELD_NAME ) auto& FIELD_NAME = X.FIELD_NAME;
#define INITIALIZE_TEST( CLASS ) CLASS X; FUN(is_win) FIELD(eng) FIELD(as_it_should_be)


class base_tester
{
private:	// varriables


	enum LOG_TYPE
	{
		__SUCCESS,
		__INFO,
		__TESTINFO,
		__WARNING,
		__ERROR
	};

public:		// methodes

private:	// methodes

	template<LOG_TYPE type, class T>
	static void log( T val ) noexcept
	{
		// timestamp
		const std::time_t now = std::chrono::system_clock::to_time_t( std::chrono::system_clock::now() );
		std::string timestamp( 30, '\0' );
		std::strftime( &timestamp[0], timestamp.size(), "%Y-%m-%d %H:%M:%S", std::localtime( &now ) );

		std::ostream* pout = &std::cout;
		if( type == __ERROR )
			pout = &std::cerr;
		std::ostream& out = *pout;
		pout = nullptr;

		out << rang::fg::gray;

		std::stringstream ss;
		ss << "[ " << timestamp << " ] " << val;

		if( type == __SUCCESS )
			out << rang::fgB::green << "[ SUCC ]" << ss.str();
		else if( type == __INFO )
			out << rang::fgB::gray << "[ INFO ]" << ss.str();
		else if( type == __TESTINFO )
			out << rang::fgB::blue << "[ TEST ]" << ss.str();
		else if( type == __WARNING )
			out << rang::fgB::yellow << "[ WARN ]" << ss.str();
		else out << rang::fgB::red << "[ ERRO ]" << ss.str();

		// out << rang::fg::reset;
		out << rang::fgB::gray << std::endl;
	}

	template<typename T>
	friend void PRINT_SUCCESS( T val );
	template<typename T>
	friend void PRINT_INFO( T val );
	template<typename T>
	friend void PRINT_TESTINFO( T val );
	template<typename T>
	friend void PRINT_WARNING( T val );
	template<typename T>
	friend void PRINT_ERROR( T val );
	template<typename T> 
	friend void ADD_TEST( T* val );
};

class switcher_tester : public base_tester
{
public:		// varriables

	SwitcherEngine< BOARD_SIZE > eng;
	storage_type< storage_type< num, BOARD_SIZE>, BOARD_SIZE > as_it_should_be;

public:		// methodes

	switcher_tester()
	{
		as_it_should_be = eng.data();

	}

	bool is_win()
	{
		return eng.data() == as_it_should_be;
	}

};

template<typename T> inline	void PRINT_SUCCESS( T val ) { base_tester::log	<base_tester::LOG_TYPE::__SUCCESS, T>( val ); }
template<typename T> inline void PRINT_INFO( T val ) { base_tester::log	<base_tester::LOG_TYPE::__INFO, T>( val ); }
template<typename T> inline void PRINT_TESTINFO( T val ) { base_tester::log	<base_tester::LOG_TYPE::__TESTINFO, T>( val ); }
template<typename T> inline void PRINT_WARNING( T val ) { base_tester::log	<base_tester::LOG_TYPE::__WARNING, T>( val ); }
template<typename T> inline void PRINT_ERROR( T val ) { base_tester::log	<base_tester::LOG_TYPE::__ERROR, T>( val ); }
template<typename T> inline void ADD_TEST( T* val ) { base_tester::tests.push_back( val ); }

//#undef _CRT_SECURE_NO_WARNINGS
