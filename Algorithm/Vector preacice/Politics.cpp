#include<iostream>
#include<vector>
using namespace std;


int main(){
   int t;cin>>t;
   while(t--){
    vector<string>n;
    int a,b;cin>>a>>b;
    for(int i=0;i<a;i++){
        string s;cin>>s;
        n.push_back(s);
    }
   // string m = n[0];
   int co=1;
    for(int i=1;i<a;i++){
       if(n[0] == n[i]) co++;
    }
    cout<<co<<endl;
   }
return 0;
}
