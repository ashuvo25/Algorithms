
#include<iostream>
using namespace std;

int fibo(int a,int b,int n){
    if(n == 0|| n==1) return a;
    return fibo(b,a+b,n-1);
}
int main(){
int a=0;int b=1;
int n;
cin >>n ;
int v=fibo(a,b,n);
cout<< v <<endl;
return 0;
}
