using namespace std;

#include<stdio.h>
#include<vector>
#include<iostream>
#include<tuple>
#include<algorithm>
#include<map>
#include<set>
#include<stack>

int sumOfDigits(int n){
    int res = 0;
    while(n!=0){
        int r = n % 10;
        res = res + r;
        n = (n-r)/10;
    }
    return res;
}

int countLargestGroup(int n) {
    std::vector<int> res(4*10, 0);
    int final_res=0;
    int max = 0;
    for(int i = 1; i<=n; i++){
        int x = sumOfDigits(i);
        res[x-1] = res[x-1]+1;
        if(res[x-1]>max){
            max = res[x-1];
        }
    }
    for(int e: res){
        if(e == max){
            final_res = final_res + 1;
        }
    }
    return final_res;
}

int main(){
int prueba = 13;
int res = countLargestGroup(prueba);
cout << res <<endl;
return 0;}