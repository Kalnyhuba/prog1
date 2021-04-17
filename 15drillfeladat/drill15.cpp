//g++ drill15.cpp Graph.cpp Window.cpp GUI.cpp Simple_window.cpp -o drill15 `fltk-config --ldflags --use-images`

#include "Simple_window.h"
#include "Graph.h"


double one (double x) { return 1; }

double slope (double x) { return x/2; }

double square (double x) { return x*x; }

double sloping_cos (double x) { return cos( x/2 ); }


int main()

{
	using namespace Graph_lib;
	Point p1{ 100, 100 };
	Simple_window win{ p1, 600, 600, "drill15/1"};
	const int axis_length = 400;
	const int notch = 20;
	Axis x{ Axis::x, Point{(win.x_max()-axis_length)/2, win.y_max()/2}, axis_length, axis_length/notch, "1 == 20 pixels"};
	Axis y{ Axis::y, Point{win.x_max()/2, win.y_max()- (win.y_max()- axis_length)/2}, axis_length, axis_length/notch, "1 == 20 pixels"};
	
	x.set_color (Color::red);
	y.set_color (Color::red);
	
	Point origo = {300,300};

	const int n = 400;
	const int x_scale = 20;
	const int y_scale = 20;

	Function onefunc{ one, -10, 11, origo, n, x_scale, y_scale };

	Function slopefunc{ slope, -10, 11, origo, n, x_scale, y_scale };

	Text label{ Point{ 100, 380}, "x/2" };

	Function squarefunc{ square, -10, 11, origo, n, x_scale, y_scale };

	Function cosfunc{ cos, -10, 11, origo, n, x_scale, y_scale };

	cosfunc.set_color(Color::blue);

	Function sloping_cosfunc{ sloping_cos, -10, 11, origo, n, x_scale, y_scale };

	win.attach(x);

	win.attach(y);

	win.attach(onefunc);
	
	win.attach(slopefunc);

	win.attach(label);

	win.attach(squarefunc);

	win.attach(cosfunc);

	win.attach(sloping_cosfunc);

	win.wait_for_button();



}