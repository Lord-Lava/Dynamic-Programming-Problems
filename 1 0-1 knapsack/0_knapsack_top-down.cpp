#include <iostream>
#include <cstring>

using namespace std;

int t[102][1002];    //dp table-> size as per the constraints 

int knapsack(int wt[],int val[],int w,int n){
    if(n==0 || w==0){ //base case
        return 0;
    }

    if(t[n][w]!=-1) return t[n][w];

    if(wt[n-1]<=w){
        return t[n][w] =  max(val[n-1] + knapsack(wt,val,w-wt[n-1],n-1),knapsack(wt,val,w,n-1));
    }
    return t[n][w] = knapsack(wt,val,w,n-1);
}

int main(){
    int n;
    cin>>n;

    int w;
    cin>>w;

    int wt[n],val[n];

    for (int i = 0; i < n; i++)
    {
        cin>>wt[i];
    }

    for (int i = 0; i < n; i++)
    {
        cin>>val[i];
    }

    memset(t,-1,sizeof(t)); //initializing the dp table by -1

    cout<<knapsack(wt,val,w,n)<<endl;
    

    return 0;
}