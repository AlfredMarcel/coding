/*
 * @Description: 说明
 * @Author: Marcel
 * @Date: 2021-04-08 14:26:11
 */

#include <iostream>
#include <vector>
#include <string>

using namespace std;

int findMin(vector<int>& nums) {
    int left=0;
    int right=nums.size()-1;
    int mid;
    int min=nums[0];
    if(right==0)return min;
    while(right-left>1){
        mid=(left+right)/2;
        if(nums[mid]<min)min=nums[mid];
        
        //左右都有序，直接判断left是不是最小，然后直接返回
        if(nums[left]<nums[right]){if(nums[left]<min)min=nums[left];return min;}

        //左边有序,要去右边找
        if(nums[left]<nums[mid]){
            left=mid+1;
            continue;
        }
        //右边有序，要去左边找
        if(nums[right]>nums[mid]){
            right=mid-1;
            continue;
        }
        
    }
    for(int i=left;i<=right;i++){
        if(nums[i]<min)min=nums[i];
    }
    return min;
}

vector<int>tmp={6,7,8,1,2,3,4,5};

int main(void){
    cout<<findMin(tmp);
}
