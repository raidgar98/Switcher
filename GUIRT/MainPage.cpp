#include "pch.h"
#include "MainPage.h"
#include "MainPage.g.cpp"

#include <winrt/Windows.UI.Popups.h>
#include <winrt/Windows.UI.Xaml.Media.h>

using namespace winrt;
using namespace Windows::UI::Xaml;
using namespace Windows::UI::Popups;
using namespace Windows::UI::Xaml::Media;



#define button( x, y ) \
void winrt::GUIRT::implementation::MainPage::B##x##_##y##_Click( winrt::Windows::Foundation::IInspectable const& , winrt::Windows::UI::Xaml::RoutedEventArgs const& ) \
{ \
	add_to_swap( B##x##_##y##() ); \
}

namespace winrt::GUIRT::implementation
{
    MainPage::MainPage()
    {
        InitializeComponent();
		sync();
    }

    int32_t MainPage::MyProperty()
    {
        throw hresult_not_implemented();
    }

    void MainPage::MyProperty(int32_t /* value */)
    {
        throw hresult_not_implemented();
    }

    void MainPage::ClickHandler(IInspectable const&, RoutedEventArgs const&)
    {
        //myButton().Content(box_value(L"Clicked"));
    }

 }


void winrt::GUIRT::implementation::MainPage::switch_button( Button btn, const bool mod_to )
{
	btn.IsEnabled( mod_to );
}

void winrt::GUIRT::implementation::MainPage::sync()
{
	for( pos i = 0; i < BOARD_SIZE; i++ )
		for( pos j = 0; j < BOARD_SIZE; j++ )
			sync_single_cell( i, j );
}

void winrt::GUIRT::implementation::MainPage::sync_single_cell( const pos row, const pos col )
{
	const num value{ eng[row][col] };
	if( value != 0 ) set_content( get_button(row, col), std::to_wstring(value) );
	else set_content( get_button( row, col ), L"" );
}

void winrt::GUIRT::implementation::MainPage::set_content( Button btn, const wchar_t* msg )
{
	btn.Content( winrt::box_value( msg ) );
}

void winrt::GUIRT::implementation::MainPage::set_content( Button btn, const std::wstring& msg )
{
	set_content(btn, msg.c_str());
}

Button winrt::GUIRT::implementation::MainPage::get_button( const pos _x, const pos _y ) 
{
	return get_button({_x, _y});
}

Button winrt::GUIRT::implementation::MainPage::get_button( const coord& posx ) 
{
	add( 0, 0 );
	add( 0, 1 ); 
	add( 0, 2 ); 
	add( 0, 3 );
	add( 1, 0 ); 
	add( 1, 1 ); 
	add( 1, 2 ); 
	add( 1, 3 );
	add( 2, 0 ); 
	add( 2, 1 ); 
	add( 2, 2 ); 
	add( 2, 3 );
	add( 3, 0 ); 
	add( 3, 1 ); 
	add( 3, 2 ); 
	add( 3, 3 );

#if BOARD_SIZE == 5

	add( 0, 4 ); add( 1, 4 ); add( 2, 4 ); add( 3, 4 );
	add( 4, 0 ); add( 4, 1 ); add( 4, 2 ); add( 4, 3 ); add( 4, 4 );

#endif
}

void winrt::GUIRT::implementation::MainPage::refresh()
{
	//if( swap_button != coord{-1, -1} ) return;
	if( is_swap_button_setted ) return;
	eng.reset();
	sync();
	switch_all_buttons( true );
}

void winrt::GUIRT::implementation::MainPage::shuffle()
{
	if( is_swap_button_setted ) return;
	eng.shuffle();
	sync();
	switch_all_buttons( true );
}

void winrt::GUIRT::implementation::MainPage::msg( const wchar_t* msg ) const
{
	MessageDialog dial( msg );
	dial.ShowAsync();
}

void winrt::GUIRT::implementation::MainPage::add_to_swap( Button btn )
{
	if( !is_swap_button_setted )
	{
		color_button_as_pending( btn );
		switch_button( btn, false );
		is_swap_button_setted = true;
		swap_button = btn;
		return;
	}

	end_turn( try_swap( btn ) );
}

void winrt::GUIRT::implementation::MainPage::color_button_as_pending( Button btn )
{
	winrt::Windows::UI::Color clr;
	clr.A = 0;
	clr.R = 252;
	clr.G = 244;
	clr.B = 163;
	btn.Background( SolidColorBrush( clr ) );
}

void winrt::GUIRT::implementation::MainPage::color_button_to_default( Button btn )
{
	winrt::Windows::UI::Color clr;
	clr.A = 255;
	clr.R = 255;
	clr.G = 255;
	clr.B = 255;
	btn.Background( SolidColorBrush( clr ) );
}

bool winrt::GUIRT::implementation::MainPage::try_swap( Button second )
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

bool winrt::GUIRT::implementation::MainPage::check_win()
{
	return eng.win();
}

coord winrt::GUIRT::implementation::MainPage::tool_tip_to_coord( const Button btn )
{
	return buttons.at( btn.TabIndex() );
}

int winrt::GUIRT::implementation::MainPage::coord_to_tool_tip( const coord& cell )
{
	return ( cell.row * BOARD_SIZE ) + cell.col;
}

void winrt::GUIRT::implementation::MainPage::switch_all_buttons( const bool switch_to )
{
	for( int i = 0; i < BOARD_SIZE; i++ )
		for( int j = 0; j < BOARD_SIZE; j++ )
			switch_button( get_button( i, j ), switch_to );
}

void winrt::GUIRT::implementation::MainPage::end_turn( const bool is_win )
{
	color_button_to_default( swap_button );
	if( !is_win ) switch_button( swap_button , true );
	else switch_all_buttons( false );
	is_swap_button_setted = false;
}

// Setup buttons

void winrt::GUIRT::implementation::MainPage::ResetButton_Click( winrt::Windows::Foundation::IInspectable const& sender, winrt::Windows::UI::Xaml::RoutedEventArgs const& e )
{
	refresh();
}

void winrt::GUIRT::implementation::MainPage::ShuffleButton_Click( winrt::Windows::Foundation::IInspectable const& sender, winrt::Windows::UI::Xaml::RoutedEventArgs const& e )
{
	shuffle();
}

button( 0, 0 ) button( 0, 1 ) button( 0, 2 ) button( 0, 3 )
button( 1, 0 ) button( 1, 1 ) button( 1, 2 ) button( 1, 3 )
button( 2, 0 ) button( 2, 1 ) button( 2, 2 ) button( 2, 3 )
button( 3, 0 ) button( 3, 1 ) button( 3, 2 ) button( 3, 3 )

#if BOARD_SIZE == 5

button( 0, 4 ) button( 1, 4 ) button( 2, 4 ) button( 3, 4 )
button( 4, 0 ) button( 4, 1 ) button( 4, 2 ) button( 4, 3 ) button( 4, 4 )

#endif

