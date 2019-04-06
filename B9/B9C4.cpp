#include <iostream>
#include <cstring>
using namespace std;
char* pad_left(const char* a, int n)
{
    int l=strlen(a);
    char *p = new char[n];
    for (int i=0; i<l; i++)
        p[i]='_';
    for (int i=l; i<n; i++)
        p[i]=a[i-l];
    return p;
}
int main()
{

    cout<<pad_left("adgrhh", 5);
}
