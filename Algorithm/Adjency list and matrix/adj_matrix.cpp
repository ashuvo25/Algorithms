#include<iostream>
using namespace std;

#define n 100

int matrix[n][n];
void init_mat(int a,int b)
{
    matrix[a][b] = 1;
}

void print_mat(int t)
{
    for(int i = 1; i<t+1; i++)
    {
        // cout<< i << " ";
        for(int j =1; j<t+1; j++)
        {
            cout<< matrix[i][j] <<" " ;
        }
        cout<<endl;
    }
}
int main()
{
    int t ;
    cin>>t;
    for(int i = 1; i<t+1; i++)
    {
        for(int j =1;j<t+1;j++){
          int a,b;
        cin>>a>>b;
        init_mat(a,b);
        }
    }
    print_mat(t);
    return 0;
}
