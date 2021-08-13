#include <iostream>
#include <cstring>

using namespace std;

int t[102][1002];

int subset_sum_count(int arr[],int n,int sum){
    if(n==0 && sum==0) return 1;
    else if(n==0) return 0;
    else if(sum == 0) return 1;

    if(t[n][sum]!=-1) return t[n][sum];

    if(arr[n-1]<=sum){
        return t[n][sum] = subset_sum_count(arr,n-1,sum-arr[n-1]) + subset_sum_count(arr,n-1,sum);
    }
    
    return t[n][sum] = subset_sum_count(arr,n-1,sum);
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

    cout<<subset_sum_count(arr,n,sum)<<endl;

    return 0;
}