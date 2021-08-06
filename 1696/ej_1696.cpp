using namespace std;

#include<stdio.h>
#include<vector>
#include<iostream>
#include<tuple>
/*     int maxResult(vector<int>& nums, int k){
        int i = 0;
        int score = 0;
        while(i<nums.size()){
            score = score + nums[i];
                if(i == nums.size()-1){
                    i = i +1;
                }else{
                    if(nums[i+1]>=0){
                        i = i+1;
                    }else{
                        int j = 1;
                        int prox = 1;
                        int max = nums[i+1];
                        while(j<=k){
                            if(nums[i+j]>0){
                                prox = j;
                                j = k+1;
                            }else{
                                if(nums[i+j]>=max){
                                    max = nums[i+j];
                                    prox = j;
                                }
                            }
                            if(i+j == nums.size()-1){
                                prox = j;
                                j = k+1;
                            }else{
                                j = j+1;
                            }
                        }
                i = i + prox;
            }
        }
        }
        return score;
    } */


/* 
    int backtracking(vector<int>& nums, vector<int> solucionParcial, int i, int k){
        int m = nums.size();
        int mejorValor = -1000;
        if(i==m-1){
            int suma = 0;
            for(int e: solucionParcial){
                suma = suma + e;
            }
            if(suma>mejorValor){
                mejorValor = suma;
                vector<int> mejorSolucion = solucionParcial;
            }
        }else{
            int j = 1;
            while(j<=k){
                if(nums[i+j]>0){
                    solucionParcial.push_back(nums[i+j]);
                    return backtracking(nums, solucionParcial,i+j, k);
                }
                if(i+j==m-1){
                    j = k+1;
                }else{
                    j++;
                }
            } 
            j = 1; 
            while(j<=k){
                solucionParcial.push_back(nums[i+j]);
                int posible = backtracking(nums, solucionParcial, i+j, k);
                if(posible>mejorValor){
                    mejorValor = posible;
                }
                solucionParcial.pop_back();
                if(i+j==m-1){
                    j = k+1;
                }else{
                    j++;
                }
            }
        }
        return mejorValor;
    } */


    tuple<int,int> maxResultado(vector<int> nums, int k){
        int m = nums.size();
        if(m==1){
            return make_pair(nums.back(), nums.back()); 
        }else{
            vector<tuple<int,int>> res(min(k,m-1));
            for(int j = 1;j<=min(k,m-1);j++){
                tuple<int,int> res_nesimo = maxResultado(std::vector<int>(nums.begin()+j, nums.end()), k);
                res[j-1] = res_nesimo;
            }
            vector<int> caminos;
            vector<int> caminos_raiz;
            for(int r = 0; r<min(k,m-1);r++){
                caminos.push_back(std::get<0>(res[r]));
                caminos_raiz.push_back(std::get<1>(res[r]));
            }
            int maximo = caminos[0];
            int suma = *(nums.begin());
            for(int h = 0; h<min(k,m-1); h++){
                if(caminos[h]>maximo){
                    maximo = caminos[h];
                }
                suma = suma + caminos_raiz[h];
            }
            int nuevo = max(maximo, suma);


            int caminoDesdeRaiz = *(nums.begin());
            for(int p = 0; p<min(k,m-1); p++){
                if(std::get<1>(res[p]) + *(nums.begin())>caminoDesdeRaiz){
                    caminoDesdeRaiz = std::get<1>(res[p])+*(nums.begin());
                }
            }
            return make_pair(nuevo, caminoDesdeRaiz);
        }
    }

    int maxResult(vector<int>& nums, int k){
        return std::get<1>(maxResultado(nums, k));
    }

/*     int maxResult(vector<int>& nums, int k){
        int m = nums.size();
        if(nums.size()<=k+1){
            int max = nums.back()+nums.front();
            for(int e: std::vector<int>(nums.begin(), nums.end()-1)){
                if(e + nums.back()>max){
                    max = e+nums.back();
                }
            }
            return max;
        }else{
            vector<int> paso = std::vector<int>(nums.begin()+m-1-k, nums.end());
            int finall = maxResult(paso, k);
            nums.resize(nums.size()-k-1);
            nums.push_back(finall);
            return maxResult(nums, k);
        }
    } */
    

int main(){
	vector<int> prueba = {-7622,4131,7439,-2974,-2663,-669,-4494,-9654,8200,-1423,1012,-5399,7978,5597,4156,1269,5752,6413,7845,6468,-2708,-2582,-2473,-1141,2225,4970,1907,-4156,1547,515,-6515,-7948,4723,7159,-208,-9331,2182,2163,4143,-6634,-1341,1365,-3940,1654,-7759,3755,-8914,-2074,-2196,-6471,-1181,-4348,-3286,-8133,-9962,-8414,-2065,-6902,-6140,-4236,2119,9175,6304,-2371,-1397,-6207,-2068,245,8186,-4801,-9801,523,-8516,-8535};
    int res;
    if(prueba.back()<0){
        res = maxResult(prueba, 2)+prueba.back();
    }else{
	    res = maxResult(prueba, 2);
    }
	cout<<res<<endl;
return 0;}
