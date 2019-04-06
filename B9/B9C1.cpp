#include <iostream>
#include <cstring>
using namespace std;
char* reverses(const char *s)
{
    int n=strlen(s);
    char *p = new char[n];
    for (int i=n-1; i>=0; i--)
        p[i]=s[n-1-i];
    return p;
}
int main()
{
    cout<<reverses("abcdef");
    return 0;
}
