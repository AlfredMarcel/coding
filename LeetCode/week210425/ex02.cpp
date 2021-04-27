/*
 * @Description: 说明
 * @Author: Marcel
 * @Date: 2021-04-25 10:27:59
 */

#include <iostream>
#include <vector>
#include <string>
#include<algorithm>

using namespace std;

int findmin(vector<int>& nums){
    int res=1000000;
    int index=-1;
    for(int i=0;i<nums.size();i++){
        if(nums[i]<res){
            res=nums[i];
            index=i;
        }
    }
    return index;
}

int maxFrequency(vector<int>& nums, int k) {
    int res=1;
    sort(nums.begin(),nums.end());
    vector<int>tmp;
    for(int i=1;i<nums.size();i++){
        tmp.push_back(nums[i]-nums[i-1]);
    }
    int min_d=findmin(tmp);
    while(k>=tmp[min_d]){
        if(min_d==-1)return nums.size();
        for(int i=0;i<min_d;i++){
            tmp[i]+=tmp[min_d];
        }
        k-=tmp[min_d];
        tmp.erase(tmp.begin()+min_d);
        res++;
        min_d=findmin(tmp);
        if(min_d==-1)return nums.size();
    }
    return res;
}

int main(void){
    vector<int>vec={1,2,4};
    cout<<maxFrequency(vec,5);
}
