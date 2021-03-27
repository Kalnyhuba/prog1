#include "Simple_window.h"
#include "Graph.h"

int main()

{

	Point p1{ 100, 100 };
	Simple_window win{ p1, 1000, 800, "drill13" };

	Lines grid;
	for (int i = 0; i < 9; i++) {
		grid.add(Point{ 0 + i*100, 0 }, Point{ 0 + i*100, 800 });
		grid.add(Point{ 0, 0 + i*100 }, Point{ 800, 0 + i*100 });

	}

	Vector_ref<Graph_lib::Rectangle> v;
	for (int i = 0; i < 8; i++) {
		v.push_back(new Graph_lib::Rectangle{ Point{ 0 + i*100, 0 + i*100 }, 100, 100 });
		v[i].set_fill_color( Color::red );
	}

	Image img1(Point( 0, 600 ), "200pixels.jpeg" );
	Image img2(Point( 300, 600 ), "200pixels.jpeg" );
	Image img3(Point( 600, 0 ), "200pixels.jpeg" );

	
	win.attach(grid);

	for (int i = 0; i < v.size(); i++ )
		win.attach(v[i]);
	
	win.attach(img1);
	win.attach(img2);
	win.attach(img3);

	
	win.wait_for_button();

}