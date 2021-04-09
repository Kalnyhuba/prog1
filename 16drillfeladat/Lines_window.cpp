#include "Lines_window.h"

Lines_window::Lines_window(Point xy, int width, int height, const string& drill16)
: Window{xy, width, height, drill16},
next_button{Point{x_max()-300,0}, 150, 40, "Next point", [](Address, Address pw) {reference_to<Lines_window>(pw).next(); }},

quit_button{Point{x_max()-150,0}, 150, 40, "Quit window", [](Address, Address pw) {reference_to<Lines_window>(pw).quit(); }},

next_x_coord{Point{300,0}, 50, 40, "Next x:"},
next_y_coord{Point{450,0}, 50, 40, "Next y:"},

xy_out{Point{100,0}, 100, 40, "Current x,y:"},

color_menu{Point{x_max()-200,80}, 200, 40, Menu::vertical, "Colors"},

line_menu{Point{x_max()-200, 350}, 200, 40, Menu::vertical, "Linestyles"}



{
	attach(next_button);
	attach(quit_button);
	attach(next_x_coord);
	attach(next_y_coord);
	attach(xy_out);
	attach(opline);

	color_menu.attach(new Button {Point(0,0), 0, 0, "Red", cb_red});
	color_menu.attach(new Button {Point(0,0), 0, 0, "Yellow", cb_yellow});
	color_menu.attach(new Button {Point(0,0), 0, 0, "Blue", cb_blue});
	color_menu.attach(new Button {Point(0,0), 0, 0, "Green", cb_green});
	color_menu.attach(new Button {Point(0,0), 0, 0, "Magenta", cb_magenta});
	color_menu.attach(new Button {Point(0,0), 0, 0, "Cyan", cb_cyan});
	attach(color_menu);

	line_menu.attach(new Button {Point(0,0), 0, 0, "Solid", cb_solid});
	line_menu.attach(new Button {Point(0,0), 0, 0, "Dash", cb_dash});
	line_menu.attach(new Button {Point(0,0), 0, 0, "Dot", cb_dot});
	attach(line_menu);
}

void Lines_window::quit() 
{
	hide();
}

void Lines_window::next()
{
	int x = next_x_coord.get_int();
	int y = next_y_coord.get_int();

	opline.add(Point{x,y});

	ostringstream ss;
	ss << '(' << x << ',' << y << ')';
	xy_out.put(ss.str());

	redraw();
}

void Lines_window::change_color(Color c)
{
	opline.set_color(c);
	redraw();
}

void Lines_window::change_style(Line_style ls)
{
	opline.set_style(ls);
	redraw();
}