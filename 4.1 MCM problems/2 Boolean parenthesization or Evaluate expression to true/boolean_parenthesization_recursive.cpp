#include <iostream>

using namespace std;

int solve(string s,int i,int j,bool isTrue){
    if(i>j) return false;
    if(i==j){
        if(isTrue == 1){
            return s[i] == 'T';
        }
        else{
            return s[i] == 'F';
        }
    }

    int ans = 0;

    for(int k=i+1;k<=j-1;k+=2){
        int lT = solve(s,i,k-1,1);
        int lF = solve(s,i,k-1,0);
        int rT = solve(s,k+1,j,1);
        int rF = solve(s,k+1,j,0);

        if(s[k] == '&'){
            if(isTrue == 1)
                ans+= lT * rT;
            else
                ans+= lT*rF + rT*lF + rF*lF;
        }
        else if(s[k] == '|'){
            if(isTrue == 1)
                ans+= lT * rT + lT*rF + rT*lF;
            else
                ans+= rF*lF;
        }
        else if(s[k] == '^'){
            if(isTrue == 1)
                ans+= lT*rF + rT*lF;
            else
                ans+= rF*lF + lT * rT;
        }
    }

    return ans;
}

int main(){
    string s;
    cin>>s;

    cout<<solve(s,0,(int)s.size()-1,true)<<endl;

    return 0;
}