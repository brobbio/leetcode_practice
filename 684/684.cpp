using namespace std;

#include<stdio.h>
#include<vector>
#include<iostream>
#include<tuple>


bool isConnected(vector<vector<int>> edges, int cantNodos){
    int n = cantNodos;
    vector<int> componentes(n,0);
    int contador = 1;
    for(vector<int> e: edges){
        if(componentes[e[0]-1] == 0 && componentes[e[1]-1] == 0){
            contador++;
            componentes[e[0]-1] = contador;
            componentes[e[1]-1] = contador;
        }else{
            int comp_1 = componentes[e[0]-1];
            int comp_2 = componentes[e[1]-1];
            if(comp_1 != 0 && comp_2 != 0){
                if(comp_1 != comp_2){
                    for(int k = 0;k<n;k++){
                        if(componentes[k]==comp_1 || componentes[k]==comp_2){
                            int nueva_componente = max(comp_1, comp_2);
                            componentes[k]=nueva_componente;
                        }
                    }
                }
            }else{
                if(comp_1 != 0){
                    componentes[e[1]-1] = comp_1;
                }else{ componentes[e[0]-1] = comp_2;}
            }
        }
    }
    bool res = componentes == std::vector<int>(n, componentes[0]);
    return res;
}

vector<int> findRedundantConnection(vector<vector<int>>& edges) {
    int n = edges.size()-1;
    int cantNodos = 1;
    for(vector<int> e: edges){
        for(int k: e){
            if(k>cantNodos){cantNodos = k;}
        }
    }
    vector<int> res;
    while(n>=0){
        res = edges[n];
        edges.erase(edges.begin() + n);
        if(isConnected(edges, cantNodos)){
            n = 0;
        }else{
            edges.insert(edges.begin() + n, res);
        }
        n--;
    }
    return res;
}



int main(){
    vector<vector<int>> prueba = {{16,25},{7,9},{3,24},{10,20},{15,24},{2,8},{19,21},{2,15},{13,20},{5,21},{7,11},{6,23},{7,16},{1,8},{17,20},{4,19},{11,22},{5,11},{1,16},{14,20},{1,4},{22,23},{12,20},{15,18},{12,16}};
    /* vector<int> */ bool res = isConnected(prueba, 25);
/*     cout<<"[";
    for(auto& e: res){
        if(&e - &res[0] == res.size()-1){
            cout<<e;
        }else{
            cout<<e<<", ";
        }
    }
    cout<<"]"<<endl; */
    cout<<res<<endl;

return 0;}