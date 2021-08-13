#include <iostream>
#include <cstring>

using namespace std;

static int t[102][1002];

bool subset_sum(int arr[],int n,int sum){
    //base cases
    if(sum==0 && n==0){
        return 1;
    }
    else if(sum==0){
        return 1;
    }
    else if(n==0){
        return 0;
    }
    //dp
    if (t[n][sum]!=-1)
    {
        return t[n][sum];
    }
    //recursion
    if(arr[n-1]<=sum){
        return t[n][sum] = subset_sum(arr,n-1,sum-arr[n-1]) || subset_sum(arr,n-1,sum);
    }
    else{
        return t[n][sum] = subset_sum(arr,n-1,sum);
    }
}

int main(){
    int n,sum;
    cin>>n>>sum;
    int arr[n];

    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }

    memset(t,-1,sizeof(t));

    cout<<subset_sum(arr,n,sum)<<endl;
    

    return 0;
}