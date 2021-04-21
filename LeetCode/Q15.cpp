/*
 * @Description: 不仅有逻辑错，还超时
 * @Author: Marcel
 * @Date: 2021-04-20 12:53:40
 */

#include <iostream>
#include <vector>
#include <string>
#include<algorithm>
#include<map>

using namespace std;

vector<vector<int>>resv;
map<vector<int>,int>tab;

void r_search(vector<int>nums){
    if(nums.size()<3)return;
    int l=0;
    int r=nums.size()-1;
    int target=0-nums[l]-nums[r];
    int ll=l+1;
    int rr=r-1;
    int res=-1;
    while(rr>=ll){
        int mid=(ll+rr)/2;
        if(nums[mid]==target){
            res=mid;
            break;
        }else if(target<mid){
            rr=mid-1;
        }else{
            ll=mid+1;
        }
    }
    if(res==-1){
        r_search(vector<int>(nums.begin()+1,nums.end()));
        r_search(vector<int>(nums.begin(),nums.end()-1));
    }else{
        vector<int>tmp;
        tmp.push_back(nums[l]);
        tmp.push_back(target);
        tmp.push_back(nums[r]);
        if(tab.find(tmp)==tab.end()){
            resv.push_back(tmp);
            tab[tmp]=1;
        }
        r_search(vector<int>(nums.begin()+1,nums.end()));
        r_search(vector<int>(nums.begin(),nums.end()-1));
    }
}

vector<vector<int>> threeSum(vector<int>& nums) {
    sort(nums.begin(),nums.end());
    r_search(nums);
    return resv;
}

int main(void){
    vector<int>a={-2,0,1,1,2};
    threeSum(a);
}
