/*
 * @Description: 说明
 * @Author: Marcel
 * @Date: 2021-04-04 13:32:52
 */

#include <iostream>
#include <vector>
#include <string>
#include<unordered_map>
#include<set>

using namespace std;

vector<int> findingUsersActiveMinutes(vector<vector<int>>& logs, int k) {
    unordered_map<int,set<int>>tab;
    for(int i=0;i<logs.size();i++){
        tab[logs[i][0]].insert(logs[i][1]);
    }
    vector<int>res(k);
    unordered_map<int,set<int>>::iterator it=tab.begin();
    for(;it!=tab.end();it++){
        if((*it).second.size()!=0){
            res[(*it).second.size()-1]++;
        }
    }
    return res;
}

int main(void){
    
    
}

