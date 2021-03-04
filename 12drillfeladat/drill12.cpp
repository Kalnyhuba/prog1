#include "std_lib_facilities.h"
#include "Graph.h"
#include "Simple_window.h"
#include "Window.h"
#include "GUI.h"

double konstans(double) { return 1; }

double sq(double x) { return x*x; }

int main()
{
	using namespace Graph_lib;

	Point tl {100,100};

	int xmax = 600;
	
	int ymax = 400;

	int x_orig = xmax/2;

	int y_orig = ymax/2;

	int rmin = -15;

	int rmax = 15;

	int number_of_points = 200;

	Simple_window win{tl, xmax, ymax, "My window"};

	Point origo{x_orig, y_orig};

	int xlength = xmax - 30;

	int ylength = ymax - 30;

	int xscale = 20, yscale = 20;


	Function  f(konstans, rmin, rmax, origo, number_of_points, xscale, yscale);

	Function  s(sq, rmin, rmax, origo, number_of_points, xscale, yscale);

	Axis x(Axis::x, Point(20, y_orig), xlength, xlength/xscale, "x axis");


	Axis y(Axis::y, Point(x_orig, ylength+20), ylength, ylength/yscale, "y axis");

	

	Polygon p;

	p.add( Point(200, 250) );
	
	p.add(Point(275, 300) );

	p.add(Point(350, 400) );

	p.set_color( Color::green);


	Rectangle r(Point( 100,150 ), 150, 100);

	r.set_fill_color(Color::red);

	r.set_style(Line_style(Line_style::dash, 4));


	Text t(Point(110, 110), "Prog1 12-es drill");

	t.set_font(Font::times_bold);


	t.set_font_size(32);

	

	Image im(Point(400,80), "golden.jpg");


	Circle c(Point(50,50), 50);

	win.attach(c);

	win.attach(im);

	win.attach(t);

	win.attach(r);

	win.attach(p);
	
	win.attach(f);

	win.attach(s);

	win.attach(y);

	win.attach(x);

	win.wait_for_button();

}