//
// MainPage.xaml.h
// Declaration of the MainPage class.
//

#pragma once

#include "MainPage.g.h"
#include "../Engine/SwitcherEngine.hpp"

using Windows::UI::Xaml::Controls::Button;

namespace GUI
{
	constexpr size_t SIZE = 5;

	public ref class MainPage sealed
	{
	private:

		std::array<std::array<Button^, SIZE>, SIZE> refs;
		std::map< int, coord > buttons;
		Button^ swap_button = nullptr;
		SwitcherEngine<SIZE> eng;

		void switch_button(Button^ btn, const bool mod_to = false);
		void sync();
		void sync_single_cell( const pos row, const pos col );
		void refresh();
		void shuffle();
		void msg(const wchar_t* msg) const;
		void add_to_swap(Button^ btn);
		void color_button_as_pending(Button^ btn);
		void color_button_to_default(Button^ btn);
		bool try_swap( Button^ second );
		bool check_win();
		coord tool_tip_to_coord(Button^ btn) const;
		int coord_to_tool_tip(const coord& cell) const;
		void switch_all_buttons(const bool switch_to );
		void end_turn(const bool is_win);

	public:
		MainPage();

	private:
		void B0_0_Click( Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e );

		void B0_1_Click( Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e );
		void B0_2_Click( Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e );
		void B0_3_Click( Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e );
		void B0_4_Click( Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e );
		void B1_0_Click( Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e );
		void B1_1_Click( Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e );
		void B1_2_Click( Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e );
		void B1_3_Click( Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e );
		void B1_4_Click( Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e );
		void B2_0_Click( Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e );
		void B2_1_Click( Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e );
		void B2_2_Click( Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e );
		void B2_3_Click( Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e );
		void B2_4_Click( Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e );
		void B3_0_Click( Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e );
		void B3_1_Click( Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e );
		void B3_2_Click( Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e );
		void B3_3_Click( Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e );
		void B3_4_Click( Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e );
		void B4_0_Click( Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e );
		void B4_1_Click( Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e );
		void B4_2_Click( Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e );
		void B4_3_Click( Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e );
		void B4_4_Click( Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e );
		void BRESET_Click( Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e );
		void BSHUFFLE_Click( Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e );
	};
}
