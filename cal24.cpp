/*
 * @Description: 24点计算
 * @Author: Marcel
 * @Date: 2021-04-17 16:41:57
 */


#include <iostream>
#include <vector>
#include <string>
#include<algorithm>

using namespace std;

double eps=1e-6;


void dfs(vector<string>& res,vector<double>& input,vector<string> tmp_res){
    if(input.size()==1){
        if(abs(input[0]-24)<eps){
            res.push_back(tmp_res[0]);
        }
        return;
    }
    for(int i=0;i<input.size();i++){
        for(int j=i;j<input.size();j++){
            if(j!=i){
                vector<double>next_val;
                vector<string>next_s;
                for(int k=0;k<input.size();k++){
                    if(k!=i&&k!=j){
                        next_val.push_back(input[k]);
                        next_s.push_back(tmp_res[k]);
                    }
                }
                //加减乘除
                for(int k=0;k<4;k++){
                    if(k==0){
                        next_val.push_back(input[i]+input[j]);
                        next_s.push_back("("+tmp_res[i]+"+"+tmp_res[j]+")");
                        dfs(res,next_val,next_s);
                    }
                    if(k==1){
                        next_val.push_back(input[i]-input[j]);
                        next_s.push_back("("+tmp_res[i]+"-"+tmp_res[j]+")");
                        dfs(res,next_val,next_s);
                    }
                    if(k==2){
                        next_val.push_back(input[i]*input[j]);
                        next_s.push_back(tmp_res[i]+"*"+tmp_res[j]);
                        dfs(res,next_val,next_s);
                    }
                    //判断除数是否为0
                    if(k==3){
                        if(abs(input[j])>eps){
                            next_val.push_back(input[i]/input[j]);
                            next_s.push_back(tmp_res[i]+"/"+tmp_res[j]);
                            dfs(res,next_val,next_s);
                        }
                    }
                    if(!next_val.empty())next_val.pop_back();
                    if(!next_s.empty())next_s.pop_back();
                }
            }   
        }
    }
}

int main(void){
    cout<<"请输入空格分隔的4个数字，用于计算\n";
    vector<double>input;
    double tmp;
    for(int i=0;i<4;i++){
        cin>>tmp;
        input.push_back(tmp);
    }
    vector<string>res;
    vector<string>tmp_res;
    for(int i=0;i<4;i++){
        tmp_res.push_back(to_string((int)input[i]));
    }
    dfs(res,input,tmp_res);
    if(res.empty())cout<<"该序列无解。";
    for(int i=0;i<res.size();i++){
        cout<<res[i]<<"\n";
    }

}

