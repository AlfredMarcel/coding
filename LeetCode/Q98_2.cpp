/*
 * @Description: 和Q98一样，同样是中序遍历，但是减少不必要的递归传参
 * @Author: Marcel
 * @Date: 2021-04-14 15:27:51
 */

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

#include <iostream>
#include <vector>
#include <string>

using namespace std;

long pre=-1e12;

bool r_bst(TreeNode* root){
    if(root==nullptr)return true;
    bool l=r_bst(root->left);
    if(root->val<=pre)return false;
    res=root->val;
    bool r=r_bst(root->right);
    return l&&r;
}

bool isValidBST(TreeNode* root){
    return r_bst(root);
}

int main(void){
    
}

