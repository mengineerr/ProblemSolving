#include <iostream>

class Point{
    int x,y;

    public:
        Point(){
            x = rand()%100;
            y = rand()%100;
        }
        int GetX(){
            return x;
        }
        int GetY(){
            return y;
        }
        void AssignX(int x_){
            x = x_;
        }
        void AssignY(int y_){
            y = y_;
        }
};



class Geometry {
    Point* point_array[100];
    int idx = 0;

    public:
        Geometry(Point **point_list);
        Geometry();

        void AddPoint(const Point &point);
        void PrintDistance();
        void PrintNumMeets();
};

Geometry::Geometry(){}

Geometry::Geometry(Point **point_list){
    *point_array = *point_list;
}

void Geometry::AddPoint(const Point &point){
    point_array[idx] = new Point(point);
    idx++;
}

void Geometry::PrintDistance(){

}

void Geometry::PrintNumMeets(){

}


int main()
{
    srand(time(NULL));
    Geometry geometry;
    Point point1;
    Point point2;
    Point point3;

    std::cout << point1.GetX() << point1.GetY() << std::endl;
    std::cout << point2.GetX() << point2.GetY() << std::endl;
    std::cout << point3.GetX() << point3.GetY() << std::endl;

    geometry.AddPoint(point1);


    //geometry.AddPoint(point1);

    return 0;
}