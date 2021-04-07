/*
 * @Description: 说明
 * @Author: Marcel
 * @Date: 2021-04-07 14:30:06
 */

#include <iostream>
#include <vector>
#include <string>

using namespace std;
/*
bool search(vector<int>& nums, int target) {

    int left=0;
    int right=nums.size()-1;
    int mid;

    if(nums.size()==1) return (nums[0]==target)?true:false;

    while(left<=right){
        mid=(left+right)/2;
        if(nums[mid]==target)return true;

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
        if(nums[mid]<=nums[right]){
            rside=1;
            if(target>=nums[mid]&&target<=nums[right]){
                left=mid+1;
                continue;
            }
        }

        if(lside==1)left=mid+1;
        if(rside==1)right=mid-1;
        if(lside==1&&rside==1)return false;

    }
    return false;

}*/

int main(void){
    
}
