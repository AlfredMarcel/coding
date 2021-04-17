/*
 * @Description: 说明
 * @Author: Marcel
 * @Date: 2021-04-17 10:49:41
 */

#include <iostream>
#include <vector>
#include <string>
#include<unordered_map>

using namespace std;

/*
bool containsNearbyDuplicate(vector<int>& nums, int k) {
    for(int i=0;i<nums.size();i++){
        for(int j=i+1;j<nums.size();j++){
            if(j-i>k)break;
            if(nums[i]==nums[j])return true;
        }
    }
    return false;
}
*/

unordered_map<int,int>tab;

bool containsNearbyDuplicate(vector<int>& nums, int k){
    for(int i=0;i<nums.size();i++){
        if(tab.find(nums[i])==tab.end()){
            tab[nums[i]]=i;
        }else{
            if(i-tab[nums[i]]<=k)return true;
            tab[nums[i]]=i;
        }
    }
    return false;
}


int main(void){
    
}
