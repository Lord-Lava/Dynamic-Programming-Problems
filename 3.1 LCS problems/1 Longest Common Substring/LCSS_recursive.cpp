#include <iostream>
#include <cstring>

using namespace std;

int LCSS(string x,string y,int n,int m,int count){
    if(n==0 || m==0){
        return count;
    }

    if(x[n-1] == y[m-1]){
        count = LCSS(x,y,n-1,m-1,count+1);
    }

    count = max(count,max(LCSS(x,y,n-1,m,0),LCSS(x,y,n,m-1,0)));
    
    return count;
}

int main(){
    string x,y;
    cin>>x>>y;

    int n = x.size();
    int m = y.size();

    cout<<LCSS(x,y,n,m,0)<<endl;

    return 0;
}