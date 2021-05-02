/*
 * @Description: 说明
 * @Author: Marcel
 * @Date: 2021-05-02 18:58:06
 */

#include <iostream>
#include <vector>
#include <string>
#include<algorithm>

using namespace std;

int leastBricks(vector<vector<int>>& wall) {
    int level=wall.size();
    vector<int>tab(20010,0);
    for(int i=0;i<wall.size();i++){
        for(int j=0;j<wall[i].size()-1;j++){
            if(j!=0)wall[i][j]+=wall[i][j-1];
            tab[wall[i][j]]++;
        }
    }
    sort(tab.begin(),tab.end());
    return level-tab.front();
}

int main(void){
    
}
