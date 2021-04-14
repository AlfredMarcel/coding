/*
 * @Description: 说明
 * @Author: Marcel
 * @Date: 2021-04-14 21:24:44
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
    return max(r_depth(root->left),r_depth(root->right))+1;
}

int maxDepth(TreeNode* root) {
    return r_depth(root);
}

int main(void){
    
}
