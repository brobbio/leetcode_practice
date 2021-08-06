using namespace std;

#include<stdio.h>
#include<vector>
#include<iostream>
#include<tuple>
#include<algorithm>
#include<map>
#include<set>
#include<stack>

    bool esVacio(map<string,multiset<string>> dicc){
        bool res = true;
        map<string, multiset<string>>::iterator it;
        for(it = dicc.begin(); it!=dicc.end(); it++){
            if(!((it->second).empty())){
                res = false;
            }
        }
        return res;
    }
    
    vector<string> findItinerary(vector<vector<string>>& tickets) {
       vector<string> res;
       map<string, multiset<string>> pasajes;
       for(vector<string> e: tickets){
           pasajes[e[0]] = {};
       }
       for(vector<string> e: tickets){
           pasajes[e[0]].insert(e[1]);
       }
       stack<string> S;
       S.push("JFK");
       while(!esVacio(pasajes)){
           string origen = S.top();
           if(!pasajes[origen].empty()){
                S.push(*(pasajes[origen].begin()));
                pasajes[origen].erase((pasajes[origen]).begin());
           }else{
               vector<tuple<string, string>> aAgregar;
               while(pasajes[S.top()].empty()){
                    string destino_recuperado = S.top();
                    S.pop();
                    string inicio_recuperado = S.top();
                    aAgregar.push_back(make_pair(inicio_recuperado, destino_recuperado));
               }
               string nuevo_origen = S.top();
               string nuevo_destino = *(pasajes[nuevo_origen].begin());
               S.push(nuevo_destino);
                pasajes[nuevo_origen].erase((pasajes[nuevo_origen]).begin());
               for(tuple<string,string> e: aAgregar){
                   pasajes[get<0>(e)].insert(get<1>(e));
               }
           }
       }
       while(!S.empty()){
           string x = S.top();
           res.push_back(x);
           S.pop();
       }
       reverse(res.begin(), res.end());
       return res;
    }

    int main(){
	vector<vector<string>> prueba = /* {{"JFK","SFO"},{"JFK","ATL"},{"SFO","ATL"},{"ATL","JFK"},{"ATL","SFO"}} */
     /* {{"AXA","EZE"},{"EZE","AUA"},{"ADL","JFK"},{"ADL","TIA"},{"AUA","AXA"},{"EZE","TIA"},{"EZE","TIA"},{"AXA","EZE"},{"EZE","ADL"},{"ANU","EZE"},{"TIA","EZE"},{"JFK","ADL"},{"AUA","JFK"},{"JFK","EZE"},{"EZE","ANU"},{"ADL","AUA"},{"ANU","AXA"},{"AXA","ADL"},{"AUA","JFK"},{"EZE","ADL"},{"ANU","TIA"},{"AUA","JFK"},{"TIA","JFK"},{"EZE","AUA"},{"AXA","EZE"},{"AUA","ANU"},{"ADL","AXA"},{"EZE","ADL"},{"AUA","ANU"},{"AXA","EZE"},{"TIA","AUA"},{"AXA","EZE"},{"AUA","SYD"},{"ADL","JFK"},{"EZE","AUA"},{"ADL","ANU"},{"AUA","TIA"},{"ADL","EZE"},{"TIA","JFK"},{"AXA","ANU"},{"JFK","AXA"},{"JFK","ADL"},{"ADL","EZE"},{"AXA","TIA"},{"JFK","AUA"},{"ADL","EZE"},{"JFK","ADL"},{"ADL","AXA"},{"TIA","AUA"},{"AXA","JFK"},{"ADL","AUA"},{"TIA","JFK"},{"JFK","ADL"},{"JFK","ADL"},{"ANU","AXA"},{"TIA","AXA"},{"EZE","JFK"},{"EZE","AXA"},{"ADL","TIA"},{"JFK","AUA"},{"TIA","EZE"},{"EZE","ADL"},{"JFK","ANU"},{"TIA","AUA"},{"EZE","ADL"},{"ADL","JFK"},{"ANU","AXA"},{"AUA","AXA"},{"ANU","EZE"},{"ADL","AXA"},{"ANU","AXA"},{"TIA","ADL"},{"JFK","ADL"},{"JFK","TIA"},{"AUA","ADL"},{"AUA","TIA"},{"TIA","JFK"},{"EZE","JFK"},{"AUA","ADL"},{"ADL","AUA"},{"EZE","ANU"},{"ADL","ANU"},{"AUA","AXA"},{"AXA","TIA"},{"AXA","TIA"},{"ADL","AXA"},{"EZE","AXA"},{"AXA","JFK"},{"JFK","AUA"},{"ANU","ADL"},{"AXA","TIA"},{"ANU","AUA"},{"JFK","EZE"},{"AXA","ADL"},{"TIA","EZE"},{"JFK","AXA"},{"AXA","ADL"},{"EZE","AUA"},{"AXA","ANU"},{"ADL","EZE"},{"AUA","EZE"}} */
     {{"JFK","KUL"},{"JFK","NRT"},{"NRT","JFK"}};
    vector<string> res = findItinerary(prueba);
    int n = res.size();
    cout<<"[";
    for(int i = 0; i<n;i++){
        cout<<res[i];
        cout<<",";
    }
    cout << "]" <<endl;
/* 
    cout << res <<endl; */
return 0;}