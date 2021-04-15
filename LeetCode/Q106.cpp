/*
 * @Description: 说明
 * @Author: Marcel
 * @Date: 2021-04-15 15:01:04
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

TreeNode* r_build(vector<int> inorder,vector<int> postorder){
    if(inorder.empty()&&postorder.empty())return nullptr;
    if(inorder.size()==1&&postorder.size()==1)return new TreeNode(inorder[0]);
    TreeNode* tmp=new TreeNode(postorder.back());
    int root_index=find(inorder.begin(),inorder.end(),tmp->val)-inorder.begin();
    tmp->left=r_build(vector<int>(inorder.begin(),inorder.begin()+root_index),vector<int>(postorder.begin(),postorder.begin()+root_index));
    tmp->right=r_build(vector<int>(inorder.begin()+root_index+1,inorder.end()),vector<int>(postorder.begin()+root_index,postorder.end()-1));
    return tmp;
}

TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
    return r_build(inorder,postorder);
}

int main(void){
    
}
