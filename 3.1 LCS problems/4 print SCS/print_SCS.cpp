#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

string SCS(string x,string y,int n,int m){
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
            if(x[i-1] == y[j-1]){
                t[i][j] = 1 + t[i-1][j-1];
            }
            else{
                t[i][j] = max(t[i-1][j],t[i][j-1]);
            }
        }
    }
    
    int i = n,j=m;string s;

    while(i>0 && j>0){
        if(x[i-1] == y[j-1]){
            s+=x[i-1];
            i--;j--;
        }
        else{
            if(t[i-1][j]>t[i][j-1]){
                s+=x[i-1];  //include the [i-1]th character before moving further
                i--;
            }
            else{
                s+=y[j-1];  //include the [j-1]th character before moving further
                j--;
            }
        }
    }

    //we have to include the rest of the string left if i/j reaches 0.
    while(i>0){
        s+=x[i-1];
        i--;
    }

    while(j>0){
        s+=y[j-1];
        j--;
    }

    reverse(s.begin(),s.end());

    return s;
}

int main(){
    string x,y;
    cin>>x>>y;

    int n = x.size();
    int m = y.size();

    string ans = SCS(x,y,n,m);

    cout<<ans<<endl;

    return 0;
}