/*
 * @Description: 说明
 * @Author: Marcel
 * @Date: 2021-04-15 16:27:51
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
#include<algorithm>

using namespace std;

int r_depth(TreeNode* root){
    if(root==nullptr)return 0;
    int l=r_depth(root->left);
    int r=r_depth(root->right);
    if(min(l,r)!=0)return min(l,r)+1;
    else return max(l,r)+1;
}

int minDepth(TreeNode* root) {
    return r_depth(root);
}

int main(void){
    
}
