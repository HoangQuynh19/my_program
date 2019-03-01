#include<iostream>

using namespace std;

int main(){
    int n;
    int a[10];
    char b[10];
    char m;
    for (int i=0;i<3;++i)
        cout<<&a[i]<<" "; // các ô nhớ liên tiếp nhau cách nhau 4 byte
    cout<<endl;
    for (int i=0;i<3;++i)
        cout<<(void*)&b[i]<<" ";    // các ô nhớ liên tiếp nhau cách nhau 1 byte
    cout<<endl;
    cout<<&n<<" "<<(void*)&m;   // ô nhớ của kí tự int được lưu sau ô nhớ của 2 mảng, ô nhớ kí tự của char được lưu trước ô nhớ của mảng char
    return 0;
}
