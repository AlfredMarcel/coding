/*
 * @Description: 说明
 * @Author: Marcel
 * @Date: 2021-04-08 15:54:02
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

void r_travel(TreeNode* root,vector<int>* res){
    if(root==nullptr)return;
    r_travel(root->left,res);
    res->push_back(root->val);
    r_travel(root->right,res);
}

class BSTIterator {

    int i,size;
    vector<int> tmp;

public:
    BSTIterator(TreeNode* root) {
        r_travel(root,&tmp);
        size=tmp.size();
        i=-1;
    }
    
    int next() {
        i++;
        return tmp[i];
    }
    
    bool hasNext() {
        if(size-i>=2)return true;
        return false;
    }
};

int main(void){
    
}
