#include <iostream>
#include <cstring>
#include <math.h>

using namespace std;

int t[102][1002];

int count_subset_sum(int arr[],int n,int diff){
    if(n==0 && diff == 0){
        return 1;
    }
    else if(n==0){
        return 0;
    }
    else if(diff==0){
        return 1;
    }
    if(t[n][diff]!=-1){
        return t[n][diff];
    }
    if(arr[n-1]<=diff && arr[n-1]!=0){
        return t[n][diff] = count_subset_sum(arr,n-1,diff-arr[n-1]) + count_subset_sum(arr,n-1,diff);
    }
    return t[n][diff] = count_subset_sum(arr,n-1,diff);
}

int main(){
    int n,sum;
    cin>>n>>sum;

    int arr[n];

    int tot = 0;

    int numberofzeroes = 0;

    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
        if(arr[i] == 0){
            numberofzeroes++;
        }
        tot += arr[i];
    }

    if((tot+sum)&1){
        cout<<0<<endl;
        return 0;
    }

    int diff = (tot+sum)/2;
    
    memset(t,-1,sizeof(t));

    cout<<pow(2,numberofzeroes)*count_subset_sum(arr,n,diff)<<endl;

    return 0;
}