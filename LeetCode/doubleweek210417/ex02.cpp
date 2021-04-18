/*
 * @Description: 说明
 * @Author: Marcel
 * @Date: 2021-04-17 22:27:54
 */

#include <iostream>
#include <vector>
#include <string>
#include<algorithm>

using namespace std;

double eps=1e-6;

int count(vector<int>& query,vector<vector<int>>& points){
    int sum=0;
    for(int i=0;i<points.size();i++){
        double a=pow(query[0]-points[i][0],2);
        double b=pow(query[1]-points[i][1],2);
        double c=pow(query[2],2);
        if(a+b<c||abs(a+b-c)<eps){
            sum++;
        }
    }
    return sum;
}

vector<int> countPoints(vector<vector<int>>& points, vector<vector<int>>& queries) {
    vector<int>res={};
    for(int i=0;i<queries.size();i++){
        res.push_back(count(queries[i],points));
    }
    return res;
}

int main(void){
    
}
