/*
 * @Description: 说明
 * @Author: Marcel
 * @Date: 2021-06-06 10:30:30
 */

#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool judge(vector<vector<int>>& a, vector<vector<int>>& b){
    for(int i=0;i<a.size();i++){
        for(int j=0;j<a[i].size();j++){
            if(a[i][j]!=b[i][j])return false;
        }
    }
    return true;
}

bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
    vector<vector<int>> mat1=mat;
    vector<vector<int>> mat2=mat;
    vector<vector<int>> mat3=mat;

    int l=mat.size()-1;
    for(int i=0;i<mat.size();i++){
        for(int j=0;j<mat[i].size();j++){
            mat1[j][l-i]=mat[i][j];
            mat2[l-i][l-j]=mat[i][j];
            mat3[l-j][i]=mat[i][j];
        }
    }

    return judge(mat,target)||judge(mat1,target)||judge(mat2,target)||judge(mat3,target);
}

int main(void){
    
}
