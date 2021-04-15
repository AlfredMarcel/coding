/*
 * @Description: 说明
 * @Author: Marcel
 * @Date: 2021-04-15 15:49:26
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

int cal_height(TreeNode* root,bool& flag){
    if(root==nullptr)return 0;
    if(flag==false)return 0;
    int l=cal_height(root->left);
    int r=cal_height(root->right);
    if(abs(l-r)>1)flag=false;
    return max(l,r)+1;
}

bool isBalanced(TreeNode* root) {
    bool flag=true;
    cal_height(root,flag);
    return flag;
}

int main(void){
    
}
