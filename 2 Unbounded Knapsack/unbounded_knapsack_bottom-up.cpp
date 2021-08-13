#include <iostream>
#include <cstring>

using namespace std;

int unbounded_knapsack(int wt[],int val[],int n,int w){
    int t[n+1][w+1];
    memset(t,-1,sizeof(t));

    for (int i = 0; i < n+1; i++)
    {
        for (int j = 0; j < w+1; j++)
        {
            if(i==0 || j==0){
                t[i][j] = 0;
            }
        }
    }

    for (int i = 1; i < n+1; i++)
    {
        for (int j = 1; j < w+1; j++)
        {
            if(wt[i-1]<=j){
                t[i][j] = max(val[i-1] + t[i][j-wt[i-1]] , t[i-1][j]); 
            }
            else{
                t[i][j] = t[i-1][j];
            }
        }
    }
    return t[n][w];
}

int main(){
    int n,w; 
    cin>>n>>w;
    int weight[n];
    int value[n];

    for (int i = 0; i < n; i++)
    {
        cin>>value[i];
    }

    for (int i = 0; i < n; i++)
    {
        cin>>weight[i];
    }

    cout<<unbounded_knapsack(weight,value,n,w)<<endl;

    return 0;
}