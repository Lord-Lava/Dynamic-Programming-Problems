#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int t[1002][1002];

int LCS(string a,string b, int n,int m){
    if(n == 0 || m == 0){
        return 0;
    }
    
    if(t[n][m]!=-1) return t[n][m];

    if(a[n-1] == b[m-1]){
        return t[n][m] = 1 + LCS(a,b,n-1,m-1);
    }
    else{
        return t[n][m] = max(LCS(a,b,n-1,m),LCS(a,b,n,m-1));
    }
}

int LPS(string a){
    string b = a;
    reverse(b.begin(),b.end());

    int n = a.size();
    int m = b.size();

    memset(t,-1,sizeof(t));

    return LCS(a,b,n,m);
}

int main(){
    string a;
    cin>>a;

    cout<<LPS(a)<<endl;

    return 0;
}