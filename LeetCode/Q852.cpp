/*
 * @Description: 说明
 * @Author: Marcel
 * @Date: 2021-06-15 13:19:14
 */

#include <iostream>
#include <vector>
#include <string>
#include<algorithm>

using namespace std;

int head(vector<int>& arr,int l,int r){
    int mid=(l+r)>>1;
    if(l==r)return l;
    else{
        if(arr[mid]>=arr[l]&&arr[mid]<=arr[r])return head(arr,mid+1,r);
        if(arr[mid]<=arr[l]&&arr[mid]>=arr[r])return head(arr,l,mid);
        else{
            int res1=head(arr,mid,r);
            int res2=head(arr,l,mid);
            if(arr[res1]>arr[res2])return res1;
            else return res2;
        }
    }
}

int peakIndexInMountainArray(vector<int>& arr) {
    return head(arr,0,arr.size()-1);
}

int main(void){
    

}
