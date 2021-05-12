/*
 * @Description: 说明
 * @Author: Marcel
 * @Date: 2021-05-10 20:11:21
 */

#include <iostream>
#include <vector>
#include <string>
#include<unordered_set>
#include<algorithm>

using namespace std;

int n;
int q[100010];

int main(void){
    ios::sync_with_stdio(false);
    cin>>n;
    for(int i=0;i<n;i++)cin>>q[i];

    unordered_set<int>tab;

    int res=0;
    int i=0,j=0;
    for(;i<n;i++){
        while(j<i&&tab.find(q[i])!=tab.end()){
            res=max(res,i-j);
            tab.erase(q[j]);
            j++;
        }
        tab.insert(q[i]);
    }
    res=max(res,i-j);
    cout<<res;
}
