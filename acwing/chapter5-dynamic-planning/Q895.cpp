/*
 * @Description: 最长上升子序列
 * @Author: Marcel
 * @Date: 2021-06-18 13:39:18
 * 状态表示：每个数字结尾的最长上升子序列长度
 */

#include <iostream>
#include <vector>
#include <string>
#include<algorithm>

using namespace std;

const int N=1010;
int box[N];
int dp[N];

int n;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie();

    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>box[i];
    }
    
    for(int i=1;i<=n;i++){
        int tmp_max=0;
        for(int j=i;j>=1;j--){
            if(box[j]<box[i])tmp_max=max(tmp_max,dp[j]);
        }
        dp[i]=tmp_max+1;
    }
    int res=-0x3f3f3f3f;
    for(int i=1;i<=n;i++){
        res=max(res,dp[i]);
    }
    cout<<res;
}

