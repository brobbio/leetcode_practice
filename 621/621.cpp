using namespace std;

#include<stdio.h>
#include<vector>
#include<iostream>
#include<tuple>
#include<algorithm>
#include<map>
#include<set>
#include<stack>

int leastInterval(vector<char>& tasks, int n) {
    int posiciones_minimas = 0;
    map<char, int> contar;
    for(char e: tasks){
        contar[e] = contar[e]+1;
    }
    for(char task: tasks){
        char actual = task;
        if(contar[actual]>0){
            bool agotado = true;
            int orden = int(actual);
            contar[actual] = contar[actual]-1;
            posiciones_minimas = posiciones_minimas+1;
            int cooldown_left = n;
            int i = 0;
            while(i<n){
                int j = 1;
                while(j<(26-(orden-int('A')))&&(i<n)){
                    if(contar[char(actual+j)]>0){
                        contar[char(actual+j)] = contar[char(actual+j)]-1;
                        posiciones_minimas = posiciones_minimas+1;
                        cooldown_left = cooldown_left-1;
                        i++;
                        agotado = agotado && (contar[char(actual+j)]==0);
                    }
                    j++;
                }
                i = n;
            }
            if(!(agotado && (contar[actual]==0))){
                posiciones_minimas = cooldown_left + posiciones_minimas;
            }
        }
    }
    return posiciones_minimas;
}

int main(){
vector<char> prueba = {'A','A','A','B','B','B', 'C','C','C', 'D', 'D', 'E'};
int res = leastInterval(prueba, 2);
cout << res <<endl; 
return 0;}