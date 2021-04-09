/*
 * @Description: 24点,回溯法
 * @Author: Marcel
 * @Date: 2021-04-09 12:17:03
 */

#include <iostream>
#include <vector>
#include <string>
#include<cmath>

using namespace std;

bool solve(vector<double>& nums){
    double eps=1e-6;

    if(nums.size()==1){
        if(abs(nums[0]-24)<eps)return true;
        return false;
    }

    for(int i=0;i<nums.size();i++){
        for(int j=0;j<nums.size();j++){
            if(j!=i){
                vector<double>tmp;
                for(int k=0;k<nums.size();k++){
                    if(k!=i&&k!=j)tmp.push_back(nums[k]);
                }
                for(int k=0;k<4;k++){
                    if(k==0)tmp.push_back(nums[i]+nums[j]);
                    if(k==1)tmp.push_back(nums[i]-nums[j]);
                    if(k==2)tmp.push_back(nums[i]*nums[j]);
                    if(k==3){
                        if(abs(nums[j])<eps)continue;
                        tmp.push_back(nums[i]/nums[j]);
                    }
                    if(solve(tmp))return true;
                    tmp.pop_back();
                }
            }
        }
    }
    return false;
}

bool judgePoint24(vector<int>& nums) {
    
    vector<double>dnums;
    for(int i=0;i<nums.size();i++){
        dnums.push_back(nums[i]*1.0);
    }
    
    return solve(dnums);
}

int main(void){
    vector<int>vec={6,8,6,4};
    cout<<judgePoint24(vec);
}
