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
int main()
{
    Point A(1,2);
    cout<<&A<<" "<<&(A.x)<<" "<<&(A.y);
    //dia chi truong dau tien cua bien kieu point la dia chi cua bien kieu point
    //dia chi truong tiep theo cua bien kia point la 8 byte doi voi kieu double
    return 0;
}


