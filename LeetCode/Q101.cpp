/*
 * @Description: 判断结构对称的二叉树，一开始以为中序遍历（空结点填null）结果对称就行，可惜错了。
 * @Author: Marcel
 * @Date: 2021-04-14 15:59:32
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
#include<queue>

using namespace std;

void r_travel(TreeNode* root,deque<string>& res){
    if(root==nullptr){
        res.push_back("null");
        return;
    }
    if(root->left==nullptr&&root->right==nullptr){
        res.push_back(to_string(root->val));
        return;    
    }
    r_travel(root->left,res);
    res.push_back(to_string(root->val));
    r_travel(root->right,res);
}

bool isSymmetric(TreeNode* root) {
    deque<string>res;
    r_travel(root,res);

    bool flag=true;
    while(res.size()>1){
        if(res.front()!=res.back()){
            flag=false;
            break;
        }
        res.pop_front();
        res.pop_back();
    }
    return flag;
}

int main(void){
    
}
