/*
 * @Description: 说明
 * @Author: Marcel
 * @Date: 2021-04-04 13:43:24
 */

#include <iostream>
#include <vector>
#include <string>
#include<algorithm>

using namespace std;

int minAbsoluteSumDiff(vector<int>& nums1, vector<int>& nums2) {
    vector<int> tmp_res(nums1.size());
    int temp_max=0;
    int max_index=-1;
    for(int i=0;i<nums1.size();i++){
        int tmp=max(nums1[i],nums2[i])-min(nums1[i],nums2[i]);
        if(tmp>temp_max){
            temp_max=tmp;
            max_index=i;
        }
        tmp_res[i]=tmp;
    }
    if(max_index==-1){return 0;}

    int min_num=tmp_res[max_index];
    int min_index=-1;
    for(int i=0;i<nums1.size();i++){
        int tmp=max(nums1[i],nums2[max_index])-min(nums1[i],nums2[max_index]);
        if(tmp<min_num){
            min_index=i;
            min_num=tmp;
        }
    }
    tmp_res[max_index]=min_num;

    int sum=0;
    for(int i=0;i<tmp_res.size();i++){
        sum+=tmp_res[i];
        sum%=1000000007;
    }
    return sum;

}

vector<int>a={1,7,5};
vector<int>b={2,3,5};

int main(void){
    minAbsoluteSumDiff(a,b);
    
}
