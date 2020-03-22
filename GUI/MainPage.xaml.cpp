//
// MainPage.xaml.cpp
// Implementation of the MainPage class.
//

#include "pch.h"
#include "MainPage.xaml.h"
#include <chrono>

using namespace GUI;
using namespace std::chrono_literals;

using namespace Windows::UI::Popups;
using namespace Platform;
using namespace Windows::Foundation;
using namespace Windows::UI;
using namespace Windows::Foundation::Collections;
using namespace Windows::UI::Xaml;
using namespace Windows::UI::Xaml::Controls;
using namespace Windows::UI::Xaml::Controls::Primitives;
using namespace Windows::UI::Xaml::Data;
using namespace Windows::UI::Xaml::Input;
using namespace Windows::UI::Xaml::Media;
using namespace Windows::UI::Xaml::Navigation;
using namespace Windows::System::Diagnostics;

using Windows::UI::Popups::MessageDialog;
using Windows::UI::Colors;
using Windows::UI::Color;

#define add(x, y) refs[x][y] = this->B##x##_##y;  this->B##x##_##y##->TabIndex = coord_to_tool_tip({x, y}); buttons[coord_to_tool_tip({x, y})] = {x, y}; color_button_to_default(B##x##_##y);
#define button( x, y ) void GUI::MainPage::B##x##_##y##_Click( Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e ) { add_to_swap(this->B##x##_##y); }

MainPage::MainPage()
{
	InitializeComponent();
	add( 0, 0 ); add( 0, 1 ); add( 0, 2 ); add( 0, 3 ); add( 0, 4 );
	add( 1, 0 ); add( 1, 1 ); add( 1, 2 ); add( 1, 3 ); add( 1, 4 );
	add( 2, 0 ); add( 2, 1 ); add( 2, 2 ); add( 2, 3 ); add( 2, 4 );
	add( 3, 0 ); add( 3, 1 ); add( 3, 2 ); add( 3, 3 ); add( 3, 4 );
	add( 4, 0 ); add( 4, 1 ); add( 4, 2 ); add( 4, 3 ); add( 4, 4 );

	sync();
}

void GUI::MainPage::switch_button( Button^ btn, const bool mod_to )
{
	btn->IsEnabled = mod_to;
}

void GUI::MainPage::sync()
{
	for( pos i = 0; i < SIZE; i++ )
		for( pos j = 0; j < SIZE; j++ )
			sync_single_cell(i, j);
}

void GUI::MainPage::sync_single_cell( const pos row, const pos col )
{
	const num value{ eng[row][col] };
	if( value != 0 ) refs[row][col]->Content = ref new String( std::to_wstring( value ).c_str() );
	else refs[row][col]->Content = L"";
}

void GUI::MainPage::refresh()
{
	if( swap_button != nullptr ) return;
	eng.reset();
	sync();
	switch_all_buttons( true );
}

void GUI::MainPage::shuffle()
{
	eng.shuffle();
	sync();
	switch_all_buttons( true );
}

void GUI::MainPage::msg( const wchar_t* msg ) const
{
	MessageDialog^ dial = ref new MessageDialog( ref new String( msg ) );
	dial->ShowAsync();
}


void GUI::MainPage::add_to_swap( Button^ btn )
{
	if( swap_button == nullptr )
	{
		color_button_as_pending( btn );
		switch_button( btn, false );
		swap_button = btn;
		return;
	}

	end_turn( try_swap( btn ) );
}

void GUI::MainPage::color_button_as_pending( Button^ btn )
{
	btn->Background = ref new SolidColorBrush( Windows::UI::ColorHelper::FromArgb(0, 252, 244, 163));
}

void GUI::MainPage::color_button_to_default( Button^ btn )
{
	btn->Background = ref new SolidColorBrush( Windows::UI::Colors::Transparent );
}

bool GUI::MainPage::try_swap(Button ^ second)
{
	const coord first_cell{ tool_tip_to_coord( swap_button ) };
	const coord second_cell{ tool_tip_to_coord( second ) };

	if( !eng.swap( first_cell, second_cell ) )
	{
		msg( L"Don't know a rules? Invalid movement.\nTry Again!" );
		return false;
	}

	sync_single_cell( first_cell.row, first_cell.col );
	sync_single_cell( second_cell.row, second_cell.col );

	return check_win();
}

bool GUI::MainPage::check_win()
{
	return eng.win();
}

coord GUI::MainPage::tool_tip_to_coord( Button^ btn ) const
{
	return buttons.at( btn->TabIndex );
}

int GUI::MainPage::coord_to_tool_tip( const coord& cell ) const
{
	return (cell.row * SIZE) + cell.col;
}

void GUI::MainPage::switch_all_buttons(const bool switch_to)
{
	for(int i = 0; i < SIZE; i++ )
		for(int j = 0; j < SIZE; j++ )
			switch_button( refs[i][j], switch_to);
}

void GUI::MainPage::end_turn( const bool is_win )
{
	color_button_to_default( swap_button );
	if( !is_win ) switch_button( swap_button, true );
	else switch_all_buttons(false);
	swap_button = nullptr;
}

void GUI::MainPage::BRESET_Click( Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e )
{
	refresh();
}

void GUI::MainPage::BSHUFFLE_Click( Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e )
{
	shuffle();
}

// Setup buttons
button( 0, 0 ) button( 0, 1 ) button( 0, 2 ) button( 0, 3 ) button( 0, 4 )
button( 1, 0 ) button( 1, 1 ) button( 1, 2 ) button( 1, 3 ) button( 1, 4 )
button( 2, 0 ) button( 2, 1 ) button( 2, 2 ) button( 2, 3 ) button( 2, 4 )
button( 3, 0 ) button( 3, 1 ) button( 3, 2 ) button( 3, 3 ) button( 3, 4 )
button( 4, 0 ) button( 4, 1 ) button( 4, 2 ) button( 4, 3 ) button( 4, 4 )
