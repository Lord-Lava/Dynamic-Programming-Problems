#include <iostream>
#include <cstring>
#include <climits>

using namespace std;

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

    int mn = INT_MAX;
    
    for (int k = i; k < j; k++)
    {
        int temp = 1+palindrome_partitioning(s,i,k)+palindrome_partitioning(s,k+1,j);
        mn = min(mn,temp);
    }
    
    return mn;
}

int main(){
    string s;
    cin>>s;

    cout<<palindrome_partitioning(s,0,(int)s.size()-1);

    return 0;
}