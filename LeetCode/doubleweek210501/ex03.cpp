/*
 * @Description: 说明
 * @Author: Marcel
 * @Date: 2021-05-01 22:59:48
 */

#include <iostream>
#include <vector>
#include <string>
#include<algorithm>

using namespace std;

int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
    sort(arr.begin(),arr.end());
    vector<long>dp;
    for(int i=0;i<arr.size();i++){
        if(i==0)dp.push_back(arr[i]);
        else if(arr[i]==dp[i-1])dp.push_back(dp[i-1]);
        else dp.push_back(dp[i-1]+1);
    }
    if(dp[0]==1)return dp.back();
    else return dp.back()-dp[0]+1;
}

int main(void){
    vector<int>vec={73,98,9};
    cout<<maximumElementAfterDecrementingAndRearranging(vec);
}
