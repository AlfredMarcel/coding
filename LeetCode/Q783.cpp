/*
 * @Description: 说明
 * @Author: Marcel
 * @Date: 2021-04-13 10:35:50
 */

#include <iostream>
#include <vector>
#include <string>
#include<algorithm>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
    
void r_min(TreeNode* root,int& mini,vector<int>& vec){
    if(root==nullptr)return;
    r_min(root->left,mini,vec);
    if(!vec.empty()){
        mini=(min(mini,root->val-vec.back()));
    }
    vec.push_back(root->val);
    r_min(root->right,mini,vec);
}

int minDiffInBST(TreeNode* root) {
    int min=100001;
    vector<int>vec;
    r_min(*root,min,vec);
    return min;
}

int main(void){
    
}
