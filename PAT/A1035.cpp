/*
 * @Description: PAT A1035
 * @Author: Marcel
 * @Date: 2021-03-29 19:40:14
 */ 

#include <iostream>
#include <vector>
#include <string>
#include<unordered_map>

using namespace std;

int N;
vector<string>vec_key,vec_value;
string name,temp1,temp2;
char tmp;

int main(void){
    ios::sync_with_stdio(false);
    cin>>N;
    for(int i=0;i<N;i++){
        cin>>name>>temp1;
        bool flag=false;
        temp2="";
        for(int j=0;j<temp1.size();j++){
            tmp=temp1[j];
            if(tmp=='1'){temp2+='@';flag=true;}
            else if(tmp=='0'){temp2+='%';flag=true;}
            else if(tmp=='l'){temp2+='L';flag=true;}
            else if(tmp=='O'){temp2+='o';flag=true;}
            else temp2+=tmp;   
        }
        if(flag){
            vec_key.push_back(name);
            vec_value.push_back(temp2);
        }
    }
    if(vec_key.empty()){
        if(N==1)cout<<"There is 1 account and no account is modified";
        else cout<<"There are "<<N<<" accounts and no account is modified";
    }else{
        cout<<vec_key.size()<<"\n";
        for(int i=0;i<vec_key.size();i++){
            cout<<vec_key[i]<<" "<<vec_value[i]<<"\n";
        }
    }
   
}
