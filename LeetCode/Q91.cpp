/*
 * @Description: 没有考虑可能的重复情况，错误
 * @Author: Marcel
 * @Date: 2021-04-21 13:56:03
 */

#include <iostream>
#include <vector>
#include <string>

using namespace std;

int r_count(string s){
    int left=0;
    int right=s.size()-1;
    if(right==left){
        if(s=="0")return 0;
        return 1;
    }
    else if(right-left==1){
        if(s[left]=='0')return 0;
        else if(s[left]=='1'){
            if(s[right]=='0')return 1;
            return 2;
        }else if(s[left]=='2'){
            if(s[right]!='0'&&s[right]<='6')return 2;
            return 1;
        }else{
            if(s[right]=='0')return 0;
            return 1;
        }
    }
    else if(right-left==2){
        int mid=(left+right)/2;
        int tmp=r_count(s.substr(0,mid))*r_count(s.substr(mid))+
                r_count(s.substr(0,mid+1))*r_count(s.substr(mid+1));
        if(tmp==4)tmp--;
        return tmp;
    }
    else {
        int mid=(left+right)/2;
        return r_count(s.substr(0,mid))*r_count(s.substr(mid))+
                r_count(s.substr(0,mid+1))*r_count(s.substr(mid+1));
    }
}

int numDecodings(string s) {
    return r_count(s);
}

int main(void){
    cout<<numDecodings("1111");
}
