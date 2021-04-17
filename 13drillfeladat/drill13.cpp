//g++ drill13.cpp Graph.cpp Window.cpp GUI.cpp Simple_window.cpp -o drill13 `fltk-config --ldflags --use-images`

#include "Simple_window.h"
#include "Graph.h"

int main()

{

	constexpr int x_max = 1000;
	constexpr int y_max = 800;

	Point p1{ 100, 100 };
	Simple_window win{ p1, x_max, y_max, "drill13" };

	constexpr int grid_size = 100;
	constexpr int grid_max = 800;


	Lines grid;
	for (int i = grid_size; i < grid_max; i+= grid_size) 
	{
		grid.add(Point{ i, 0 }, Point{ i, grid_max });
		grid.add(Point{ 0, i }, Point{ grid_max, i });

	}

	win.attach(grid);


	Vector_ref<Rectangle> v;

	for (int i = 0; i < 8; i++) 
	{
		v.push_back(new Rectangle{ Point{ i*grid_size, i*grid_size }, grid_size, grid_size });
		v[i].set_fill_color( Color::red );
		win.attach(v[i]);
	}

		
	Vector_ref<Image> img;

	img.push_back(new Image{ Point{0, 200 }, "flower.jpg" });
	img.push_back(new Image{ Point{0, 400 }, "flower.jpg" });
	img.push_back(new Image{ Point{400, 600 }, "flower.jpg" });

	constexpr int image_size = 200;
	
	
	for (int i = 0; i < img.size(); i++)
		{
		img[i].set_mask(Point{100,100}, image_size, image_size);
		win.attach(img[i]);
	}

	Image dog(Point{0,0}, "dog.jpg");

	win.attach(dog);

	for (int i = 0; i < 8; i++)
		for (int j = 0; j < 8; j++)
	{
		win.wait_for_button();

		if (j < 7) 
			dog.move(100,0);
		else
			dog.move(-700,100);
	}

	
	win.wait_for_button();

}