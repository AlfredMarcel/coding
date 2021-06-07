/*
 * @Description: 说明
 * @Author: Marcel
 * @Date: 2021-06-03 18:17:07
 */

#include <iostream>
#include <vector>
#include <string>
#include<algorithm>
#include<map>
#include<algorithm>

using namespace std;

int findMaxLength(vector<int>& nums) {
    vector<int>pre=vector<int>(nums.size()+1,0);
    for(int i=0;i<nums.size();i++){
        if(nums[i]==1)pre[i+1]=pre[i]+1;
        else pre[i+1]=pre[i]-1;
    }

    int res=0;
    unordered_map<int,int> tab;
    for(int i=0;i<pre.size();i++){
        if(tab.find(pre[i])!=tab.end()){
            res=max(res,i-tab[pre[i]]);
        }
        tab[pre[i]]=i;
    }
    return res;

}

int main(void){
    
}
