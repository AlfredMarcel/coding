/*
 * @Description: 说明
 * @Author: Marcel
 * @Date: 2021-07-23 11:15:42
 */

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:

    int st[60];
    int a[60];

    bool isCovered(vector<vector<int>>& ranges, int left, int right) {
        for(int i=0;i<ranges.size();i++){
            a[ranges[i][0]]++;
            a[ranges[i][1]+1]--;
        }
        for(int i=1;i<60;i++)st[i]=a[i]+st[i-1];
        for(int i=left;i<=right;i++){
            if(st[i]==0)return false;
        }
        return true;
    }
};

int main(void){
    
}
