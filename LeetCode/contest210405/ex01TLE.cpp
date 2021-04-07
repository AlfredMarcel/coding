/*
 * @Description: lc春季赛 TLE
 * @Author: Marcel
 * @Date: 2021-04-05 15:00:28
 */

#include <iostream>
#include <vector>
#include <string>
#include<algorithm>

using namespace std;

int purchasePlans(vector<int>& nums, int target) {
    sort(nums.begin(),nums.end());
    int res=0;
    int left=-1,right=-1;
    for(int i=0;i<nums.size();i++){
        if(2*nums[i]>target&&left==-1){
            left=i;
        }
        if(nums[i]>target&&right==-1){
            right=i;
        }
    }
    if(left==-1)left=nums.size();
    if(right==-1)right=nums.size();
    res=(res+(left*(left-1)/2))%1000000007;
    int tmp_res=0;
    for(int i=0;i<left;i++){
        for(int j=left;j<right;j++){
            if(nums[i]+nums[j]<=target){
                tmp_res=(tmp_res+1)%1000000007;
            }
        }
    }
    res=(res+tmp_res)%1000000007;
    return res;
}

vector<int>vec ={1,9};

int main(void){
    cout<<purchasePlans(vec,10);
}
