/*
 * @Description: PAT A 1112 unfinished 16/20 被卡了两个测试点不晓得啥情况，回来再查
 * @Author: Marcel
 * @Date: 2021-03-29 20:36:31
 */

#include <iostream>
#include <vector>
#include <string>
#include<unordered_map>
#include<vector>

using namespace std;

int k;
unordered_map<char,int>tab;
vector<char>base;
string input;

int main(void){
    cin>>k;
    cin>>input;
    char tmp=input[0];
    int count=1;
    for(int i=1;i<input.size();i++){
        if(input[i]==tmp){
            count++;
        }else{
            if(count>=k){
                base.push_back(tmp);
                tab[tmp]=1;
                tmp=input[i];
                count=1;
            }else{
                tab[tmp]=0;
                tmp=input[i];
                count=1;
            }
        }
    }
    if(count>=k){
        base.push_back(tmp);
        tab[tmp]=1;
    }else{
        tab[tmp]=0;
    }

    string res="";
    
    count=0;
    for(int i=0;i<input.size();i++){
        if(count==0){
            if(tab[input[i]]==0){
                res+=input[i];
            }else{
                tmp=input[i];
                count++;
            }
        }else{
            if(tab[input[i]]==0){
                int step=(count%(k-1)>0)?count%(k-1):(k-1);
                while(step-->0){
                    res+=tmp;
                }
                count=0;
                res+=input[i];
            }else if(input[i]==tmp){
                count++;
            }else{
                int step=(count%(k-1)>0)?count%(k-1):(k-1);
                while(step-->0){
                    res+=tmp;
                }
                tmp=input[i];
                count=1;
            }
        }
    }
    if(count!=0){
        int step=(count%(k-1)>0)?count%(k-1):(k-1);
                while(step-->0){
                    res+=tmp;
                }
    }
    string res0="";
    for(int i=0;i<base.size();i++){
        if(tab[base[i]]==1){
            if(res0.find(base[i])==-1)
                res0+=base[i];
        }
    }
    cout<<res0;
    cout<<"\n"<<res;


}

