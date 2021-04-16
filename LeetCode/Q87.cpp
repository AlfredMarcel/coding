/*
 * @Description: 暴力枚举可能结果，直接超时
 * @Author: Marcel
 * @Date: 2021-04-16 12:27:13
 */
#include <iostream>
#include <vector>
#include <string>
#include<unordered_set>

using namespace std;

unordered_set<string> r_create(string s1){
    unordered_set<string> tmp;
    if(s1.size()==1){
        tmp.insert(s1);
        return tmp;
    }
    for(int i=1;i<s1.size();i++){
        unordered_set<string>left=r_create(s1.substr(0,i));
        unordered_set<string>right=r_create(s1.substr(i));
        unordered_set<string>::iterator it1=left.begin();
        unordered_set<string>::iterator it2=right.begin();
        while(it1!=left.end()){
            it2=right.begin();
            while(it2!=right.end()){
                tmp.insert((*it1)+(*it2));
                tmp.insert((*it2)+(*it1));
                it2++;
            }
            it1++;
        }
    }
    return tmp;
}

bool isScramble(string s1, string s2) {
    bool flag=false;
    if(s1.size()==1)return true;
    unordered_set<string>tmp=r_create(s1);
    cout<<tmp.size();
    if(tmp.find(s2)!=tmp.end())flag=true;
    return flag;
}

int main(void){
    isScramble("abcdefghijklmnopq","abcdefghijklmnopq");
}
