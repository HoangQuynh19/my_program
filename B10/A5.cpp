#include<iostream>
using namespace std;

struct test
{
    double x;
};
struct Test
{
    test a;
    int arr[1];

};
int main()
{
    test m;
    Test T;

    int Arr[1];
    m=T.a;
  //  Arr=T.arr;

    cout<<&m<<" "<<&(T.a)<<endl;
   // cout<<&Arr<<" "<<&(T.arr)<<endl;
    return 0;
}


