/*
 * @Description: PAT A 1054
 * @Author: Marcel
 * @Date: 2021-03-26 13:04:30
 */

#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

unordered_map<int ,int>map;
int M,N,temp;
int threshold;

int main(void){
    scanf("%d %d",&M,&N);
    threshold=(M*N)/2+1;
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            scanf("%d",&temp);
            map[temp]++;
            if(map[temp]==threshold){
                cout<<temp;
                return 0;
            }
        }
    }
}

