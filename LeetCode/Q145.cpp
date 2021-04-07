/*
 * @Description: 说明
 * @Author: Marcel
 * @Date: 2021-04-07 21:32:28
 */
#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

void r_travel(TreeNode* root,vector<int>* res){
    if(root==nullptr)return;
    r_travel(root->left,res);
    r_travel(root->right,res);
    res->push_back(root->val);
}

vector<int> postorderTraversal(TreeNode* root) {
    vector<int> res;
    r_travel(root,&res);
    return res;
}

int main(void){
    
}

