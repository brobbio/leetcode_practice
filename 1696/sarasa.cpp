using namespace std;

#include<stdio.h>
#include<vector>
#include<iostream>
#include<tuple>

int main(){
	vector<int> hola = {1,2,3,4,5};
	vector<int> otro = std::vector<int>(hola.begin()+5,hola.end());
	for(int e: otro){
		cout<<e<<endl;
	}
return 0;}
