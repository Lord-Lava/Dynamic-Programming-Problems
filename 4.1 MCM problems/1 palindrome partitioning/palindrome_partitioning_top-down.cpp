#include <iostream>
#include <cstring>
#include <climits>

using namespace std;

int t[501][501]; //as per GFG constraints

bool isPalindrome(string s,int i,int j){
    if(i>=j) return 1;
    bool ans = 0;
    if(s[i] != s[j]){
        return 0;
    }
    return isPalindrome(s,i+1,j-1);
}

int palindrome_partitioning(string s,int i,int j){
        if(i>=j) return 0;
        
        if(isPalindrome(s,i,j) == 1) return 0;
        
        if(t[i][j]!=-1) return t[i][j];
    
        int mn = INT_MAX;
        int left;int right;
        for (int k = i; k < j; k++)
        {
            if(t[i][k]!=-1){
                left = t[i][k];
            }
            else{
                left = palindrome_partitioning(s,i,k);
                t[i][k] = left;
            }
            if(t[k+1][j]!=-1){
                right = t[k+1][j];
            }   
            else{
                right = palindrome_partitioning(s,k+1,j);
                t[k+1][j] = right;
            }
            int temp = 1+left+right;
            mn = min(temp,mn);
        }
        
        return t[i][j] = mn;
}

int main(){
    string s;
    cin>>s;

    memset(t,-1,sizeof(t));
    cout<<palindrome_partitioning(s,0,(int)s.size()-1);

    return 0;
}