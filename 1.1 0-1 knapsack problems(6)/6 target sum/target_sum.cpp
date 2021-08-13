#include <iostream>
#include <cstring>
#include <math.h>

using namespace std;

int target_sum(int arr[],int n,int diff){
    int t[n+1][diff+1];
    memset(t,-1,sizeof(t));

    for (int i = 0; i < n+1; i++)
    {
        for (int j = 0; j < diff+1; j++)
        {
            if(i==0){
                t[i][j] = 0;
            }
            if(j==0){
                t[i][j] = 1;
            }
        }
    }

    for (int i = 1; i < n+1; i++)
    {
        for (int j = 1; j < diff+1; j++)
        {
            if(arr[i-1]<=j && arr[i-1]!=0){
                t[i][j] = t[i-1][j-arr[i-1]] + t[i-1][j];
            }
            else{
                t[i][j] = t[i-1][j];
            }
        }   
    }
    
    return t[n][diff];
}

int main(){
    int n,sum;
    cin>>n>>sum;

    int arr[n];

    int tot = 0;
    int zeroes = 0;

    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
        if(arr[i]==0){
            zeroes++;
        }
        tot+=arr[i];
    }

    if((tot + sum)&1){
        cout<<0<<endl;
        return 0;
    }

    int diff = (tot+sum)/2;

    cout<<pow(2,zeroes)*target_sum(arr,n,diff)<<endl;

    return 0;
}