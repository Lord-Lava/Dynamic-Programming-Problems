#include <iostream>

using namespace std;

bool sub_pattern_matching(string a,string b){
    int n = a.size();
    int m = b.size();
    
    int i = 0, j = 0;
    int ctr=0;
    while(i<n && j<m){
        if(a[i] == b[j]){
            ctr++;
            i++;j++;
        }
        else{
            j++;
        }
    }

    if(ctr == n){
        return 1;
    }
    return 0;
}

int main(){
    string a,b;
    cin>>a>>b;

    if(a.size()>b.size()){
        cout<<sub_pattern_matching(b,a)<<endl;
    }
    else{
        cout<<sub_pattern_matching(a,b)<<endl;
    }

    return 0;
}