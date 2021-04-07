#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

struct Student
{
    string name;
    string sex;
    string id;
    int grade;

    Student(string name,string sex,string id,int grade){
        this->name=name;
        this->sex=sex;
        this->id=id;
        this->grade=grade;
    }
    
    Student(){

    }
};

vector<Student>male;
vector<Student>female;

int N,temp4;
string temp1,temp2,temp3;

bool cmp1(Student &a,Student &b){
    return a.grade>b.grade;
}

bool cmp2(Student &a,Student &b){
    return a.grade<b.grade;
}

int main(){
    cin>>N;
    for(int i=0;i<N;i++){
        cin>>temp1>>temp2>>temp3>>temp4;
        if(temp2=="M"){
            male.push_back(Student(temp1,temp2,temp3,temp4));
        }else{
            female.push_back(Student(temp1,temp2,temp3,temp4));
        }
    }

    sort(female.begin(),female.end(),cmp1);
    sort(male.begin(),male.end(),cmp2);

    bool flag=true;
    Student temp;

    if(female.size()==0){
        cout<<"Absent"<<"\n";
        flag=false;
    }else{
        temp=female[0];
        cout<<temp.name<<" "<<temp.id<<"\n";
    }

    if(male.size()==0){
        cout<<"Absent"<<"\n";
        flag=false;
    }else{
        temp=male[0];
        cout<<temp.name<<" "<<temp.id<<"\n";
    }


    if(flag){
        cout<<female[0].grade-male[0].grade;
    }else{
        cout<<"NA";
    }

}