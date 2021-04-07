/*
 * @Description: 说明
 * @Author: Marcel
 * @Date: 2021-03-26 13:23:04
 */

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include<algorithm>


using namespace std;

int N,K;
int course_index,stu_num;
string temp_name;
unordered_map<string,vector<int> >map;

int main(void){
    ios::sync_with_stdio(false);
   cin>>N>>K;
   for(int i=1;i<=K;i++){
       cin>>course_index>>stu_num;
       for(int j=0;j<stu_num;j++){
            cin>>temp_name;
            map[temp_name].push_back(course_index);
       }
   }
   for(int i=0;i<N;i++){
       cin>>temp_name;
       sort(map[temp_name].begin(),map[temp_name].end());
       string res;
       res=temp_name+" "+to_string(map[temp_name].size());
       for(int j =0;j<map[temp_name].size();j++){
           res+=" "+to_string(map[temp_name][j]);
       }
       cout<<res<<"\n";
   }


}
