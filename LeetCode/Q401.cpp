/*
 * @Description: 说明
 * @Author: Marcel
 * @Date: 2021-06-21 12:21:00
 */

#include <iostream>
#include <vector>
#include <string>
#include<cstring>

using namespace std;

/*
 * @Description: 说明
 * @Author: Marcel
 * @Date: 2021-06-21 12:21:00
 */
class Solution {

    vector<int>hour={1,2,4,8};
    vector<int>minute={1,2,4,8,16,32};
    bool hh[10];
    bool mm[10];
    vector<string>res={};
    vector<int>sum_hour={};
    vector<int>sum_minute={};

public:

    void dfs1(int num,int sum){
        if(num>4)return dfs1(num-1,sum);
        if(num==0){
            sum_hour.push_back(sum);
            return;
        }else{
            for(int i=0;i<hour.size();i++){
                if(!hh[i]){
                    hh[i]=true;
                    if(sum+hour[i]<=11)dfs1(num-1,sum+hour[i]);
                    hh[i]=false;
                }
            }
        }
    }

    void dfs2(int num,int sum){
        if(num>6)return dfs2(num-1,sum);
        if(num==0){
            sum_minute.push_back(sum);
            return;
        }else{
            for(int i=0;i<minute.size();i++){
                if(!mm[i]){
                    mm[i]=true;
                    if(sum+minute[i]<=59)dfs2(num-1,sum+minute[i]);
                    mm[i]=false;
                }
            }
        }
    }

    vector<string> readBinaryWatch(int turnedOn) {
        for(int i=0;i<=turnedOn;i++){
            int j=turnedOn-i;
            memset(hh,0,sizeof hh);
            memset(mm,0,sizeof mm);
            dfs1(i,0);
            dfs2(j,0);
            for(int i=0;i<sum_hour.size();i++){
            for(int j=0;j<sum_minute.size();j++){
                string s1=to_string(sum_hour[i]);
                string s2=to_string(sum_minute[j]);
                if(sum_minute[j]<10)s2="0"+s2;
                res.push_back(s1+":"+s2);
                }
            }
            sum_hour.clear();
            sum_minute.clear();
        }
        return res;
    }
};

int main(void){
    Solution* obj=new Solution();
    vector<string>res=obj->readBinaryWatch(1);
    for(int i=0;i<res.size();i++)cout<<res[i]<<"\n";
}
