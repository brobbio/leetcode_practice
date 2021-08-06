using namespace std;

#include<stdio.h>
#include<vector>
#include<iostream>
#include<tuple>
#include<algorithm>
#include<map>
#include<set>
#include<stack>

void marcarIslas(vector<vector<char>>& grid, int pos1, int pos2){
    if(pos1<0 || pos2<0 || pos1>grid.size()-1 || pos2>grid[0].size()-1 || grid[pos1][pos2]=='0'){
        return;
    }else{
        if(grid[pos1][pos2] == '2'){
            return;
        }
        grid[pos1][pos2] = '2';
        marcarIslas(grid, pos1+1,pos2);
        marcarIslas(grid, pos1-1,pos2);
        marcarIslas(grid, pos1,pos2+1);
        marcarIslas(grid, pos1, pos2-1);
    }
}

int numIslands(vector<vector<char>>& grid){
    int cantIslas = 0;
    for(int i = 0; i<grid.size(); i++){
        for(int j= 0; j<grid[0].size();j++){
            if(grid[i][j]=='1'){
                cantIslas++;
                marcarIslas(grid, i, j);
            }
        }
    }
    return cantIslas;
}

int main(){
    vector<vector<char>> prueba = {{'1','1','1','1','0'},{'1','1','0','1','0'},{'1','1','0','0','0'},{'0','0','0','0','0'}};
    int res = numIslands(prueba);
    cout<< res;
return 0;}