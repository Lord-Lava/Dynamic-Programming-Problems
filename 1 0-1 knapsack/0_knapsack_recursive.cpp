#include <iostream>

using namespace std;

int knapsack(int wt[],int val[],int w,int n){
    if(w==0 || n==0){ //base case
        return 0;
    }
    //recursion based on choice diagram
    if(wt[n-1]<=w){
        return max(val[n-1] + knapsack(wt,val,w-wt[n-1],n-1),knapsack(wt,val,w,n-1));
    }
    //else if(wt[n-1]>w)
    return knapsack(wt,val,w,n-1);
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

    cout<<knapsack(wt,val,w,n)<<endl;
    

    return 0;
}