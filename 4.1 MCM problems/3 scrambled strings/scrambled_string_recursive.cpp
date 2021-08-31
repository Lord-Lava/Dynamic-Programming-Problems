#include <iostream>

using namespace std;

bool scrambled_string(string a,string b){
    if(a==b) return 1;
    if(a.size()<=1) return 0;

    int n = a.size();

    for (int i = 1; i <= n-1; i++)
    {
        bool c1 = scrambled_string(a.substr(0,i),b.substr(n-i,i)) && scrambled_string(a.substr(i,n-i),b.substr(0,n-i));
        bool c2 = scrambled_string(a.substr(0,i),b.substr(0,i)) && scrambled_string(a.substr(i,n-i),b.substr(i,n-i));
        if( c1 || c2 ){
            return 1;
        }
    }
    return 0;
}

int main(){
    string a,b;
    cin>>a>>b;

    if(a.size() != b.size()) return 0;

    cout<<scrambled_string(a,b)<<endl;

    return 0;
}