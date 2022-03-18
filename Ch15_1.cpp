//g++ main.cpp Graph.cpp Window.cpp GUI.cpp Simple_window.cpp -o main `fltk-config --ldflags --use-images`
#include "Simple_window.h"
#include "Graph.h"


double one(double x) {return 1;}
double slope(double x) {return x/2;}
double square(double x) {return x*x;}
double sloping_cos(double x) {return cos(x)+slope(x);}



int main(){
	Simple_window win (Point(100,100),600,600,"Function graphs");
	Axis x (Axis::x, Point(100,300) , 400, 20, "x axis");
    Axis y (Axis::y, Point(300,500), 400, 20, "y axis");
    x.set_color(Color::red);
    y.set_color(Color::red);

    win.attach(x);
    win.attach(y);

    //---------------------------------------------------------------
    
    Point origo (300,300);
    double x_scale = 20;
    double y_scale = 20;
    int points = 400;
    double r_min = -10, r_max = 11;

    Function f1{one, r_min, r_max, origo, points,x_scale,y_scale};

    Function f2{slope, r_min, r_max, origo, points,x_scale,y_scale};
    Text t(Point(110,410),"x/2");

    Function f3{square, r_min, r_max, origo, points,x_scale,y_scale};

    Function f4{cos, r_min, r_max, origo, points,x_scale,y_scale};
    f4.set_color(Color::blue);

    Function f5{sloping_cos, r_min, r_max, origo, points,x_scale,y_scale};
    f5.set_color(Color::blue);

    win.attach(f1);
    win.attach(f2);
    win.attach(t);
    win.attach(f3);
    win.attach(f4);
    win.attach(f5);


    win.wait_for_button();
	return 0;
}