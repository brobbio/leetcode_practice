using namespace std;

#include<stdio.h>
#include<vector>
#include<iostream>
#include<tuple>
#include<algorithm>
#include<map>
#include<set>
#include<stack>

class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};


    
Node* DFS(Node* node, map<int, Node*> diccio, set<int> copiados, set<int>& visitados){
    visitados.insert(node->val);
    Node* nuevo_nodo;
    if(!copiados.count(node->val)){
        nuevo_nodo = new Node;
        nuevo_nodo->val = node->val;
        diccio.insert(make_pair(node->val, nuevo_nodo));
        copiados.insert(node->val);
    }else{
        nuevo_nodo = diccio[node->val];
    }
    for(Node* n: node->neighbors){
            if(!copiados.count(n->val)){
                Node* nuevo_vecino = new Node;
                nuevo_vecino->val = n->val;
                (nuevo_vecino->neighbors).push_back(nuevo_nodo);
                (nuevo_nodo->neighbors).push_back(nuevo_vecino);
                diccio[n->val] = nuevo_vecino;
                copiados.insert(n->val);
            }else{
                Node* nuevo_vecino = diccio[n->val];
                if(!count((nuevo_nodo->neighbors).begin(),(nuevo_nodo->neighbors).end(), nuevo_vecino)){
                    (nuevo_nodo->neighbors).push_back(nuevo_vecino);
                }
                if(!count((nuevo_vecino->neighbors).begin(),(nuevo_vecino->neighbors).end(), nuevo_nodo)){
                    (nuevo_vecino->neighbors).push_back(nuevo_nodo);
                }
            }
    }
    for(Node* n: node->neighbors){
        if(!visitados.count(n->val)){
            DFS(n, diccio, copiados, visitados);
        }
    }
    return diccio[node->val];
}



Node* cloneGraph(Node* node){
    if(node == NULL){
        return NULL;
    }else{
        set<int> visitados;
        return DFS(node, {}, {}, visitados);
    }
}

int main(){
    Node* nodo1 = new Node(1);
    Node* nodo2 = new Node(2);
    Node* nodo3 = new Node(3);
    Node* nodo4 = new Node(4);
    (nodo1->neighbors).push_back(nodo2);
    (nodo1->neighbors).push_back(nodo4);
    (nodo2->neighbors).push_back(nodo1);
    (nodo2->neighbors).push_back(nodo3);
    (nodo3->neighbors).push_back(nodo2);
    (nodo3->neighbors).push_back(nodo4);
    (nodo4->neighbors).push_back(nodo1);
    (nodo4->neighbors).push_back(nodo3);
    Node* res = cloneGraph(nodo1);
    cout<< res;
return 0;}