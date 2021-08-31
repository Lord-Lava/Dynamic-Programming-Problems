#include <iostream>
#include <cstring>
#include <climits>

using namespace std;

int t[1001][1001];

int egg_drop(int e,int f){
    if(f==0 || f==1) return f;
    if(e==1) return f;

    int mn = INT_MAX;

    if(t[e][f]!=-1) return t[e][f];

    for(int k=1;k<=f;k++){
        int temp = 1 + max(egg_drop(e-1,k-1) , egg_drop(e,f-k));
        mn = min(mn,temp);
    }
    return t[e][f] = mn;
}

int main(){
    int e,f;
    cin>>e>>f;

    memset(t,-1,sizeof(t));

    cout<<egg_drop(e,f)<<endl;

    return 0;
}