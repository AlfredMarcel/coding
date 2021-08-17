/*
 * @Description: 说明
 * @Author: Marcel
 * @Date: 2021-07-04 12:18:44
 */

#include <iostream>
#include <vector>
#include <string>
#include<map>
#include<unordered_map>
#include<algorithm>

using namespace std;

struct line{
    char c;
    int num;
};

bool cmp(line &a,line &b){
    return a.num>=b.num;
}

class Solution {
    unordered_map<char,int>tab;
public:
    string frequencySort(string s) {
        for(char c :s){
            tab[c]++;
        }
        vector<line>tmp;
        for(auto p=tab.begin();p!=tab.end();p++){
            tmp.push_back({p->first,p->second});
        }
        sort(tmp.begin(),tmp.end(),cmp);
        string res;
        for(line t:tmp){
            string tt;
            for(int i=0;i<t.num;i++)tt+=t.c;
            res+=tt;
        }
        return res;

    }
};

int main(void){
    
}
