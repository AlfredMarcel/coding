/*
 * @Description: 说明
 * @Author: Marcel
 * @Date: 2021-04-14 21:12:48
 */
#include <iostream>
#include <vector>
#include <string>
#include<queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

vector<vector<int>> levelOrder(TreeNode* root) {
    vector<vector<int>>res;
    queue<TreeNode*>que1;
    queue<TreeNode*>que2;
    que1.push(root);

    while(!(que1.empty()&&que2.empty())){
        vector<int>tmp;
        while(!que1.empty()){
            if(que1.front()!=nullptr){
                que2.push(que1.front()->left);
                que2.push(que1.front()->right);
                tmp.push_back(que1.front()->val);
            }
            que1.pop();
        }
        if(!tmp.empty())res.push_back(tmp);
        swap(que1,que2);
    }
}

int main(void){
    
}
