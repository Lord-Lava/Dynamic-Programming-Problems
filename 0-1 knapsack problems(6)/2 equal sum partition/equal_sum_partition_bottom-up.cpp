#include <iostream>
#include <cstring>

using namespace std;

bool subset_sum(int arr[],int n,int sum){
    int t[n+1][sum+1];
    memset(t,-1,sizeof(t));

    for (int i = 0; i < n+1; i++)
    {
        for(int j=0;j<sum+1;j++){
            if(i==0)
                t[i][j] = false;
            if(j==0)
                t[i][j] = true;
        }
    }
    
    for (int i = 1; i < n+1; i++)
    {
        for (int j = 1; j < sum+1; j++)
        {
            if(arr[i-1]<=sum){
                t[i][j] = t[i-1][j-arr[i-1]] || t[i-1][j];
            }
            else{
                t[i][j] = t[i-1][j];
            }
        }
    }
    return t[n][sum];
}

int main(){
    int n;cin>>n;
    int arr[n];

    int sum=0;

    for(int i=0;i<n;i++){
        cin>>arr[i];
        sum+=arr[i];
    } 

    if(sum&1){
        cout<<false<<endl;
    }
    else{
        cout<<subset_sum(arr,n,sum/2);
    }

    return 0;
}