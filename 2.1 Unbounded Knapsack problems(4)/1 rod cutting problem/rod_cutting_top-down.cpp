#include <iostream>
#include <cstring>

using namespace std;

int t[1002][1002];

int rod_cutting(int length[],int price[],int n,int len){
    if(n==0 || len ==0){
        return 0;
    }
    if(t[n][len]!=-1){
        return t[n][len];
    }

    if(length[n-1]<=len){
        return t[n][len] = max(price[n-1] + rod_cutting(length,price,n,len-length[n-1]),rod_cutting(length,price,n-1,len));
    }
    return t[n][len] = rod_cutting(length,price,n-1,len);
}

int main(){
    int n,len;
    cin>>n>>len;

    int length[n];
    int price[n];

    for (int i = 0; i < n; i++)
    {
        cin>>length[i];
    }

    for (int i = 0; i < n; i++)
    {
        cin>>price[i];
    }

    memset(t,-1,sizeof(t));

    cout<<rod_cutting(length,price,n,len)<<endl;

    return 0;
}