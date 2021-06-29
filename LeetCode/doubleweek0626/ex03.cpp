/*
 * @Description: 说明
 * @Author: Marcel
 * @Date: 2021-06-26 22:52:32
 */

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int sum=0;
        int cnt=0;
        int tmp=0;
        for(int i=0;i<nums.size();i++){
            //+
            if((cnt+2)%2==0){
                if(nums[i]>=tmp)tmp=nums[i];
                else{
                    sum+=tmp;
                    cnt++;
                    tmp=nums[i];
                }
            }
            //-
            else{
                if(nums[i]<tmp)tmp=nums[i];
                else{
                    sum-=tmp;
                    cnt++;
                    tmp=nums[i];
                }
            }
        }
        if((cnt+2)%2==0)sum+=tmp;
        return sum;
    }
};

int main(void){
    
}
