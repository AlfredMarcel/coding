/*
 * @Description: 说明
 * @Author: Marcel
 * @Date: 2021-04-09 00:07:09
 */
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int findMin(vector<int>& nums) {
    int n=nums[0];
    for(int i=0;i<nums.size();i++){
        if(nums[i]<n)n=nums[i];
    }
    return n;
}

int main(void){
    
}
