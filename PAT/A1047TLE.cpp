/*
 * @Description: PAT A 1047  unfinished TLE
 * @Author: Marcel
 * @Date: 2021-03-26 14:04:00
 */

/*最后一个测试点超时了，据说把set<string>改成set<int>可以优化速度，回到学校试试*/

#include <iostream>
#include <set>
#include <string>
#include<unordered_map>

using namespace std;

int N,K,each_course_num,temp_course_id;
string stu_name;
unordered_map<int,set<string>>tab;

int main(void){
   ios::sync_with_stdio(false);
   cin>>N>>K;
   for(int i=0;i<N;i++){
       cin>>stu_name>>each_course_num;
       for(int j=0;j<each_course_num;j++){
           cin>>temp_course_id;
           tab[temp_course_id].insert(stu_name);
       }
   }
   /*
   unordered_map<int,set<string>>::iterator it;
   for(it=tab.begin();it!=tab.end();it++){
       cout<<it->first<<" "<<it->second.size()<<"\n";
       set<string>::iterator its;
       for(its=it->second.begin();its!=it->second.end();its++){
           cout<<*(its)<<"\n";
       }
   }*/
    for(int i=1;i<=K;i++){
        cout<<i<<" "<<tab[i].size()<<"\n";
        set<string>::iterator its;
       for(its=tab[i].begin();its!=tab[i].end();its++){
           cout<<*(its)<<"\n";
       }
    }

}

