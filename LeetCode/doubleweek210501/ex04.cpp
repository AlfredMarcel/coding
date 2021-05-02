/*
 * @Description: TLE
 * @Author: Marcel
 * @Date: 2021-05-01 23:25:58
 */

#include <iostream>
#include <vector>
#include <string>
#include<unordered_map>
#include<algorithm>

using namespace std;

vector<int> closestRoom(vector<vector<int>>& rooms, vector<vector<int>>& queries) {
    vector<int>res={};
    unordered_map<int,int>room_table;
    int mm=10000000;
    int mx=-1;
    for(int i=0;i<rooms.size();i++){
        room_table[rooms[i][0]]=rooms[i][1];
        mm=min(mm,rooms[i][0]);
        mx=max(mx,rooms[i][0]);
    }
    for(int i=0;i<queries.size();i++){
        int target=queries[i][0];
        int size=queries[i][1];
        int count=0;
        bool flag=false;
        if(target>mx)target=mx;
        if(target<mm)target=mm;
        while(target-count>=mm||target+count<=mx){
            if(room_table.find(target-count)!=room_table.end()){
                if(room_table[target-count]>=size){
                res.push_back(target-count);
                flag=true;
                break;
                }
            }
            if(room_table.find(target+count)!=room_table.end()){
                if(room_table[target+count]>=size){
                res.push_back(target+count);
                flag=true;
                break;
                }
            }
            count++;
        }
        if(!flag)res.push_back(-1);
    }
    return res;
}

int main(void){
    
}
