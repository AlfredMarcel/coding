/*
 * @Description: 说明
 * @Author: Marcel
 * @Date: 2021-04-16 20:02:00
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

vector<vector<int>>res;
vector<int>tmp;

void dfs(TreeNode* root,int target){
    if(root==nullptr)return;
    tmp.push_back(root->val);
    if(root->val==target){
        if(root->left==nullptr&&root->right==nullptr){
            res.push_back(tmp);
        }
    }
    dfs(root->left,target-root->val);
    dfs(root->right,target-root->val);
    tmp.pop_back();
}

vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
    dfs(root,targetSum);
    return res;
}

int main(void){
    
}
