#include <iostream>
#include <cstring>

using namespace std;

struct String
{
    int n;
    char* p = new char[n];
   String(const char* a)
   {
        n = strlen(a);
        for (int i = 0; i < n ; i++) {
            *(p+ i) = a[i];
        }
   }

   void print_str() {

         cout << p ;

   }

   void append(const char* s)
   {    int m=strlen(s)+n;
        int j=0;
        char* temp= new char[m];
        for (int i = 0; i < n ; i++) {
            *(temp+ i) = p[i];
        }
        for (int i = n; i < m ; i++) {

            *(temp+ i) = s[j];
            j++;
        }
        p=temp;
        cout<<temp;
        delete [] temp;
   }

   void destruct()
   {
        delete [] p;
   }

};

int main()
{
    String s("hello");
    s.print_str();

    s.append(" world");
    s.print_str();
    return 0;
}
