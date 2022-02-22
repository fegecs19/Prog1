//g++ main.cpp Graph.cpp Window.cpp GUI.cpp Simple_window.cpp -o main `fltk-config --ldflags --use-images`

#include "Simple_window.h"
#include "Graph.h"

int main()
try{
	using namespace Graph_lib;

    Simple_window win {Point{100,100}, 600, 400, "My window"};

    Axis x (Axis::x, Point(20,300) , 280, 20, "x axis");
    Axis y (Axis::y, Point(20,300), 280, 20, "y axis");
    x.set_color(Color::red);
    y.set_color(Color::green);

	Function sine(sin, 0, 100,Point(20, 150), 1000 ,25,50);

	Rectangle r(Point(300,150),50,50);
	r.set_fill_color(Color::blue);
	Closed_polyline poly_rect;
	poly_rect.add(Point(200,50));
	poly_rect.add(Point(230,75));
	poly_rect.add(Point(200,100));
	poly_rect.add(Point(100,100));
	poly_rect.add(Point(100,50));


	r.set_fill_color(Color::black);
	poly_rect.set_style(Line_style(Line_style::dot,4));
	
	Text t(Point(150, 100), "Hello, graphical world");
	t. set_font(Font::times_bold);
	t.set_font_size(15);

	Image ii {Point{350,200}, "c++.jpeg"};


	Circle c(Point(100,250),75);
	Ellipse e(Point(100,250), 100,50);
	e.set_color(Color::dark_red);
	Mark m(Point(100,250), 'x');

	win.attach(e);
	win.attach(ii);
	win.attach(c);
	win.attach(sine);
	win.attach(t);
	win.attach(r);
	win.attach(x);
	win.attach(y);
	win.attach(poly_rect);
	win.attach(m);

    win.wait_for_button();
}
catch(exception& e){
	cout << "Something went wrong!"<< endl;
	return 1;
}