/*
 * @Description: 快排，模板
 * @Author: Marcel
 * @Date: 2021-04-22 21:21:01
 */

#include <iostream>
#include <vector>
#include <string>
#include<algorithm>

using namespace std;

int N;
int box[100010];

void quick_sort(int *box,int l,int r){
    if(l>=r)return;
    int i=l-1;
    int j=r+1;
    /*枢轴取中间元素靠谱一点*/
    int mid=(l+r)/2;
    int pilot=box[mid];    
    while(i<j){
        do{
            i++;
        }while(box[i]<pilot);
        do{
            j--;
        }while(box[j]>pilot);
        if(i<j)swap(box[i],box[j]);
        else break;
    }
    quick_sort(box,l,j);
    quick_sort(box,j+1,r);
}

int main(void){
    ios::sync_with_stdio(false);
    cin>>N;
    for(int i=0;i<N;i++){
        cin>>box[i];
    }
    sort(box,box+N);
    //quick_sort(box,0,N-1);
    for(int i=0;i<N;i++){
        cout<<box[i]<<" ";
    }

}
