/*
 * @Description: 说明
 * @Author: Marcel
 * @Date: 2021-04-09 21:37:36
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

vector<TreeNode*> generateTrees(int n) {
    
}

int main(void){
    
}
