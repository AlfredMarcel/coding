/*
 * @Description: 给前序和中序遍历序列，重建二叉树。 定位左右子树，递归创建。
 * @Author: Marcel
 * @Date: 2021-04-14 21:29:24
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

TreeNode* r_build(vector<int>pre,vector<int>in){
    if(pre.empty()&&in.empty())return nullptr;
    if(pre.size()==1&&in.size()==1){
        TreeNode* tmp=new TreeNode(pre[0]);
        return tmp;
    }
    TreeNode* tmp=new TreeNode(pre[0]);
    vector<int>::iterator it=find(in.begin(),in.end(),pre[0]);
    int root_index=it-in.begin();
    tmp->left=r_build(vector<int>(pre.begin()+1,pre.begin()+1+root_index),vector<int>(in.begin(),in.begin()+root_index));
    tmp->right=r_build(vector<int>(pre.begin()+1+root_index,pre.end()),vector<int>(in.begin()+root_index+1,in.end()));
    return tmp;
}

TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    return r_build(preorder,inorder);
}

int main(void){
    vector<int>pre={3,9,20,15,7};
    vector<int>in={9,3,15,20,7};
    buildTree(pre,in);
}
