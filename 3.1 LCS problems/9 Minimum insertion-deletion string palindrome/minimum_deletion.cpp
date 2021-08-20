#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int LPS(string a, string b,int n,int m){
    int t[n+1][m+1];
    memset(t,-1,sizeof(t));

    for (int i = 0; i < n+1; i++)
    {
        for (int j = 0; j < m+1; j++)
        {
            if(i==0 || j==0)
                t[i][j] = 0;
        }
    }

    for (int i = 1; i < n+1; i++)
    {
        for (int j = 1; j < m+1; j++)
        {
            if(a[i-1] == b[j-1]){
                t[i][j] = 1 + t[i-1][j-1];
            }
            else{
                t[i][j] = max(t[i-1][j] , t[i][j-1]); 
            }
        }
    }

    return t[n][m];
}

int min_del(string s){
    string b = s;
    reverse(b.begin(),b.end());

    int n = s.length();
    int m = b.length();

    return n-LPS(s,b,n,m);  
}

int main(){
    string s;
    cin>>s;

    cout<<min_del(s)<<endl;

    return 0;
}