/*
 * @Description: 说明
 * @Author: Marcel
 * @Date: 2021-04-15 15:21:39
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

vector<vector<int>> levelOrderBottom(TreeNode* root) {
    vector<vector<int>>res;
    queue<TreeNode*>que1;
    queue<TreeNode*>que2;
    que1.push(root);
    while(!(que1.empty()&&que2.empty())){
        vector<int>tmp;
        while(!que1.empty()){
            TreeNode* current=que1.front();
            if(current!=nullptr){
                que2.push(current->left);
                que2.push(current->right);
                tmp.push_back(current->val);
            }
            que1.pop();
        }
        swap(que1,que2);
        if(!tmp.empty())res.insert(res.begin(),tmp);
    }
    return res;
}

int main(void){
    
}
