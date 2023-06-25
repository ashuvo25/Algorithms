#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int main(){

  while(true){
     string s;
     cin>>s;
     if(s == " '\0' ") return false;
     transform(s.begin(),s.end(),s.begin(),::toupper);
     cout<< s <<endl;
  }
return 0;
}
