/*
 * @Description: 说明
 * @Author: Marcel
 * @Date: 2021-04-06 21:36:59
 */
#include <iostream>
#include <vector>
#include <string>
#include<stack>

using namespace std;

string simplifyPath(string path) {
    stack<string>folders;
    string folder="";
    bool flag=true;
    for(int i=0;i<path.size();i++){
        if(path[i]=='/'&&folder==""){
            flag=true;
            continue;
        }else if(path[i]=='/'){
            if(folder==".."){
                if(folders.empty()==false)folders.pop();
            }else if(folder=="."){
            }else{
                folders.push(folder);
            }
            folder="";
        }else{
            folder+=path[i];
        }
    }
    if(folder!=""){
        if(folder==".."){
            if(folders.empty()==false)folders.pop();
            }else if(folder=="."){
            }else{
                folders.push(folder);
            }
    }

    string res="";
    while(folders.empty()==false){
        res="/"+folders.top()+res;
        folders.pop();
    }
    if(res=="")res="/";
    return res;
}

int main(void){
    cout<<simplifyPath("/../");
}
