#include<iostream>
#include<algorithm>
#include<vector>
#include<stack>
using namespace std;
vector<int> getLeft(vector<int> &ar ,int n){
   vector <int> res(n);
   stack<int > st;
   for (int  i = 0; i < n; i++)
   {
     if(st.empty())
     res[i] = -1;
     else{
        while(!st.empty() && ar[st.top()] > ar[i]){
            st.pop();
        }
        if(st.empty()) res[i] = -1;
        else res[i] = st.top();
     }
     st.push(i);
   }  
   return res;
}
vector<int> getright(vector<int> &ar ,int n){
   vector <int> res(n);
   stack<int > st;

   for (int  i = 0; i < n; i++)
   {
     if(st.empty())
     res[i] = n;
     else{
        while(!st.empty() && ar[st.top()] >= ar[i]){
            st.pop();
        }
        if(st.empty()) res[i] = n;
        else res[i] = st.top();
     }
     st.push(i);
   }  
   return res;
}
int main()
{
    int t;
    cin>>t;
    vector<int> ar(t);
    for (int i = 0; i < t; i++)
    {
        cin>> ar [i];
    }
    vector<int>left = getLeft(ar,t);
    vector<int>right = getright(ar,t);
    long long sum = 0;
    for (int i = 0; i < t; i++)
    {
        long long lf = i-left[i];// how much index in left of any element
        long long rl =right[i] - i;//how much index in right of any element   
        long long total = lf*rl;
        long long total_sum = total*ar[i];
        sum +=total_sum;
    }
    cout<< sum <<endl;
    
}