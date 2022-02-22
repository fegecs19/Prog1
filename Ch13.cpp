//g++ Ch13.cpp Graph.cpp Window.cpp GUI.cpp Simple_window.cpp -o main `fltk-config --ldflags --use-images`

#include "Simple_window.h"
#include "Graph.h"



int main(){
	using namespace Graph_lib;
	Simple_window win {Point{100,100}, 800, 1000, "Simple_window"};

	int width = 100;
	int height = 100;
	Lines grid;
	for(int i=width;i<=800;i+=width)
		grid.add(Point(i,0), Point(i,800));
	for(int i=height;i<=800;i+=height)
		grid.add(Point(0,i), Point(800,i));
	

	Vector_ref<Rectangle> c;
	for(int i=0;i<8;i++){
		c.push_back(new Rectangle(Point(i*width,i*height),100,100));
		c[c.size()-1].set_fill_color(Color::red);
		win.attach(c[c.size()-1]);
	}

	Image pepe(Point(0,200),"pepe_2.gif");
	pepe.set_mask(Point(0,0),200,200);
	Image pepe_2(Point(200,0),"pepe_2.gif");
	pepe.set_mask(Point(0,0),200,200);
	Image pepe_3(Point(400,0),"pepe_2.gif");
	pepe.set_mask(Point(0,0),200,200);



	win.attach(grid);
	win.attach(pepe);
	win.attach(pepe_2);
	win.attach(pepe_3);

	int i, j = 0;
	while(true){
		for(int i=0;i<=700;i+=100)
			for(int j=0;j<=700;j+=100){
				Image pepe_s(Point(j,i),"pepe-s.jpg");
				pepe_s.set_mask(Point(132,125),100,100);
				win.attach(pepe_s);
				win.wait_for_button();
			}
	}
}
