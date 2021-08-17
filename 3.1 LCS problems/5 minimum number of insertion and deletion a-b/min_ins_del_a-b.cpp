#include <iostream>
#include <cstring>

using namespace std;

pair<int,int> LCS(string a,string b,int n,int m){
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
                t[i][j] = max(t[i-1][j],t[i][j-1]);
            }
        }
    }

    return make_pair(n-t[n][m],m-t[n][m]);
}

int main(){
    string a,b;
    cin>>a>>b;

    int n = a.size();
    int m = b.size();

    pair<int,int>ins_del = LCS(a,b,n,m);

    cout<<ins_del.first<<" "<<ins_del.second<<endl;    

    return 0;
}