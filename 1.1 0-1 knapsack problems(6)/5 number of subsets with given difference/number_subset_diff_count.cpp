#include <iostream>
#include <cstring>

using namespace std;

int count_of_subset_sum(int arr[],int sum,int n){
    int t[n+1][sum+1];
    memset(t,-1,sizeof(t));

    for (int i = 0; i < n+1; i++)
    {
        for (int j = 0; j < sum+1; j++)
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
        for (int j = 1; j < sum+1; j++)
        {
            if(arr[i-1]<=j){
                t[i][j] = t[i-1][j-arr[i-1]] + t[i-1][j];
            }
            else{
                t[i][j] = t[i-1][j];
            }
        }
    }
    
    return t[n][sum];
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

    if((tot + diff)&1){
        cout<<0<<endl;
        return 0;
    }

    int sum = (tot+diff)/2;

    cout<<count_of_subset_sum(arr,sum,n)<<endl;    

    return 0;
}