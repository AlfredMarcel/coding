/*
 * @Description: 说明
 * @Author: Marcel
 * @Date: 2021-06-21 15:36:55
 */

#include<iostream>
using namespace std;

const int N=14;
int dp[N][N];
int n;

int main(){
	ios::sync_with_stdio(false);
	cin.tie();
	
	cin>>n;
	int ll,rr;
	
	for(int j=1;j<=10;j++){
		for(int i=1;i<=10;i++){
			if(i>1&&i<10)dp[i][j]=dp[i-1][j-1]+dp[i+1][j-1]+2;
			else if(i==1)dp[i][j]=dp[i+1][j-1]+1;
			else if(i==10)dp[i][j]=dp[i-1][j-1]+1;
		}
	}
	string sl,sr;
	for(int i=0;i<n;i++){
		cin>>sl>>sr;
		int li=sl.back()-'0'+1;
		int lj=sl.size();
		int ri=sr.back()-'0'+1;
		int rj=sr.size();
		int sum=0;
	}
	
}