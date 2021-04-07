/*
 * @Description: PAT A1022
 * @Author: Marcel
 * @Date: 2021-03-29 17:12:24
 */
#include <iostream>
#include <vector>
#include <string>
#include<unordered_map>
#include<algorithm>

using namespace std;

int N,M;
unordered_map<string,vector<string>>book2id;
unordered_map<string,vector<string>>author2id;
unordered_map<string,vector<string>>key2id;
unordered_map<string,vector<string>>publish2id;
unordered_map<int,vector<string>>year2id;

string temp_id;
string temp_book,temp_author,temp_key,temp_publish;
string input,in_id,in_query;
int temp_year;
vector<string> query_res;

int main(void){
    ios::sync_with_stdio(false);
    cin>>N;
    for(int i=0;i<N;i++){
        cin>>temp_id;
        cin.clear();
        cin.ignore();
        getline(cin,temp_book);
        book2id[temp_book].push_back(temp_id);
        getline(cin,temp_author);
        author2id[temp_author].push_back(temp_id);
        getline(cin,temp_key);
        string temp="";
        for(int j=0;j<temp_key.size();j++){
            if(temp_key[j]==' '){
                key2id[temp].push_back(temp_id);
                temp="";
            }else if(j==temp_key.size()-1){
                temp+=temp_key[j];
                key2id[temp].push_back(temp_id);
                temp="";
            }
            else{
                temp+=temp_key[j];
            }
        }
        getline(cin,temp_publish);
        publish2id[temp_publish].push_back(temp_id);
        cin>>temp_year;
        year2id[temp_year].push_back(temp_id);
    }

    cin>>M;
        cin.clear();
        cin.ignore();
    for(int i=0;i<M;i++){
        getline(cin,input);
        in_id=input.substr(0,1);
        in_query=input.substr(3);
        if(in_id=="1") query_res=book2id[in_query];
        else if(in_id=="2") query_res=author2id[in_query];
        else if(in_id=="3") query_res=key2id[in_query];
        else if(in_id=="4") query_res=publish2id[in_query];
        else if(in_id=="5") query_res=year2id[stoi(in_query)];

        cout<<input<<"\n";
        if(query_res.empty()){
            cout<<"Not Found\n";
        }else{
            sort(query_res.begin(),query_res.end());
            for(int j=0;j<query_res.size();j++){
                cout<<query_res[j]<<"\n";
            }
        }
    }

}

