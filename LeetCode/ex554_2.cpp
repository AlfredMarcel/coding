/*
 * @Description: 说明
 * @Author: Marcel
 * @Date: 2021-05-02 19:34:57
 */

#include <iostream>
#include <vector>
#include <string>
#include<algorithm>
#include<unordered_map>

using namespace std;

int leastBricks(vector<vector<int>>& wall) {
    unordered_map<long long,int>tab;
    for(int i=0;i<wall.size();i++){
        long long pre;
        for(int j=0;j<wall[i].size()-1;j++){
            if(j==0)pre=(long long)wall[i][j];
            else pre+=wall[i][j];
            tab[pre]++;
        }
    }    
    int res=0;
    unordered_map<long long ,int>::iterator it=tab.begin();
    for(;it!=tab.end();it++){
        if(it->second>res)res=it->second;
    }
    return wall.size()-res;
}

int main(void){
    
}
