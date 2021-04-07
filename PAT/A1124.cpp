#include<iostream>
#include<set>
#include<vector>
#include<string>

using namespace std;

set<string>tab;
vector<string>vec;

int M,N,S;
string temp;
string res;

int main(){
    cin>>M>>N>>S;
    int count=0;
    for(int i=0;i<M;i++){
        cin>>temp;
        count++;
        if(count==S){
            if(tab.find(temp)!=tab.end()){
                count--;
                continue;
            }else{
                tab.insert(temp);
                vec.push_back(temp);
                count-=N;
            }
        }
    }
    if(tab.empty()){
        cout<<"Keep going...";
    }else{
        for(vector<string>::iterator it=vec.begin();it!=vec.end();it++){
            res+=*(it)+"\n";
        }
        cout<<res.substr(0,res.length()-1);
    }

    
}


/*
错的,模1就没有余数了，需要考虑
int main(){
    bool flag=false;
    int fix=0;
    cin>>M>>N>>S;
    for(int i=0;i<M;i++){
        cin>>temp;
        {
            if(flag){
                if(map.count(temp)==1){
                    fix++;
                    continue;
                }else{
                    res+=temp+"\n";
                    map[temp]=1;
                    flag=false;
                }
            }else{
                if((i+1+N-fix)%N==S){
                    if(map.count(temp)==1){
                        flag=true;
                        fix++;
                        continue;
                    }else{
                        res+=temp+"\n";
                        map[temp]=1;
                        flag=false;
                    }
                }
                
            }   
        }
             
    }
    if(res==""){
        cout<<"Keep going...";
    }else{
        cout<<res.substr(0,res.length()-1);
    }
    
}
*/
