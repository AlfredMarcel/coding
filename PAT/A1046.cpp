/*
 * @Description: PAT A 1046
 * @Author: Marcel
 * @Date: 2021-03-25 14:10:43
 */

#include <iostream>
#include <vector>
#include <string>
#include<algorithm>

using namespace std;

int N,M;
//dis 存放 1到i的顺时针距离,这样计算距离相对减就可以，O1
vector<int>dis;

int main(void){
    int sum=0;
    int temp;
    cin>>N;
    for(int i=0;i<N;i++){
        cin>>temp;
        dis.push_back(sum);
        sum+=temp;
    }

    cin>>M;
    int t1,t2,index1,index2;
    for(int i=0;i<M;i++){
        cin>>t1>>t2;
        if(t1>t2){
            index1=t2;
            index2=t1;
        }else{
            index1=t1;
            index2=t2;
        }
        int temp_res=dis[index2-1]-dis[index1-1];
        cout<<min(temp_res,sum-temp_res)<<"\n";
    }
   
}
