#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

string print_LCS(string x,string y,int n,int m){
    int t[n+1][m+1];
    memset(t,-1,sizeof(t));

    for (int i = 0; i < n+1; i++)
    {
        for (int j = 0; j < m+1; j++)
        {
            if(i==0 || j==0){
                t[i][j] = 0;
            }
        }
    }

    for (int i = 1; i < n+1; i++)
    {
        for (int j = 1; j < m+1; j++)
        {
            if(x[i-1] == y[j-1]){
                t[i][j] = 1 + t[i-1][j-1];
            }
            else{
                t[i][j] = max(t[i-1][j],t[i][j-1]);
            }
        }
    }

    cout<<t[n][m]<<endl;
    
    //print code->
    string s;
    int i = n,j=m;

    while(i>0 && j>0){
        if(x[i-1] == y[j-1]){
            s+=x[i-1];
            i--;j--;
        }
        else{
            if(t[i-1][j]>t[i][j-1]){
                i--;
            }
            else{
                j--;
            }
        }
    }
    reverse(s.begin(),s.end());
    return s;
}

int main(){
    string x,y;
    cin>>x>>y;

    int n = x.size();
    int m = y.size();

    cout<<print_LCS(x,y,n,m)<<endl;

    return 0;
}