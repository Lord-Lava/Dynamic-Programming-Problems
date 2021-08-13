#include <iostream>
#include <cstring>

using namespace std;

int t[1002][102];

int unbounded_knapsack(int weight[],int value[],int n,int w){
    if(n==0 || w == 0){
        return 0;
    }
    if(t[n][w]!=-1) return t[n][w];
    if(weight[n-1]<=w){
        return t[n][w] = max(value[n-1] + unbounded_knapsack(weight,value,n,w-weight[n-1]),unbounded_knapsack(weight,value,n-1,w));
    }
    return t[n][w] = unbounded_knapsack(weight,value,n-1,w);
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

    memset(t,-1,sizeof(t));

    cout<<unbounded_knapsack(weight,value,n,w)<<endl;
    
    return 0;
}