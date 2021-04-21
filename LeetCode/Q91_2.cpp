/*
 * @Description: 说明
 * @Author: Marcel
 * @Date: 2021-04-21 14:42:28
 */

#include <iostream>
#include <vector>
#include <string>

using namespace std;

int numDecodings(string s) {
    vector<int>dp={0};
    for(int i=0;i<s.size();i++){
        if(s[i]=='0'){
            if(i==0){
                dp.push_back(0);
            }else{
                if(s[i-1]=='1'||s[i-1]=='2'){
                    if(i!=1)dp.push_back(dp[i-1]);
                    else dp.push_back(1);
                }else{
                    dp.push_back(0);
                }
            }
        }else{
            if(i==0){
                dp.push_back(1);
            }else{
                if((s[i-1]=='1'&&s[i]>'0'&&s[i]<='9')||(s[i-1]=='2'&&s[i]>'0'&&s[i]<='6')){
                    if(i!=1)dp.push_back(dp[i]+dp[i-1]);
                    else dp.push_back(dp[i]+1);
                }else{
                    dp.push_back(dp[i]);
                }
            }
        }
    }
    return dp.back();
}

int main(void){
    cout<<numDecodings("2611055971756562");
}
