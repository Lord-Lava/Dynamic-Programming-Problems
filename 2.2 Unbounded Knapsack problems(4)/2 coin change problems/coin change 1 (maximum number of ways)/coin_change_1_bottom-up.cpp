#include <iostream>
#include <cstring>

using namespace std;

int t[1002][1002];

int coin_change_1(int coin[],int n,int sum){
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

    if(coin[n-1]<=sum){
        return t[n][sum] = coin_change_1(coin,n,sum-coin[n-1]) + coin_change_1(coin,n-1,sum);
    }
    else{
        return t[n][sum] = coin_change_1(coin,n-1,sum);
    }

    return t[n][sum];
}

int main(){
    int n,sum;
    cin>>n>>sum;

    int coin[n];

    for (int i = 0; i < n; i++)
    {
        cin>>coin[i];
    }

    memset(t,-1,sizeof(t));

    cout<<coin_change_1(coin,n,sum)<<endl;

    return 0;
}