#include <iostream>
#include <cstring>
#include <climits>

using namespace std;

int t[1002][1002];

int coin_change_2(int coin[],int n,int sum){
    if(n==0 && sum==0){
        return INT_MAX-1;   //since if coin_change_2(coin,n,sum-coin[n-1]) = INT_MAX, coin_change_2(coin,n,sum-coin[n-1])+1 = INT_MAX+1 will overflow.
    }
    else if(n==0){
        return INT_MAX-1;
    }
    else if(sum==0){
        return 0;
    }

    if(t[n][sum]!= -1) return t[n][sum];

    if(coin[n-1]<=sum){
        return t[n][sum] = min(coin_change_2(coin,n,sum-coin[n-1]) + 1 , coin_change_2(coin,n-1,sum));
    }
    return t[n][sum] = coin_change_2(coin,n-1,sum);
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
    
    cout<<coin_change_2(coin,n,sum)<<endl;

    return 0;
}