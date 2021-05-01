/*
 * @Description: 说明
 * @Author: Marcel
 * @Date: 2021-05-01 10:38:15
 */

#include <iostream>
#include <vector>
#include <string>
#include<unordered_map>

using namespace std;

class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};

void dfs(unordered_map<int,Employee*>& tab,int id,int & sum){
    sum+=tab[id]->importance;
    if(tab[id]->subordinates.empty())return;
    for(int i=0;i<tab[id]->subordinates.size();i++){
        dfs(tab,tab[id]->subordinates[i],sum);
    }
}

int getImportance(vector<Employee*> employees, int id) {
    unordered_map<int,Employee*>tab;
    for(int i=0;i<employees.size();i++){
        tab[employees[i]->id]=employees[i];
    }
    int sum=0;
    dfs(tab,id,sum);
    return sum;
}

int main(void){


}
