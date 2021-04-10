/*
 * @Description: 说明
 * @Author: Marcel
 * @Date: 2021-04-09 20:32:45
 */

#include <iostream>
#include <vector>
#include <string>

using namespace std;



/*两边子树的可能状态数的乘积，递推计算*/
int numTrees(int n,vector<long>& vec) {
    if(vec[n]!=0)return vec[n];
    else{
        if(n==0)return 1;
        else {
            int num=0;
            for(int i=0;i<n;i++){
                num+=numTrees(i,vec)*numTrees(n-1-i,vec);
            }
        vec[n]=num;
        return num;
        }
    }
}
int main(void){
    vector<long>vec(50,0);
    for(int i=0;i<20;i++){
        numTrees(i,vec);
    }
    cout<<vec[19];
}
