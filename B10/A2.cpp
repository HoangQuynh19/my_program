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
        cout<<&A<<endl;
}
void Print(Point A)
{
    cout<<&A<<endl;
}
int main()
{

    Point A(1,2);
    cout<<&A<<endl;
    print(A);
    Print(A);
    return 0;
}

