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
    if(des.size()!=0)des.erase(des.begin()+des.size()-1,des.end());
    return des;
}
};


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
        
        vector<int> ret = Solution().inorderTraversal(root);

        string out = integerVectorToString(ret);
        cout << out << endl;
    }
    return 0;
}

