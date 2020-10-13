#include<bits/stdc++.h>
using namespace std;
struct TreeNode{
    int val;
    TreeNode *left,*right;
    TreeNode(int _val):val(_val),left(NULL),right(NULL){}
};

int minDepth(TreeNode* root){
    if(!root) return 0;
    if(!root->left && !root->right) return 1;
    if(!root->left) return minDepth(root->right)+1;
    if(!root->right) return minDepth(root->left)+1;

    return min(minDepth(root->left),minDepth(root->right));
   
}

int main()
{
    auto root=new TreeNode(0);
    root->left=new TreeNode(1);
    cout<<minDepth(root)<<endl;
    return 0;
}