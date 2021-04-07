/*
 * @Description: PAT A 1140
 * @Author: Marcel
 * @Date: 2021-03-29 19:20:21
 */

#include <iostream>
#include <vector>
#include <string>

using namespace std;

string input;
int N;


string handle(string &ss){
    string res="";
    if(ss.size()==1){
        return ss+"1";
    }else{
        char temp=ss[0];
        int count=1;
        for(int i=1;i<ss.size();i++){
            if(ss[i]==temp)count++;
            else{
                res+=temp+to_string(count);
                temp=ss[i];
                count=1;
            }
        }
        res+=temp+to_string(count);
        return res;
    }
}

int main(void){
    ios::sync_with_stdio(false);
    cin>>input>>N;
    for(int i=0;i<N-1;i++){
        input=handle(input);
    }
    cout<<input;
}

