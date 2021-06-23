/*
 * @Description: 错解
 * @Author: Marcel
 * @Date: 2021-06-24 00:10:37
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
    vector<line>vec;
    unordered_map<int,int>tab;

public:
    int maxPoints(vector<vector<int>>& points) {
        for(int i=0;i<points.size();i++){
            int x=points[i][0],y=points[i][1];
            int length=vec.size();
            int idx=0;
            for(int j=0;j<length;j++){
                //空点
                if(vec[j].k==111111){
                    //斜率不存在
                    if(x==vec[j].x)vec[j].k=999999;
                    else vec[j].k=(y-vec[j].y)/(x-vec[j].x);
                    tab[j]++;
                }
                //一条线
                else{
                    if(vec[j].k==999999){
                        if(x==vec[j].x){
                            tab[j]++;
                        }else{
                            //新增一条线
                            double tmp_k=(y-vec[j].y)/(x-vec[j].x);
                            vec.push_back({vec[j].x,vec[j].y,tmp_k});
                            tab[length+idx++]=2;
                        }
                    }else{
                        if(x!=vec[j].x){
                            if(abs(vec[j].k-(y-vec[j].y)/(x-vec[j].x))<eps){
                                tab[j]++;
                            }else{
                                //新增一条线
                                double tmp_k=(y-vec[j].y)/(x-vec[j].x);
                                vec.push_back({vec[j].x,vec[j].y,tmp_k});
                                tab[length+idx++]=2;
                            }
                        }else{
                            double tmp_k=999999;
                            vec.push_back({vec[j].x,vec[j].y,tmp_k});
                            tab[length+idx++]=2;
                        }           
                    }
                }
            }
            //增加空点
            double tmp_k=111111;
            vec.push_back({x,y,tmp_k});
            tab[length+idx++]=1;
        }
        int res=0;
        for(auto p=tab.begin();p!=tab.end();p++){
            res=max(res,p->second);
        }
        return res;
    }
};

int main(void){
    Solution* s =new Solution();

}
