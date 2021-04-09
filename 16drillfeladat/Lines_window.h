#include "GUI.h"

using namespace Graph_lib;

struct Lines_window : Graph_lib::Window {
	Lines_window(Point xy, int width, int height, const string& drill16);
	Open_polyline opline;
	bool wait_for_button();

private:
	Button next_button;
	Button quit_button;
	Menu color_menu;
	Menu line_menu;

	In_box next_x_coord;
	In_box next_y_coord;

	Out_box xy_out;

	void next();
	void quit();
	void change_color(Color c);
	void change_style(Line_style ls);

	void change_red() {change_color(Color::red);}
	static void cb_red(Address, Address pw) {reference_to<Lines_window>(pw).change_red(); }

	void change_yellow() {change_color(Color::yellow);}
	static void cb_yellow(Address, Address pw) {reference_to<Lines_window>(pw).change_yellow(); }

	void change_blue() {change_color(Color::blue);}
	static void cb_blue(Address, Address pw) {reference_to<Lines_window>(pw).change_blue(); }

	void change_green() {change_color(Color::green);}
	static void cb_green(Address, Address pw) {reference_to<Lines_window>(pw).change_green(); }

	void change_magenta() {change_color(Color::magenta);}
	static void cb_magenta(Address, Address pw) {reference_to<Lines_window>(pw).change_magenta(); }

	void change_cyan() {change_color(Color::cyan);}
	static void cb_cyan(Address, Address pw) {reference_to<Lines_window>(pw).change_cyan(); }


	void change_solid() {change_style(Line_style::solid);}
	static void cb_solid(Address, Address pw) {reference_to<Lines_window>(pw).change_solid(); }

	void change_dash() {change_style(Line_style::dash);}
	static void cb_dash(Address, Address pw) {reference_to<Lines_window>(pw).change_dash(); }

	void change_dot() {change_style(Line_style::dot);}
	static void cb_dot(Address, Address pw) {reference_to<Lines_window>(pw).change_dot(); }


};