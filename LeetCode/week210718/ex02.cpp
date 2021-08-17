/*
 * @Description: 说明
 * @Author: Marcel
 * @Date: 2021-07-18 10:36:30
 */

#include <iostream>
#include <vector>
#include <string>
#include<algorithm>

using namespace std;

class Solution {
public:
    int addRungs(vector<int>& rungs, int dist) {
        int res=0;
        int cur=0;
        int idx=0;
        while(idx<rungs.size()){
            if(rungs[idx]-cur<=dist){
                cur=max(rungs[idx],cur);
                idx++;
            }else{
                int tar=rungs[idx]-cur;
                int pre=res;
                res+=tar/dist-1;
                if((tar+dist)%dist!=0)res++;
                cur+=(res-pre)*dist;
            }
        }
        return res;
    }
};

int main(void){
    Solution* s = new Solution();
    vector<int>vec={1,3,5,10};
    int a=2;
    cout<<s->addRungs(vec,a);
}
