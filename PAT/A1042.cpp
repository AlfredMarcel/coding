/*
 * @Description: PAT A1042
 * @Author: Marcel
 * @Date: 2021-03-24 20:11:28
 */

#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<string>mould={"S","H","C","D"};
vector<string>raw_vec;
vector<int>method;
int K;

int main(void){
    cin>>K;
    for(int l=0;l<mould.size();l++){
        for(int i=1;i<14;i++){
            raw_vec.push_back(mould[l]+to_string(i));
        }
    }
    raw_vec.push_back("J1");
    raw_vec.push_back("J2");
    
    for(int i=0;i<54;i++){
        int index;
        cin>>index;
        method.push_back(index);
    }

    for(int i=0;i<K;i++){
        vector<string>temp(54,"");
        for(int j=0;j<54;j++){
            temp[method[j]-1]=raw_vec[j];
        }
        raw_vec=temp;
    }
    string res;
    for(int i=0;i<raw_vec.size();i++){
        res+=raw_vec[i]+" ";
    }
    cout<<res.substr(0,res.length()-1);

}


