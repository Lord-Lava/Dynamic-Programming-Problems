#include <iostream>
#include <cstring>
#include <unordered_map>

using namespace std;

unordered_map<string,bool> mp;

bool scrambled_string(string a,string b){
    if(a==b) return 1;
    if(a.size()<=1) return 0;

    string key = a;
    key+=' ';
    key.append(b);

    if(mp.find(key)!=mp.end()){
        return mp[key];
    }

    int n = a.size();

    for (int i = 1; i < n; i++)
    {
        bool c1 = scrambled_string(a.substr(0,i),b.substr(n-i,i)) && scrambled_string(a.substr(i,n-i),b.substr(0,n-i));
        bool c2 = scrambled_string(a.substr(0,i),b.substr(0,i)) && scrambled_string(a.substr(i,n-i),b.substr(i,n-i));
        if(c1 || c2){
            return mp[key] = 1;
        }
    }
    return mp[key] = 0;
}

int main(){
    string a,b;
    cin>>a>>b;

    if(a.size()!=b.size()) return 0;

    cout<<scrambled_string(a,b)<<endl;

    return 0;
}