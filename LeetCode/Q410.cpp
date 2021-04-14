/*
 * @Description: 说明
 * @Author: Marcel
 * @Date: 2021-04-13 15:20:15
 */
#include <iostream>
#include <vector>
#include <string>
#include<numeric>
#include<algorithm>

using namespace std;

int splitArray(vector<int>& nums, int m) {
    int left=0;
    int right=accumulate(nums.begin(),nums.end(),0);
    int res=1e9;


    while(right>=left){
        int mid=(left+right)/2;
        int steps=0;
        int t_sum=1;
        int max=0;
        for(int i=0;i<nums.size();i++){
            if(steps+nums[i]>mid){
                /*mid小于数组中任一元素，说明mid必小，直接往右边二分*/
                if(nums[i]>mid){t_sum=m+1;break;}
                max=(steps>max)?steps:max;
                t_sum++;
                steps=nums[i];
            }else{
                steps+=nums[i];
            }
        }
        if(t_sum>m){
            left=mid+1;
        }
        if(t_sum<m){
            right=mid-1;
        }
        if(t_sum==m){
            res=min(res,mid);
            right=mid-1;
        }
    }
    if(res==1e9){
        int t=0;
        for(int i=0;i<nums.size();i++){
            t=max(t,nums[i]);
        }
        return t;
    }
    return res;
}

vector<int>vec={1,1,1,1,1,3,2};

int main(void){
    cout<<splitArray(vec,5);
}
