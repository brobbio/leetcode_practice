using namespace std;

#include<stdio.h>
#include<vector>
#include<iostream>
#include<tuple>
#include<algorithm>
#include<map>
#include<set>
#include<stack>

int DFS(vector<vector<int>>& times, set<int> visitados, int n, int k, int tiempo, int ejes_usados){
    visitados.insert(k);
    int ninguno_empieza_con_k = true;
    int max_tiempo = tiempo;
    int mejor_nodo;
    for(vector<int> nodo: times){
        if(nodo[0]==k){
            ninguno_empieza_con_k = false;
            ejes_usados = ejes_usados + 1;
            if(!visitados.count(nodo[1])){
                int nuevo_tiempo = DFS(times, visitados, n, nodo[1], tiempo + nodo[2], ejes_usados);
                if(nuevo_tiempo < max_tiempo){
                    max_tiempo = nuevo_tiempo;
                    mejor_nodo = nodo[1];
                }
            }
        }
    }
    if(ejes_usados == times.size()){
        if(visitados.size()==n){
            return max_tiempo;
        }else{
            return -1;
        }
    }else{
        if(ninguno_empieza_con_k){
            return max_tiempo;
        }else{
            return DFS(times, visitados, n, mejor_nodo, max_tiempo, ejes_usados);
        }
    }
}

int networkDelayTime(vector<vector<int>>& times, int n, int k) {
    set<int> visitados;
    int tiempo = 0;
    int ejes_usados = 0;
    int res = DFS(times, visitados, n, k, tiempo, ejes_usados);
    if(visitados.size() == n){
        return res;
    }else{
        return -1;
    }
}

int main(){
    vector<vector<int>> times = {{1,2,1},{2,3,2},{1,3,2}};
    int res = networkDelayTime(times, 3, 1);
    cout << res <<endl; 
return 0;}