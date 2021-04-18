/*
 * @Description: 说明
 * @Author: Marcel
 * @Date: 2021-04-18 15:43:09
 */

#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<int>in;
vector<int>des;
int num=0;

void r_change(int index){
    for(int i=index+1;i<in.size();i++){
        if(i==index+1){
            if(in[i]==0){
                r_change(i);
            }
        }else{
            if(in[i]==1){
                r_change(i);
            }
        }
    }
    in[index]=(in[index]+1)%2;
    num++;
}

int main(void){
    string input,target;
    cin>>input>>target;
    
    
    for(int i=0;i<input.size();i++){
        in.push_back(input[i]-'0');
        des.push_back(target[i]-'0');
    }

    int length=in.size();

    for(int i=0;i<length;i++){
        if(in[i]!=des[i]){
            r_change(i);
        }
    }

    cout<<num;
}
