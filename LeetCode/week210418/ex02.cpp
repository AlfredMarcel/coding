/*
 * @Description: 说明
 * @Author: Marcel
 * @Date: 2021-04-18 10:29:25
 */

#include <iostream>
#include <vector>
#include <string>
#include<algorithm>

using namespace std;

int maxIceCream(vector<int>& costs, int coins) {
    sort(costs.begin(),costs.end());
    int res=0;
    for(int i=0;i<costs.size();i++){
        if(coins<costs[i])return res;
        coins-=costs[i];
        res++;
    }
    return res;
}

int main(void){
    
}
