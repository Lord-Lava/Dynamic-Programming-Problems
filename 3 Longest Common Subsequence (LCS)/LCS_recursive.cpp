#include <iostream>

using namespace std;

int LCS(string x,string y,int n,int m){
    if(n==0 || m==0) 
        return 0;
    
    if(x[n-1] == y[n-1]) 
        return 1+LCS(x,y,n-1,m-1);
    else 
        return max( LCS(x,y,n,m-1) , LCS(x,y,n-1,m) );
}

int main(){
    string x,y;
    cin>>x>>y;

    int n = x.size();
    int m = y.size();

    cout<<LCS(x,y,n,m)<<endl;

    return 0;
}