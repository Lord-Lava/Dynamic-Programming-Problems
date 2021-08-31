#include <iostream>
#include <climits>

using namespace std;

int egg_drop(int e,int f){
    if(f==0 || f==1) return f;
    if(e==1) return f;

    int mn = INT_MAX;

    for(int k=1;k<=f;k++){
        int temp = 1 + max(egg_drop(e-1,k-1) , egg_drop(e,f-k));
        mn = min(mn,temp);
    }
    return mn;
}

int main(){
    int e,f;
    cin>>e>>f;

    cout<<egg_drop(e,f)<<endl;

    return 0;
}