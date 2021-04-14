/*
 * @Description: 递归自底向上构造，适合写带返回值的递归函数
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

vector<TreeNode*> create(int left,int right){
    vector<TreeNode*>res;
    if(left>right){
        res.push_back(nullptr);
    }else{
        for(int i=left;i<=right;i++){
            vector<TreeNode*>l=create(left,i-1);
            vector<TreeNode*>r=create(i+1,right);
            for(TreeNode* ll:l){
                for(TreeNode* rr:r){
                    TreeNode* tmp=new TreeNode(i,ll,rr);
                    res.push_back(tmp);
                }
            }
        }
    }
    return res;
}

vector<TreeNode*> generateTrees(int n) {
    vector<TreeNode*>res;
    if(n!=0)res=create(1,n);
    return res;    
}

int main(void){
    
}
