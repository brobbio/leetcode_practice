using namespace std;

#include<stdio.h>
#include<vector>
#include<iostream>
#include<tuple>
#include<algorithm>
#include<map>
#include<set>
#include<stack>

//UNFINISHED

vector<vector<string>> agregarCuenta(vector<vector<string>> accounts, vector<string> account){
    bool repetido = false;
    for(vector<string>& prev: accounts){
        if(prev[0]==account[0]){
            for(int i = 1;i<account.size();i++){
                if(count(prev.begin()+1,prev.end(),account[i])){
                    prev.insert(prev.end(), account.begin()+1, account.end());
                    set<string> s(prev.begin(), prev.end());
                    prev.assign(s.begin(),s.end());
                    std::sort(prev.begin()+1,prev.end());
                    repetido = true;
                }
            }
        }
    }
    if(!repetido){
        string nombre = account.front();
        set<string> s(account.begin()+1, account.end());
        account.assign(s.begin(), s.end());
        account.insert(account.begin(), nombre);
        std::sort(account.begin()+1,account.end());
        accounts.push_back(account);
    }
    return accounts;
}



vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
    if(accounts.size()==0){
        return {};
    }else{
        vector<string> back = accounts.back(); 
        accounts.pop_back();
        vector<vector<string>> nuevaCuenta = accountsMerge(accounts);
        return agregarCuenta(nuevaCuenta, back);
    }
    
    return accounts;
}


int main(){
vector<vector<string>> prueba = {{"David","David0@m.co","David1@m.co"},{"David","David3@m.co","David4@m.co"},{"David","David4@m.co","David5@m.co"},{"David","David2@m.co","David3@m.co"},{"David","David1@m.co","David2@m.co"}};
vector<vector<string>> res = accountsMerge(prueba);
/*     int res = partition(prueba, 4); */
    for(vector<string> e : res){
        for(string j: e){
            cout<<j<<endl;
        }

}
/* cout<<res; */
return 0;}