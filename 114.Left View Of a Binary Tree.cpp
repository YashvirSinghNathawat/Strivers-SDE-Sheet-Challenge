#include <bits/stdc++.h> 
/************************************************************

    Following is the TreeNode class structure

    template <typename T>
    class TreeNode {
       public:
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/
void preorder(TreeNode<int> *root,int level,vector<int> &res){
    if(root==NULL)  return;
    if(res.size()==level)  res.push_back(root->data);
    preorder(root->left,level+1,res);
    preorder(root->right,level+1,res);
}
vector<int> getLeftView(TreeNode<int> *root)
{
    //    Write your code here
    vector<int> res;
    preorder(root,0,res);
    return res;

}