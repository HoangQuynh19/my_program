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
void print(Point& A){
        cout << "("<<A.x << "," << A.y <<")"<< endl;
}
int main()
{
    Point A(1,2);
    print(A);
    return 0;
}

