/*
 * @Description: 说明
 * @Author: Marcel
 * @Date: 2021-06-24 01:43:01
 */

#include <iostream>
#include <vector>
#include <string>
#include<unordered_map>
#include<algorithm>

using namespace std;

struct line{
    int x,y;
    double k;
};

class Solution {

    const double eps=1e-6;
    vector<line>lines;
    unordered_map<int,int>tab;

public:
    int maxPoints(vector<vector<int>>& points) {
        for(int i=0;i<points.size();i++){
            int x=points[i][0],y=points[i][1];     
            //判断新点是否在某条线上
            for(int j=0;j<lines.size();j++){
                if(lines[j].k==999999){
                    if(x==lines[j].x){
                        tab[j]++;
                    }
                }else{
                    if(abs((y-lines[j].y)-lines[j].k*(x-lines[j].x))<eps){
                        tab[j]++;
                    }
                }
            }
            int idx=0,length=lines.size();
            //以新点为右端点添加线
            for(int j=i-1;j>=0;j--){
                double tmp_k;
                if(points[j][0]==points[i][0])tmp_k=999999;
                else tmp_k=((points[j][1]*1.0-points[i][1])/(points[j][0]-points[i][0]));
                lines.push_back({points[j][0],points[j][1],tmp_k});
                tab[length+idx++]=2;
            }
        }
        int res=1;
        for(auto p=tab.begin();p!=tab.end();p++){
            res=max(res,p->second);
        }
        return res;
    }
};

int main(void){
    Solution* s=new Solution();
    vector<vector<int>>vec={{-6,-1},{3,1},{12,3}};
    cout<<s->maxPoints(vec);
}
