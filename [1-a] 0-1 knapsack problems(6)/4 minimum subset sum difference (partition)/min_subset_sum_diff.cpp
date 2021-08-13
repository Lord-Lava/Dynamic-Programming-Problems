#include <iostream>
#include <cstring>
#include <climits>
#include <vector>

using namespace std;

int main(){
    int n;cin>>n;
    int arr[n];

    int range = 0;

    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
        range+=arr[i];
    }

    bool t[n+1][range+1];
    memset(t,0,sizeof(t));

    for (int i = 0; i < n+1; i++)
    {
        for (int j = 0; j < range+1; j++)
        {
            if(i==0){
                t[i][j] = false;
            }
            else{
                t[i][j] = true;
            }
        }
    }

    vector<int>v;
    
    for (int i = 1; i < n+1; i++)
    {
        for (int j = 1; j < range+1; j++)
        {
            if(arr[i-1]<=range){
                t[i][j] = t[i-1][j-arr[i-1]] || t[i-1][j];
            }
            else{
                t[i][j] = t[i-1][j];
            }
            if(i==n && t[i][j] == true){
                v.push_back(i);
            }
        } 
    }

    int mn = INT_MAX;

    for (int i = 0; i < v.size(); i++)
    {
        mn = min(mn,range-2*v[i]);
    }

    cout<<mn<<endl;

    return 0;
}