/*
 * @Description: 双指针left，right，二分查找
 * @Author: Marcel
 * @Date: 2021-04-07 13:26:22
 */

#include <iostream>
#include <vector>
#include <string>

using namespace std;

int search(vector<int>& nums, int target) {
    int left=0;
    int right=nums.size()-1;
    int mid;

    //nums长度为1需要拦截，不然mid+1就越界了
    if(nums.size()==1)return (nums[0]==target)?0:-1;

    while(right>=left){
                
       mid=(left+right)/2;
        if(nums[mid]==target)return mid;

        int lside=0;
        int rside=0;

        //左半边有序
        if(nums[left]<=nums[mid]){
            lside=1;
            if(target>=nums[left]&&target<=nums[mid]){
                right=mid-1;
                continue;
            }
        }
        //右半边有序
        if(nums[mid+1]<=nums[right]){
            rside=1;
            if(target>=nums[mid+1]&&target<=nums[right]){
                left=mid+1;
                continue;
            }
        }

        if(lside==1)left=mid+1;
        if(rside==1)right=mid-1;
        if(lside==1&&rside==1)return -1;

    }
    return -1;
}

vector<int>vec ={3,1};

int main(void){
    cout<<search(vec,0);
}

