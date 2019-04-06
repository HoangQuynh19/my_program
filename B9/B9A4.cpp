#include <iostream>
using namespace std;

int* test()
{
    int n = 0;
    int *p = new int;
    p = &n;
    delete p;
    cout<<&n<<endl;
    return p;
}
int main()
{
    cout<<test();
    return 0;
}
