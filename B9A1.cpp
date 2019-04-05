#include<iostream>
#include<string.h>
using namespace std;
char* concat(const char*s, const char*ss)
{
    int n=strlen(s)+strlen(ss);
    char *p = new char[n];
    strcpy(p, s);
    strcat(p, ss);
    return p;
}
int main()
{
    const char*s="Hello";
    const char*ss="World";
    cout<<concat(s,ss);

}
