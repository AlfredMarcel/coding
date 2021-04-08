/*
 * @Description: 说明
 * @Author: Marcel
 * @Date: 2021-04-08 23:18:50
 */
#include <iostream>
#include <vector>
#include <string>
#include<stack>

using namespace std;

bool isValidSerialization(string preorder) {

    stack<int>nodes;
    bool flag_root=false;

    vector<string>vec;
    string tmp="";
    for(int i=0;i<preorder.size();i++){
        
        if(preorder[i]==','){
            vec.push_back(tmp);
            tmp="";
        }else{
            tmp+=preorder[i];
        }
    }
    vec.push_back(tmp);

    for(int i=0;i<vec.size();i++){
        if(nodes.empty()){
            if(flag_root)return false;
            if(vec[i]=="#"){
                if(preorder.size()==1)return true;
                return false;
            }
            nodes.push(0);
            flag_root=true;
        }
        else{
            nodes.top()++;
            if(nodes.top()==2)nodes.pop();
            if(vec[i]!="#")nodes.push(0);
        }
        
    }
    if(nodes.empty())return true;
    return false;


}

int main(void){
    cout<<isValidSerialization("9,3,4,#,#,1,#,#,2,#,6,#,#");
}
