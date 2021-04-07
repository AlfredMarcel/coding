/*
 * @Description: 二叉树的中序遍历
 * @Author: Marcel
 * @Date: 2021-04-07 15:09:27
 */

#include <iostream>
#include <vector>
#include <string>
#include<stack>

using namespace std;

struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };

/*递归方法*/


void r_inorder(TreeNode* root,vector<int>* des){
    if(root==nullptr)return;
    r_inorder(root->left,des);
    des->push_back(root->val);
    r_inorder(root->right,des);
}

/*迭代方法*/

void d_inorder(TreeNode* root,vector<int>* des){
    stack<TreeNode*>call;
    if(root!=nullptr)call.push(root);
    while(call.empty()!=true){

        if(root!=nullptr){
            call.push(root);
            root=root->left;
        }
        //到底了
        else{
            des->push_back(call.top()->val);
            root=call.top()->right;
            call.pop();
        }
    }

}

//中序遍历  左根右
vector<int> inorderTraversal(TreeNode* root) {
    vector<int>des;
    //r_inorder(root,&des);
    d_inorder(root,&des);
    des.erase(des.begin()+des.size()-1,des.end());
    return des;
}




int main(void){
    inorderTraversal(nullptr);
    
}

