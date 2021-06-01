/*
 * @Description: 说明
 * @Author: Marcel
 * @Date: 2021-06-01 11:47:40
 */

#include <iostream>
#include <vector>
#include <string>
#include<algorithm>

using namespace std;

vector<bool> canEat(vector<int>& candiesCount, vector<vector<int>>& queries) {
    
    int max_eat,min_eat;
    vector<bool>res;
    for(int i=1;i<candiesCount.size();i++){
        candiesCount[i]+=candiesCount[i-1];
    }
    for(int i=0;i<queries.size();i++){
        max_eat=(queries[i][1]+1)*queries[i][2];
        min_eat=queries[i][1]+1;
        if(max_eat<=candiesCount[queries[i][0]]){
            if(queries[i][0]==0){
                res.push_back(true);
                continue;
            }else{
                res.push_back(max_eat>candiesCount[queries[i][0]-1]);
                continue;
            }
        }else{
            res.push_back(min_eat<=candiesCount[queries[i][0]]);
            continue;
        }
    }
    return res;
}

int main(void){
    
}
