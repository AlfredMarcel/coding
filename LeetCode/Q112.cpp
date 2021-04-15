/*
 * @Description: 忽略了正负数的计算
 * @Author: Marcel
 * @Date: 2021-04-15 16:35:58
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

void dfs(TreeNode* root ,int target,bool& flag){
    if(flag==true)return;
    if(root==nullptr)return;
    if(root->val==target){
        /*叶子结点*/
        if(root->left==nullptr&&root->right==nullptr)flag=true;
        /*不是叶子结点的话，这时候要继续dfs，因为可能后面到叶子遍历到的和又为0了*/
    }
    dfs(root->left,target-root->val,flag);
    dfs(root->right,target-root->val,flag);
}

bool hasPathSum(TreeNode* root, int targetSum) {
    bool flag=false;
    dfs(root,targetSum,flag);
    return flag;
}

int main(void){
    TreeNode* t1=new TreeNode(-3);
    TreeNode* t2=new TreeNode(-2,nullptr,t1);
    cout<<hasPathSum(t2,5);
}
