#include <iostream>
#include <cstring>

using namespace std;

int main(){
    int n;cin>>n;int len;cin>>len;
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

    int t[len+1][n+1];
    memset(t,-1,sizeof(t));
    
    for (int i = 0; i < len+1; i++)
    {
        for (int j = 0; j < n+1; j++)
        {
            if(i==0 || j==0){
                t[i][j] = 0;
            }
        }
    }

    for (int i = 1; i < len+1; i++)
    {
        for (int j = 1; j < n+1; j++)
        {
            if(length[i-1]<=j){
                t[i][j] = max(price[i-1] + t[i][j-length[i-1]],t[i-1][j]);
            }
            else{
                t[i][j] = t[i-1][j];
            }
        }
    }
    
    cout<<t[n][len]<<endl;

    return 0;
}