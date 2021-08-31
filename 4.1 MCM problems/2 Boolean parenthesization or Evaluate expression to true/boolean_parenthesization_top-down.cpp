#include <iostream>
#include <cstring>
#include <unordered_map>
#include <string>

using namespace std;

#define int long long

unordered_map<string,int> mp;

int t[1001][1001][2];

int solve(string s,int i,int j,bool isTrue){
    if(i>j){
        return false;
    }
    if(i==j){
        if(isTrue == 1){
            return s[i] == 'T';
        }
        else{
            return s[i] == 'F';
        }
    }

    // memoization using unordered_map ->
    string temp = to_string(i);
    temp.append(" ");
    temp.append(to_string(j));
    temp.append(" ");
    temp.append(to_string(isTrue));

    if(mp.find(temp)!=mp.end()){
        return mp[temp];
    }

    // if(t[i][j][isTrue]!=-1){
    //     return t[i][j][isTrue];
    // }

    int ans = 0;

    for(int k=i+1;k<j;k+=2){
        int lT = solve(s,i,k-1,1);
        int lF = solve(s,i,k-1,0);
        int rT = solve(s,k+1,j,1);
        int rF = solve(s,k+1,j,0);

        if(s[k] == '&'){
            if(isTrue == 1){
                ans+= lT*rT;
            }
            else{
                ans+= lT*rF + rT*lF + lF*rF;
            }
        }
        else if(s[k] == '|'){
            if(isTrue == 1){
                ans+= lT*rF + rT*lF + lT*rT;
            }
            else{
                ans+= lF*rF;
            }
        }
        else if(s[k] == '^'){
            if(isTrue == 1){
                ans+= rT*lF + rF*lT;
            }
            else{
                ans+= rT*lT + rF*lF;
            }
        }
    }

    return mp[temp] = ans%1003;
    // return t[i][j][isTrue] = ans;
}

signed main(){
    string s;
    cin>>s;

    memset(t,-1,sizeof(t));
    cout<<solve(s,0,(int)s.size()-1,true)%1003<<endl;

    return 0;
}