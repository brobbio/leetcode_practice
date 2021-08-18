using namespace std;

#include<stdio.h>
#include<vector>
#include<iostream>
#include<tuple>
#include<algorithm>
#include<map>
#include<set>
#include<stack>

void presolucion(string tiles,  char actual,  map<char, int> restantes, int& contador){
    std::map<char, int>::iterator it = restantes.begin();
    bool isLeaf = true;
    restantes[actual]--;
    contador++;
    while(it != restantes.end()){
        if((it->second)>0){
            presolucion(tiles,  it->first,  restantes, contador);
            isLeaf = false;
        }
        it++;
    }
    if(isLeaf){
        return;
    }
    // return contador;
}

int numTilePossibilities(string tiles) {
    map<char, int> counter;
    set<char> keys;
    int res = 0;
    int contador = 0;
    for(char e: tiles){
        counter[e] = counter[e] + 1;
        keys.insert(e);
    }
    // presolucion(tiles,  '',  counter, contador);
    for(char e: keys){
        // counter[e]--;
        presolucion(tiles, e, counter, contador);
        // res = res + con;
        // counter[e]++;
    }
    return contador;
}


/*
            A              B              C
          / |            / |            / | 
         B  C           A  C           A  B
         |  |           |  |           |  |
         C  B           C  A           B  A
*/

int main(){
string prueba = "x";
int res = numTilePossibilities(prueba);
cout<<res<<endl;
return 0;}