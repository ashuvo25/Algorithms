#include<iostream>
using namespace std;

int gcd(int a,int b){
 if (a%b == 0) return b;
  return gcd(b,a%b);
}
int lcm (int a,int b){
  return a*b /gcd(a,b);
}
int main()
{
int a,b;cin>>a>>b;
int x = gcd(a,b);
cout<< x <<endl;
int y = lcm(a,b);
cout<< y <<endl;
main();
return 0;
}
