using namespace std;

#include<stdio.h>
#include<vector>
#include<iostream>
#include<tuple>
#include<algorithm>
#include<map>
#include<set>
#include<stack>

bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int limite_inferior = 0;
    int limite_superior = matrix.size()-1;
    int fila_medio = limite_inferior + (limite_superior - limite_inferior)/2;
    while(limite_inferior!=limite_superior){
        if(limite_superior == limite_inferior +1 ){
            if(matrix[limite_superior][0]<=target){
                limite_inferior = limite_superior;
            }else{
                limite_superior = limite_inferior;
            }
        }else{
            fila_medio = limite_inferior + (limite_superior - limite_inferior)/2;
            if(matrix[fila_medio][0]<=target && matrix[fila_medio+1][0]>target){
                limite_inferior = fila_medio;
                limite_superior = fila_medio;
            }else{
                if(matrix[fila_medio][0]>target){
                    limite_superior = fila_medio-1;
                }
                if(matrix[fila_medio+1][0]<=target){
                    limite_inferior = fila_medio+1;
                }
            }
        }
    }
    fila_medio = limite_inferior;
    int limite_derecho = matrix[0].size()-1;
    int limite_izquierdo = 0;
    int med = limite_izquierdo + (limite_derecho - limite_izquierdo)/2;
    while(limite_derecho!=limite_izquierdo){
        if(limite_derecho == limite_izquierdo +1){
            bool res1 = matrix[fila_medio][limite_izquierdo] == target;
            bool res2 = matrix[fila_medio][limite_derecho] == target;
            return res1 || res2;
        }else{
            int med = limite_izquierdo + (limite_derecho - limite_izquierdo)/2;
            if(matrix[fila_medio][med]==target){
                return true;
            }else{
                if(matrix[fila_medio][med]>target){
                    limite_derecho = med;
                }else{
                    limite_izquierdo = med;
                }
            }
        }
    }
    return matrix[fila_medio][med]==target;
    
    
}

int main(){
    vector<vector<int>> prueba = {{1},{3},{5}};
    int res = searchMatrix(prueba, 3);
    cout<< res;
return 0;}