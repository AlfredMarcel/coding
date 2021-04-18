/*
 * @Description: 说明
 * @Author: Marcel
 * @Date: 2021-04-17 22:27:38
 */

#include <iostream>
#include <vector>
#include <string>

using namespace std;

int minOperations(vector<int>& nums) {
    int sum=0;
    if(nums.size()==1)return sum;
    for(int i=1;i<nums.size();i++){
        if(nums[i]>nums[i-1])continue;
        else{
            sum+=(nums[i-1]-nums[i])+1;
            nums[i]+=(nums[i-1]-nums[i])+1;
        }
    }
    return sum;
}

int main(void){
    vector<int>vec={1,5,2,4,1};
    cout<<minOperations(vec);
}
