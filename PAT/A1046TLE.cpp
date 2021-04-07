/*
 * @Description: PAT A1046
 * @Author: Marcel
 * @Date: 2021-03-25 14:10:43
 */

#include <iostream>
#include <vector>
#include<algorithm>
#include<string>

using namespace std;

int N,M;
int total_length=0;
vector<int>vec;

int main(void){
   cin>>N;
   int temp;
   for(int i=0;i<N;i++){
       cin>>temp;
       vec.push_back(temp);
       total_length+=temp;
   }

   cin>>M;
   int index1,index2,l1,l2,temp_res;
   for(int i=0;i<M;i++){
        temp_res=0;
        cin>>index1>>index2;
        l1=min(index1,index2);
        l2=max(index1,index2);
        /*优化一下, 但还是超时*/
        if(l2-l1>N/2){
            for(int j=0;j<l1-1;j++){
                temp_res+=vec[j];
            }
            for(int j=l2-1;j<N;j++){
                temp_res+=vec[j];
            }
        }else{
            for(int j=l1-1;j<l2-1;j++){
                temp_res+=vec[j];
        }
        }
        
        temp_res=min(temp_res,total_length-temp_res); 
        cout<<to_string(temp_res)+"\n";
        
   }
    //cout<<res.substr(0,res.length()-1);
}
