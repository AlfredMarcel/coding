/*
 * @Description: 说明
 * @Author: Marcel
 * @Date: 2021-07-04 12:37:37
 */

#include <iostream>
#include <vector>
#include <string>
#include<algorithm>

using namespace std;


class Solution {

public:
    int maxIceCream(vector<int>& costs, int coins) {
        sort(costs.begin(),costs.end());
        int res=0;
        for(int i:costs){
            if(i<=coins){
                res++;
                coins-=i;
            }else{
                break;
            }
        }
        return res;
    }
};

int main(void){
    
}
