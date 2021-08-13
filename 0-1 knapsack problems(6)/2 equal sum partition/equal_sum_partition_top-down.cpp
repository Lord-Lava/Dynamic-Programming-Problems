#include <iostream>
#include <cstring>

using namespace std;

int t[102][1002];

bool subset_sum(int arr[],int n,int sum){
    if(n==0 && sum==0){
        return 1;
    }
    else if(n==0){
        return 0;
    }
    else if(sum==0){
        return 1;
    }

    if(t[n][sum]!=-1) return t[n][sum];

    if(arr[n-1] <= sum){
        return t[n][sum] = subset_sum(arr,n-1,sum-arr[n-1]) || subset_sum(arr,n-1,sum);
    }
    else{
        return t[n][sum] = subset_sum(arr,n-1,sum);
    }
}

int main(){
    int n;
    cin>>n;

    int arr[n];

    int sum=0;
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
        sum+=arr[i];
    }

    if(sum&1){
        cout<<0<<endl;
    }
    else{
        memset(t,-1,sizeof(t));
        cout<<subset_sum(arr,n,sum/2)<<endl;
    }

    return 0;
}