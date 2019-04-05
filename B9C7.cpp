#include <iostream>
#include <cstring>
using namespace std;
char* trim_left(const char* a)
{
    int n=strlen(a);

    int k=0;
    while (a[k]==' ')
    {
        k++;
    }
    char *p = new char[n-k];
    for (int i=k; i<n; i++)
            p[i-k]=a[i];
    return p;
}
int main()
{
    cout<<trim_left("   avbaf   agreg");
}
