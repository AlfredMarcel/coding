/*
 * @Description: 说明
 * @Author: Marcel
 * @Date: 2021-04-28 14:55:27
 */
#include <iostream>
#include<vector>
#include<list>
using namespace std;

vector<int>handle(vector<int>tmp){
    if(tmp.size()==1)return tmp;
    vector<int>res;
    res.push_back(tmp.front());
    res.push_back(tmp.back());
    return res;
}

int main() {
    //int a;
    //cin >> a;
    vector<int>vec={1,2,3,5,6,9,10,11,12,13,20};
    vector<vector<int>>res;
    vector<int>tmp;
    for(int i=0;i<vec.size();i++){
        if(tmp.empty()||tmp.back()==vec[i]-1)tmp.push_back(vec[i]);
        else{
            res.push_back(handle(tmp));
            tmp.clear();
            tmp.push_back(vec[i]);
        }
    }
    if(!tmp.empty())res.push_back(tmp);
    
}
