/*
 * @Description: PAT A 1071
 * @Author: Marcel
 * @Date: 2021-03-30 10:23:32
 */

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

string input;
unordered_map<string,int>tab;
string temp_max;
int max_num=0;

bool vaild(char &a){
    if((a>='0'&&a<='9')||(a>='A'&&a<='Z')||(a>='a'&&a<='z'))return true;
    else return false;
}

char modify(char a){
    if(a>='A'&&a<='Z'){
        a+=32;
    }
    return a;
}

int main(void){
    ios::sync_with_stdio(false);
    getline(cin,input);

    string word="";
    for(int i=0;i<input.size();i++){
        if(vaild(input[i])){
            word+=modify(input[i]);
        }else{
            if(word!=""){
                tab[word]+=1;
                if(tab[word]>max_num||(tab[word]==max_num&& word<temp_max)){
                    max_num=tab[word];
                    temp_max=word;
                }
                word="";
            }
        }
    }
    if(word!=""){
                tab[word]+=1;
                if(tab[word]>max_num||(tab[word]==max_num&& word<temp_max)){
                    max_num=tab[word];
                    temp_max=word;
                }
                word="";
            }
    cout<<temp_max<<" "<<max_num;

}
