/*
 * @Description: PAT A 1077
 * @Author: Marcel
 * @Date: 2021-03-29 20:10:21
 */

#include <iostream>
#include <vector>
#include <string>

using namespace std;
int N;
string temp;
vector<string>vec;
int min_size=256;

int main(void){
    cin>>N;
    cin.clear();
    cin.ignore();
    for(int i=0;i<N;i++){
        getline(cin,temp);
        int a=temp.size();
        if(a<min_size) min_size=a;
        vec.push_back(temp);
    }

    string res="";
    bool flag=true;
    for(int i=1;i<=min_size;i++){
        char ttt=vec[0][vec[0].length()-i];
        for(int j=0;j<vec.size();j++){
            if(vec[j][vec[j].length()-i]!=ttt){
                flag=false;
                break;
            }
        }
        if(flag)res=ttt+res;
        else break;
    }
    if(res=="")cout<<"nai";
    else cout<<res;

    
   
}

