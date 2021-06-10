/*
 * @Description: 说明
 * @Author: Marcel
 * @Date: 2021-06-10 10:34:55
 */

#include <iostream>
#include <vector>
#include <string>

using namespace std;

int change(int amount, vector<int>& coins) {
    vector<int>dp(amount+1,0);
    dp[0]=1;
    for(int i=0;i<coins.size();i++){
        for(int j=1;j<=amount;j++){
            if(coins[i]<=j){
                dp[j]+=dp[j-coins[i]];
            }
        }
    }
    return dp.back();
}

int main(void){
    int a=5;
    vector<int>vec={1,2,5};
    cout<<change(a,vec);
}
