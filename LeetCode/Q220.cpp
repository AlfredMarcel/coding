/*
 * @Description: 滑动窗口
 * @Author: Marcel
 * @Date: 2021-04-17 10:37:14
 */
#include <iostream>
#include <vector>
#include <string>
#include<set>
#include<algorithm>

using namespace std;

bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
    multiset<long>window;
    int left=0;
    for(int i=0;i<nums.size();i++){
        
        auto p=lower_bound(window.begin(),window.end(),(long)(nums[i]-t));
        /*nums[i]-*p<=t,还需要nums[i]-*p>=-t*/
        if(p!=window.end()&&(long)nums[i]-*p>=t*-1){
            return true;
        }
        window.insert(nums[i]);
        if(window.size()>k){
            window.erase(nums[left]);
            left++;
        }
    }
    return false;
}




int main(void){
    vector<int>vec={7,1,3};
    cout<<containsNearbyAlmostDuplicate(vec,2,3);    
}
