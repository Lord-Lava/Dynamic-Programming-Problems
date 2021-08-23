#include <iostream>
#include <cstring>
#include <climits>

using namespace std;

int t[1001][1001];

int MCM(int arr[],int i,int j){
    if(i>=j) return 0;

    if(t[i][j]!=-1) return t[i][j];

    int mn = INT_MAX;

    for(int k=i;k<j;k++){
        int temp = MCM(arr,i,k) + MCM(arr,k+1,j) + arr[i-1]*arr[j]*arr[k];
        mn = min(mn,temp);
    }

    return t[i][j] = mn;
}

int main(){
    int n;
    cin>>n;

    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }

    memset(t,-1,sizeof(t));
    cout<<MCM(arr,1,n-1)<<endl;

    return 0;
}