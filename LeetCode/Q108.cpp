/*
 * @Description: 说明
 * @Author: Marcel
 * @Date: 2021-04-15 15:36:54
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

TreeNode* r_build(int left,int right,vector<int>& nums){
    if(left>right)return nullptr;
    else if(left==right)return new TreeNode(nums[left]);
    else{
        int mid=(left+right)/2;
        TreeNode* tmp =new TreeNode(nums[mid]);
        tmp->left=r_build(left,mid-1,nums);
        tmp->right=r_build(mid+1,right,nums); 
    }
}

TreeNode* sortedArrayToBST(vector<int>& nums) {
    int left=0;
    int right=nums.size()-1;
    return r_build(left,right,nums);
}

int main(void){
    
}
