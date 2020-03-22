#pragma once

#include "../GUIRT/Generated Files/MainPage.g.h"
#include "../Engine/SwitcherEngine.hpp"

#include <array>
#include <map>
#include <functional>

#define __BOARD_SIZE 4;

using winrt::Windows::UI::Xaml::Controls::Button;
constexpr size_t BOARD_SIZE = __BOARD_SIZE;

#define add(x, y) if(posx == coord(x, y)) return B##x##_##y##();
/*refs[x][y] = std::function<Button()>([&](){ return B##x##_##y(); }); \
B##x##_##y##().TabIndex( coord_to_tool_tip({x, y}) ); \
buttons[coord_to_tool_tip({x, y})] = {x, y}; \
color_button_to_default(B##x##_##y());*/


namespace winrt::GUIRT::implementation
{
	struct MainPage : MainPageT<MainPage>
	{
		//std::array<std::array<std::function<Button()>, BOARD_SIZE>, BOARD_SIZE> refs;
		std::map< int, coord > buttons;
		bool is_swap_button_setted{ false };
		Button swap_button;
		SwitcherEngine<BOARD_SIZE> eng;

		void switch_button( Button btn, const bool mod_to = false );
		void sync();
		void sync_single_cell( const pos row, const pos col );
		void refresh();
		void shuffle();
		void msg( const wchar_t* msg ) const;
		void add_to_swap( Button btn );
		void color_button_as_pending( Button btn );
		void color_button_to_default( Button btn );
		bool try_swap( Button second );
		bool check_win();
		coord tool_tip_to_coord( const Button btn );
		int coord_to_tool_tip( const coord& cell );
		void switch_all_buttons( const bool switch_to );
		void end_turn( const bool is_win );
		void set_content( Button btn, const wchar_t* msg );
		void set_content( Button btn, const std::wstring& msg );
		Button get_button( const pos _x, const pos _y );
		Button get_button( const coord& posx );

		MainPage();

		int32_t MyProperty();
		void MyProperty( int32_t value );

		void ClickHandler( Windows::Foundation::IInspectable const& sender, Windows::UI::Xaml::RoutedEventArgs const& args );
		void B0_0_Click( winrt::Windows::Foundation::IInspectable const& sender, winrt::Windows::UI::Xaml::RoutedEventArgs const& e );
		void B0_1_Click( winrt::Windows::Foundation::IInspectable const& sender, winrt::Windows::UI::Xaml::RoutedEventArgs const& e );
		void B0_2_Click( winrt::Windows::Foundation::IInspectable const& sender, winrt::Windows::UI::Xaml::RoutedEventArgs const& e );
		void B0_3_Click( winrt::Windows::Foundation::IInspectable const& sender, winrt::Windows::UI::Xaml::RoutedEventArgs const& e );
		void B1_0_Click( winrt::Windows::Foundation::IInspectable const& sender, winrt::Windows::UI::Xaml::RoutedEventArgs const& e );
		void B1_1_Click( winrt::Windows::Foundation::IInspectable const& sender, winrt::Windows::UI::Xaml::RoutedEventArgs const& e );
		void B1_2_Click( winrt::Windows::Foundation::IInspectable const& sender, winrt::Windows::UI::Xaml::RoutedEventArgs const& e );
		void B1_3_Click( winrt::Windows::Foundation::IInspectable const& sender, winrt::Windows::UI::Xaml::RoutedEventArgs const& e );
		void B2_0_Click( winrt::Windows::Foundation::IInspectable const& sender, winrt::Windows::UI::Xaml::RoutedEventArgs const& e );
		void B2_1_Click( winrt::Windows::Foundation::IInspectable const& sender, winrt::Windows::UI::Xaml::RoutedEventArgs const& e );
		void B2_2_Click( winrt::Windows::Foundation::IInspectable const& sender, winrt::Windows::UI::Xaml::RoutedEventArgs const& e );
		void B2_3_Click( winrt::Windows::Foundation::IInspectable const& sender, winrt::Windows::UI::Xaml::RoutedEventArgs const& e );
		void B3_0_Click( winrt::Windows::Foundation::IInspectable const& sender, winrt::Windows::UI::Xaml::RoutedEventArgs const& e );
		void B3_1_Click( winrt::Windows::Foundation::IInspectable const& sender, winrt::Windows::UI::Xaml::RoutedEventArgs const& e );
		void B3_2_Click( winrt::Windows::Foundation::IInspectable const& sender, winrt::Windows::UI::Xaml::RoutedEventArgs const& e );
		void B3_3_Click( winrt::Windows::Foundation::IInspectable const& sender, winrt::Windows::UI::Xaml::RoutedEventArgs const& e );
		void ResetButton_Click( winrt::Windows::Foundation::IInspectable const& sender, winrt::Windows::UI::Xaml::RoutedEventArgs const& e );
		void ShuffleButton_Click( winrt::Windows::Foundation::IInspectable const& sender, winrt::Windows::UI::Xaml::RoutedEventArgs const& e );
	};
}

namespace winrt::GUIRT::factory_implementation
{
	struct MainPage : MainPageT<MainPage, implementation::MainPage>
	{};
}
