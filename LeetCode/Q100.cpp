/*
 * @Description: 说明
 * @Author: Marcel
 * @Date: 2021-04-14 15:50:29
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

bool r_same(TreeNode* p,TreeNode* q){
    if(p==nullptr||q==nullptr){
        if(p==nullptr&&q==nullptr)return true;
        return false;
    }
    bool l=r_same(p->left,q->left);
    if(p->val!=q->val)return false;
    bool r=r_same(p->right,q->right);
    return l&&r;
}

bool isSameTree(TreeNode* p, TreeNode* q) {
    return r_same(p,q);
}

int main(void){
    
}
