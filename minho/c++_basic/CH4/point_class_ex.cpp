#include <cmath>
#include <cstdlib>
#include <ctime>
#include <iostream>
//#include <conio.h>

using namespace std;

class Point{

    int x, y;

   public:
    Point() : x(rand()%100), y(rand()%100) {}
    Point(int x, int y) : x(x), y(y) {}
    Point(Point& point): x(point.x), y(point.y) {}
    int get_x(){ return x; }
    int get_y(){ return y; }
    void set_x(int _x) { x = _x; }
    void set_y(int _y) { y = _y; }
};

class Geometry{

    Point **point_list;
    unsigned int point_number;

   public:
    Geometry();
    Geometry(Point **_point_list, unsigned int _point_number);
    ~Geometry();
    void add_point(Point& point);
    void show_distance();
    void show_intersection();
    void show_point();

};

int main()
{

    srand(time(NULL));

    //Method 1
    cout << "<< [1] Generate null geometry and add points >>" << endl;
    cout << "Press a key to start..." << endl;
    //getch();

    Geometry geometry1;
    Point p1, p2, p3;
    geometry1.add_point(p1);
    geometry1.add_point(p2);
    geometry1.add_point(p3);

    cout << endl << "<< Points >>" << endl;
    geometry1.show_point();

    cout << endl << "<< Distances >>" << endl;
    geometry1.show_distance();

    cout << endl << "<< Intersections >>" << endl;
    geometry1.show_intersection();

    cout << endl << endl;

    //Method 2
    cout << "<< [2] Generate geometry with point list >>" << endl;
    cout << "Press a key to start..." << endl;
    //getch();

    Point **point_list;
    unsigned int point_number = 5;

    point_list = new Point*[point_number];
    for(unsigned int i = 0; i < point_number; i++){
        point_list[i] = new Point();
    }

    Geometry geometry2(point_list, point_number);

    for(unsigned int i = 0; i < point_number; i++){
        delete point_list[i];
    }
    delete[] point_list;

    cout << endl << "<< Points  >>" << endl;
    geometry2.show_point();

    cout << endl << "<< Distances  >>" << endl;
    geometry2.show_distance();

    cout << endl << "<< Intersections >>" << endl;
    geometry2.show_intersection();


    return 0;
}

Geometry::Geometry() : point_number(0) {}

//constructor using deep copy
Geometry::Geometry(Point **_point_list, unsigned int _point_number) : point_number(_point_number) {

    point_list = new Point*[point_number];
    for(unsigned int i = 1; i < point_number; i++){
        point_list[i] = new Point(*_point_list[i]);
    }

}

Geometry::~Geometry() {

    for(unsigned int i = 0; i < point_number; i++){
        delete point_list[i];
    }

    delete point_list;
}

void Geometry::add_point(Point& point){

    if(point_number > 0) {
        Point** point_list_tmp = point_list;
        point_list = new Point*[point_number + 1];
        for(unsigned int i = 0; i < point_number; i++){
            point_list[i] = new Point(*point_list_tmp[i]);
            delete point_list_tmp[i];
        }
        delete point_list_tmp;
    }
    else{
        point_list = new Point*[point_number + 1];
    }

    point_list[point_number] = new Point(point);
    point_number++;

}

void Geometry::show_distance(){

    for(unsigned int i = 0; i < point_number - 1; i++){
        for(unsigned int j = i + 1; j < point_number; j++){
            cout << "|(" << (*point_list[i]).get_x() << ", " << (*point_list[i]).get_y() << ") - ("
                         << (*point_list[j]).get_x() << ", " << (*point_list[j]).get_y() << ")| = "
                 << sqrt(pow((*point_list[i]).get_x() - (*point_list[j]).get_x(), 2)
                       + pow((*point_list[i]).get_y() - (*point_list[j]).get_y(), 2)) << endl;
        }
    }
}

void Geometry::show_intersection(){

    double a, b, c; //f(x, y) = a*x + b*y + c
    double product;
    const double epsilon = 1E-12;
    unsigned int intersection = 0;

    //find f(x, y) passing two points
    for(unsigned int i = 0; i < point_number - 1; i++){
        for(unsigned int j = i + 1; j < point_number; j++){

            if((*point_list[i]).get_y() == (*point_list[j]).get_y()){
                a = (double)0;
                b = (double)1;
                c = (double)-(*point_list[i]).get_y();
            }
            else{
                a = (double)1;
                b = (double)-((*point_list[i]).get_x() - (*point_list[j]).get_x())
                            /((*point_list[i]).get_y() - (*point_list[j]).get_y());
                c = (double) ((*point_list[i]).get_x() * (*point_list[j]).get_y()
                            - (*point_list[i]).get_y() * (*point_list[j]).get_x())
                            /((*point_list[i]).get_y() - (*point_list[j]).get_y());
            }

            cout << endl << "(P" << i << ", P" << j << ") : f(x, y) = " << a << " x + " << b << " y + " << c << endl;

            //count all intersections to f(x, y) even when overlapped
            for(unsigned int m = i; m < point_number - 1; m++){
                for(unsigned int n  = m + 1; n < point_number; n++){

                    if((m == i) && (n <= j)){}
                    else{

                        if((m == i) || (m == j) || (n == i) || (n == j)) product = (double)0;
                        else{
                            product = (a*(*point_list[m]).get_x() + b*(*point_list[m]).get_y() + c)
                                    * (a*(*point_list[n]).get_x() + b*(*point_list[n]).get_y() + c);
                        }
                        cout << "(P" << i << ", P" << j << ") * (P" << m << ", P" << n << ") = " << product << endl;

                        if(product <= epsilon) intersection++;
                    }

                } //for n
            } //for m

        } //for j
    } //for i

    cout << "There are " << intersection << " intersections, among which "
         << point_number * (point_number - 1) * (point_number - 2) / 2
         << " are overlapped with one of P0 to P" << point_number - 1 << "." << endl
         << "Criterion: product <= " << epsilon << endl;
}

void Geometry::show_point(){

    for(unsigned int i = 0; i < point_number; i++){
        point_list[i] = new Point();
        cout << "p" << i << "(" << (*point_list[i]).get_x() << "," << (*point_list[i]).get_y() << ")" << endl;
    }

}