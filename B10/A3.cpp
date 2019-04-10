#include<iostream>
using namespace std;

struct Point
{
    double x;
    double y;
    Point (double _x, double _y){
        x = _x;
        y = _y;
    }
};
Point mid_Point(const Point& A, const Point& B)
{
     Point C(1,1);
    C.x=(A.x+B.x)/2;
    C.y=(A.y+B.y)/2;
    return C;
}
void print(Point& A){
    cout << "("<<A.x << "," << A.y <<")"<< endl;
}
int main()
{
    Point A(1,2);
    Point B(4,4);
    Point C(0,0);
    C= mid_Point(A,B);
    print(C);
    return 0;
}


