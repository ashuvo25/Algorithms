#include<iostream>
using namespace std;
int ext_gcd( int a,int b,int &x ,int &y){
    if(b == 0){
        x = 1;
        y = 0;
        return a;
    }
  int x1,y1;
  int d = ext_gcd(b,a%b,x1,y1);
     x = y1;
     y = x1 -(a/b)*y1;
     return d;
}
int main()
{
    int a,b;cin>>a>>b;
    int x,y;
    int d = ext_gcd(a,b,x,y);
    cout<< x << " " << y<< " " << d  <<endl;
    return 0;
}
