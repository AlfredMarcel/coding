/*
 * @Description: 说明
 * @Author: Marcel
 * @Date: 2021-04-18 14:46:40
 */

#include <iostream>
#include <vector>
#include <string>

using namespace std;

int num;
vector<int>input;
int tmp;

int main(void){
    int max_num=0;
    int max_index=0;
    cin>>num;
    for(int i=0;i<num;i++){
        cin>>tmp;
        input.push_back(tmp);
    }
    int sum;
    for(int i=4;i<num;i++){
        sum=input[i-4]+input[i-3]+input[i-2]+input[i-1]+input[i];
        if(sum>max_num){
            max_num=sum;
            max_index=i;
        }
    }
    cout<<max_index-3<<" "<<max_index+1<<" "<<max_num;
}
