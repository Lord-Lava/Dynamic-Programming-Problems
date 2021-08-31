#include <iostream>
#include <climits>

using namespace std;

struct node{
    int val;
    struct node* left;
    struct node* right;
    node(int x){
        val = x;
        right = NULL;
        left = NULL;
    }
};

int max_path_sum2(node* root,int& res){
    if(root == NULL) return 0;

    int l = max_path_sum2(root->left,res);
    int r = max_path_sum2(root->right,res);

    int temp = max(l,r) + root->val;
    if(root->left == NULL && root->right == NULL){
        temp = max(temp,root->val);
    }
    int ans = max(temp,l+r+root->val);
    res = max(res,ans);

    return temp;
}

int main(){
    struct node* root = new node(10);
    root->left = new node(2);
    root->left->left = new node(20);
    root->left->right = new node(1);
    root->right = new node(10);
    root->right->right = new node(-25);
    root->right->right->right = new node(4);
    root->right->right->left = new node(3);

    int res = INT_MIN;
    max_path_sum2(root,res);
    cout<<res<<endl;

    return 0;
}