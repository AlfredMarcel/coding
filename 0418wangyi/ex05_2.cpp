/*
 * @Description: 说明
 * @Author: Marcel
 * @Date: 2021-04-18 16:30:57
 */

#include <iostream>
#include <vector>
#include <string>

using namespace std;

int num=0;
int sum=0;
vector<int>vec;

int main(void){
    cin>>num;
    int tmp;
    for(int i=0;i<num;i++){
        cin>>tmp;
        vec.push_back(tmp);
    }

    while(vec.size()>1){
        vector<int>tt;
        int tmp_min=2147483647;
        int tmp_index=0;
        for(int i=0;i<vec.size()-1;i++){
            int tmp=vec[i]+vec[i+1];
            if(tmp<tmp_min){
                tmp_min=tmp;
                tmp_index=i;
            }
        }
        vec.erase(vec.begin()+tmp_index,vec.begin()+tmp_index+2);
        vec.insert(vec.begin()+tmp_index,tmp_min);
        sum+=tmp_min;
    }
    cout<<sum;

}
