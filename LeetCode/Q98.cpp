/*
 * @Description: 说明
 * @Author: Marcel
 * @Date: 2021-04-14 14:56:29
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

void r_travel(TreeNode* root,vector<int>& res,bool& flag){
    if(root==nullptr)return;
    if(flag==false)return;
    r_travel(root->left,res,flag);
    if(!res.empty()&&res.back()>=root->val)flag=false;
    res.push_back(root->val);
    r_travel(root->right,res,flag);
}


bool isValidBST(TreeNode* root) {
    vector<int>vec;
    bool flag=true;
    r_travel(root,vec,flag);
    
    return flag;
}

int main(void){
    
}

