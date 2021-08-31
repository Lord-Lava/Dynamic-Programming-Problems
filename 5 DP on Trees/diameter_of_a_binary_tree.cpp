#include <iostream>
#include <climits>

using namespace std;

class node{
    public:
     
    int data;
    node* left;
    node* right;

    node(int x){
        data = x;
        right = NULL;
        left = NULL;
    } 
};

int diameter(node* root, int& res){
    if(root == NULL) return 0;

    int l = diameter(root->left,res);
    int r = diameter(root->right,res);

    int temp = 1 + max(l,r);
    res = max(res,1+l+r);

    return temp;
}



int main(){
    node* root = new node(1);
    root->left = new node(2);
    root->left->left = new node(3);
    root->left->right = new node(4);
    root->left->right->right = new node(5);
    root->left->right->left = new node(6);
    root->right = new node(7);
    root->right->right = new node(8);
    root->right->right->right = new node(9);
    root->right->right->right->right = new node(10);
    root->right->right->right->left = new node(11);
    root->right->right->right->left->right = new node(12);
    root->right->right->right->left->left = new node(13);

    int res = INT_MIN;

    diameter(root,res);

    cout<<res<<endl;

    return 0;
}