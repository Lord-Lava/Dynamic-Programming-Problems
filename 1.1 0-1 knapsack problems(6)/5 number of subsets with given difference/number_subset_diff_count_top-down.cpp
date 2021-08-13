#include <iostream>
#include <cstring>

using namespace std;

int t[102][1002];

int count_subset_sum(int arr[],int n,int sum){
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

    if(arr[n-1]<=sum){
        return t[n][sum] = count_subset_sum(arr,n-1,sum-arr[n-1]) + count_subset_sum(arr,n-1,sum);
    }
    return t[n][sum] = count_subset_sum(arr,n-1,sum);
}

int main(){
    int n,diff;
    cin>>n>>diff;

    int arr[n];
    int tot = 0;

    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
        tot+=arr[i];
    }

    if((tot+diff)&1){
        cout<<0<<endl;
        return 0;
    }

    int sum = (tot+diff)/2;

    memset(t,-1,sizeof(t));
    
    cout<<count_subset_sum(arr,n,sum)<<endl;

    return 0;
}