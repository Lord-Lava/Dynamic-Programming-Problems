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

    int left,right;
    for(int k=1;k<=f;k++){
        if(t[e-1][k-1]!=-1){
            left = t[e-1][k-1];
        }
        else{
            left = egg_drop(e-1,k-1);
            t[e-1][k-1] = left;
        }
        if(t[e][f-k]!=-1){
            right = t[e][f-k];
        }
        else{
            right = egg_drop(e,f-k);
            t[e][f-k] = right;
        }

        int temp = 1 + max(left , right);
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