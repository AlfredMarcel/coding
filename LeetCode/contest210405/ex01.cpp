/*
 * @Description: lc杯 ex01 双指针
 * @Author: Marcel
 * @Date: 2021-04-05 15:00:28
 */

#include <iostream>
#include <vector>
#include <string>
#include<algorithm>

using namespace std;

int purchasePlans(vector<int>& nums, int target) {
    int left=0;
    int right=nums.size()-1;
    int res=0;
    sort(nums.begin(),nums.end());
    while(right>left){
        if(nums[left]+nums[right]<=target){
            res+=(right-left);
            res%=1000000007;
            left++;
        }else{
            right--;
        }
    }
    return res;
}

vector<int>vec={2,2,1,1,2,2,3,4,5,6};

int main(void){
    cout<<purchasePlans(vec,10);
}

