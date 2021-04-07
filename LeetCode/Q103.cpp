/*
 * @Description: 说明
 * @Author: Marcel
 * @Date: 2021-04-07 19:33:05
 */

#include <iostream>
#include <vector>
#include <string>
#include<queue>
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

void r_travel(TreeNode* root ,vector<vector<int>>* res){
    vector<int>tmp;
    int count=0;
    stack<TreeNode*>left;
    stack<TreeNode*>right;
    if(root!=nullptr){
        left.push(root);
        tmp.push_back(root->val);
        res->push_back(tmp);
    }
    while(true){
        if(((count+2)%2==0&&left.empty())||((count+2)%2==1&&right.empty()))break;
        else{
            count++;
            tmp.clear();
            /*left-->right*/
            if((count+2)%2==1){
                while(left.empty()!=true){
                    TreeNode* t=left.top();
                    if(t->right!=nullptr){
                        right.push(t->right);
                        tmp.push_back(right.top()->val);
                    }
                    if(t->left!=nullptr){
                        right.push(t->left);
                        tmp.push_back(right.top()->val);
                    }
                    
                    left.pop();
                }
                if(tmp.size()!=0)res->push_back(tmp);
            }
            /*right-->left*/
            else{
                while(right.empty()!=true){
                    TreeNode* t=right.top();
                    if(t->left!=nullptr){
                        left.push(t->left);
                        tmp.push_back(left.top()->val);
                    }
                    if(t->right!=nullptr){
                        left.push(t->right);
                        tmp.push_back(left.top()->val);
                    }
                    
                    right.pop();
                }
                if(tmp.size()!=0)res->push_back(tmp);
            }
        }
    }

}

vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
    vector<vector<int>>res;
    r_travel(root,&res);
    return res;
}

int main(void){
    TreeNode a(15);
    TreeNode b(7);
    TreeNode c(20,&a,&b);
    TreeNode d(9);
    TreeNode e(3,&d,&c);

    zigzagLevelOrder(&e);
}
