
#include<iostream>
#include<stdio.h>
#include<string>

#include<string.h>

using namespace std;

int main(){
	int cnt[26]={0,};
	
	string s;
	cin>>s;
	int k = s.length();
	
	for(int i=0; i<k;i++){
		cnt[s[i]-97]++;
	}
	for(int j=0; j<26;j++)
		printf("%d ",cnt[j]);

	
	return 0;
}