/*
 * @Description: leetcode 二叉树输入处理的代码，可以到这个文件里调试
 * @Author: Marcel
 * @Date: 2021-04-07 16:50:36
 */

#include <iostream>
#include <vector>
#include <string>
#include<stack>
#include<queue>
#include<sstream>


using namespace std;



struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };

class Solution {
public:

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
                    if(t->left!=nullptr){
                        right.push(t->left);
                        tmp.push_back(t->val);
                    }
                    if(t->right!=nullptr){
                        right.push(t->right);
                        tmp.push_back(t->val);
                    }
                    left.pop();
                }
                res->push_back(tmp);
            }
            /*right-->left*/
            else{
                while(right.empty()!=true){
                    TreeNode* t=right.top();
                    if(t->right!=nullptr){
                        left.push(t->right);
                        tmp.insert(tmp.begin(),t->val);
                    }
                    if(t->left!=nullptr){
                        left.push(t->left);
                        tmp.insert(tmp.begin(),t->val);
                    }
                    right.pop();
                }
                res->push_back(tmp);
            }
        }
    }

}

vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
    vector<vector<int>>res;
    r_travel(root,&res);
    return res;
}


TreeNode* stringToTreeNode(string input) {

    input = input.substr(1, input.length() - 2);
    if (!input.size()) {
        return nullptr;
    }

    string item;
    stringstream ss;
    ss.str(input);

    getline(ss, item, ',');
    TreeNode* root = new TreeNode(stoi(item));
    queue<TreeNode*> nodeQueue;
    nodeQueue.push(root);

    while (true) {
        TreeNode* node = nodeQueue.front();
        nodeQueue.pop();

        if (!getline(ss, item, ',')) {
            break;
        }

        if (item != "null") {
            int leftNumber = stoi(item);
            node->left = new TreeNode(leftNumber);
            nodeQueue.push(node->left);
        }

        if (!getline(ss, item, ',')) {
            break;
        }

        if (item != "null") {
            int rightNumber = stoi(item);
            node->right = new TreeNode(rightNumber);
            nodeQueue.push(node->right);
        }
    }
    return root;
}

string integerVectorToString(vector<int> list, int length = -1) {
    if (length == -1) {
        length = list.size();
    }

    if (length == 0) {
        return "[]";
    }

    string result;
    for(int index = 0; index < length; index++) {
        int number = list[index];
        result += to_string(number) + ", ";
    }
    return "[" + result.substr(0, result.length() - 2) + "]";
}

int main() {
    string line;
    while (getline(cin, line)) {
        TreeNode* root = stringToTreeNode(line);
        
        vector<vector<int>> ret = Solution().zigzagLevelOrder(root);

        
    }
    return 0;
}

};