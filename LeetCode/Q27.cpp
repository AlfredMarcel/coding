/*
 * @Description: 说明
 * @Author: Marcel
 * @Date: 2021-04-19 08:12:28
 */

#include <iostream>
#include <vector>
#include <string>

using namespace std;

int removeElement(vector<int>& nums, int val) {
    if(nums.size()==0)return 0;
    int right=nums.size();
    for(int i=0;i<right;i++){
        if(nums[i]==val){
            while(right==nums.size()||nums[right]==val){
                if(right<=i)return right;
                right--;
            }
            swap(nums[i],nums[right]);
        }
    }
    return right;
}

int main(void){
    vector<int>vec={1,2,3,4,5,3,3,3,6,7,3,4};
    cout<<removeElement(vec,3);
}
