/*
 * @Description: 说明
 * @Author: Marcel
 * @Date: 2021-08-23 09:27:15
 */

#include <iostream>
#include <vector>
#include <string>
#include<algorithm>

using namespace std;

class Solution {
public:
    int getMaximumGenerated(int n) {
        int res=0;
        vector<int> tmp;
        for(int i=0;i<=n;i++){
            if(i==0)tmp.push_back(0);
            else if(i==1)tmp.push_back(1);
            else if((i+2)%2==0){
                tmp.push_back(tmp[i/2]);
            }else{
                tmp.push_back(tmp[i/2]+tmp[i/2+1]);
            }
            res=max(res,tmp.back());
        }
        return res;
    }
};

int main(void){
    
}
