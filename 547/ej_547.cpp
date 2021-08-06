using namespace std;

#include<stdio.h>
#include<vector>
#include<iostream>
#include<tuple>

void transitividad(vector<vector<int>>& matriz, int indice){
    int n = matriz.size();
    bool hayQueSeguir = true;
    while(hayQueSeguir){
        hayQueSeguir = false;
        for(int j = 0;j<n;j++){
            if(j!=indice){
                if(matriz[indice][j]==1){
                    for(int k = 0;k<n;k++){
                        int nuevo = max(matriz[indice][k], matriz[j][k]);
                        if(matriz[indice][k] != nuevo){
                            hayQueSeguir = true;
                            matriz[indice][k] = nuevo;
                        }
                    }
                }
            }
        }
    }
}

int findCircleNum(vector<vector<int>>& isConnected) {
    int n = isConnected[0].size();
    int tot = n;
    vector<int> res = std::vector<int>(n, 1);
    for(int i = 0;i<n;i++){
        transitividad(isConnected, i);
        if(isConnected[i]==std::vector<int>(n, 1)){return 1;}
    }
    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
                if(i!=j){
                    if(isConnected[i][j]==1){
                        if(res[j]==1){
                            tot = tot - 1;
                            res[j]=0;
                            res[i]=0;
                        }    
                    }
                }
        }
    }
    return tot;
}

int main(){
	vector<vector<int>> prueba = {{1,0,0,1},{0,1,1,0},{0,1,1,0},{1,0,0,1}};
    int res = findCircleNum(prueba);
    int n = prueba.size();
 /*    cout<<"[";
    for(int i = 0; i<n;i++){
        cout<<"[";
            for(int k = 0; k<n;k++){
                if(k<n-1){
                    cout<< res[i][k] << ",";
                }else{
                    cout<< res[i][k];
                }
            }
        if(i <n-1){
            cout << "],"<<endl;
        }else{
            cout<< "]";
        }
    }
    cout << "]" <<endl; */

    cout << res <<endl;
return 0;}