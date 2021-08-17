#include <iostream>
#include <cstring>

using namespace std;

int t[1002][1002];

int SCS(string x,string y,int n,int m){
    if(n==0 || m==0){
        return 0;
    }
    if(t[n][m]!=-1) return t[n][m];

    if(x[n-1] == y[m-1]){
        return t[n][m] = 1+SCS(x,y,n-1,m-1);
    }
    else{
        return t[n][m] = max(SCS(x,y,n-1,m),SCS(x,y,n,m-1));
    }
}

int main(){
    string x,y;
    cin>>x>>y;

    int n = x.size();
    int m = y.size();

    memset(t,-1,sizeof(t));

    cout<<n+m-SCS(x,y,n,m)<<endl;

    return 0;
}