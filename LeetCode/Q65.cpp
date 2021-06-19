/*
 * @Description: 说明
 * @Author: Marcel
 * @Date: 2021-06-17 19:06:01
 */

#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool isDigit(string s){
    if(s.size()==0)return false;
    bool res=true;
    int cnt=0;
    for(int i=0;i<s.size();i++){
        if(s[i]>='0'&&s[i]<='9'){
            cnt++;
        }else{
            if((s[i]=='+'||s[i]=='-')&&i==0)continue;
            else return false;
        }
    }
    if(cnt>0)return true;
    else return false;
}

bool isPart(string s){
    if(s.size()==0)return true;
    bool res=true;
    int cnt=0;
    for(int i=0;i<s.size();i++){
        if(s[i]>='0'&&s[i]<='9'){
            cnt++;
        }else{
            return false;
        }
    }
    if(cnt>0)return true;
    else return false;
}

bool isFloat(string s){
    if(s.size()==0)return false;
    if(s[0]=='+'||s[0]=='-')s=s.substr(1,s.size()-1);
    int poi_idx=-1;
    for(int i=0;i<s.size();i++){
        if(s[i]=='.'){
            poi_idx=i;
            break;
        }
    }
    string lft=s.substr(0,poi_idx);
    string rit=s.substr(poi_idx+1);
    if(lft.size()==0&&rit.size()==0)return false;
    return isPart(lft)&&isPart(rit);
}

bool isNumber(string s) {
    int idx=0;
    for(int i=0;i<s.size();i++){
        if(s[i]=='e'||s[i]=='E'){
            string s1=s.substr(0,i);
            //e是最后一个？
            string s2=s.substr(i+1);
            return (isFloat(s1)||isDigit(s1))&&isDigit(s2);
        }
    }
    return isFloat(s)||isDigit(s);
}

int main(void){
    string tmp;
    cin>>tmp;
    cout<<isNumber(tmp);
}
