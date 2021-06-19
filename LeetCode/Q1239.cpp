/*
 * @Description: 说明
 * @Author: Marcel
 * @Date: 2021-06-19 00:13:48
 */

#include <iostream>
#include <vector>
#include <string>
#include<set>
#include<algorithm>

using namespace std;

void dfs(vector<string>& arr,set<char>& box,int & res,string tmp,int idx){
    for(int i=idx;i<arr.size();i++){
        bool flag=true;
        for(int j=0;j<arr[i].size();j++){
            if(box.find(arr[i][j])!=box.end()){
                flag=false;
                break;
            }
        }
        if(flag){
            for(int j=0;j<arr[i].size();j++)box.insert(arr[i][j]);
            dfs(arr,box,res,tmp+arr[i],idx+1);
            for(int j=0;j<arr[i].size();j++)box.erase(arr[i][j]);
        }
    }
    res=max(res,(int)tmp.size());
}

int maxLength(vector<string>& arr) {
    set<char>box;
    int res=0;
    dfs(arr,box,res,"",0);
    return res;
}

int main(void){
    vector<string>vec={"a","b","c","d","e","f","g","h","i","j","k","l","m","n"};
    cout<<maxLength(vec);
}
