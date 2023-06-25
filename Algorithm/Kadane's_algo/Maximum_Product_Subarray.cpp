#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
    int t;
    cin>>t;
    int arr[t];
    for (int i = 0; i < t; i++)
    {
        cin>>arr[i];
    }
    int sum = 1;int maxs = arr[0];
    for (int i = 0; i < t; i++)
    {
        sum *= arr[i];
      maxs =   max(maxs,sum);
        if(sum<0) sum = 0;
    }
    cout<<maxs<<endl;
    
}