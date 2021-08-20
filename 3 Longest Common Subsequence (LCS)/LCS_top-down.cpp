#include <iostream>
#include <cstring>

using namespace std;

int static t[1002][1002];

int LCS(string x,string y,int n,int m){
    if(n==0 || m==0) 
        return 0;

    if(t[n][m]!=-1) return t[n][m];
    
    if(x[n-1] == y[m-1]) 
        return t[n][m] = 1+LCS(x,y,n-1,m-1);
    else 
        return t[n][m] = max( LCS(x,y,n,m-1) , LCS(x,y,n-1,m) );
}

int main(){
    string x,y;
    cin>>x>>y;

    int n = x.size();
    int m = y.size();

    memset(t,-1,sizeof(t));

    cout<<LCS(x,y,n,m)<<endl;

    return 0;
}