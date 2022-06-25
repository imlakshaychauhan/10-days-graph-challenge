#include<bits/stdc++.h>
using namespace std;

// Program to find the parent to check whether two nodes are in the same component or not
// and to union the no of nodes with path compression
// TC - O(4 * α) ~ O(4) - constant
// SC - O(N)
int parent[100000], ranks[100000];

void makeSet(int n) {
    for(int i = 0; i <= n; i++) {
        parent[i] = i;
        ranks[i] = 0;
    }
}

int findPar(int node) {
    if(node == parent[node]) return node;
    return parent[node] = findPar(parent[node]); // path compression line
}

void doUnion(int u, int v) {
    u = findPar(u);
    v = findPar(v);
    if(ranks[u] < ranks[v]) parent[u] = v;
    else if(ranks[u] > ranks[v]) parent[v] = u;
    else {
        parent[v] = u;
        ranks[u]++;
    }
}

int main(){
    makeSet(10);
    int m;
    cin >> m;
    while(m--) {
        int u, v;
        cin >> u >> v;
        doUnion(u, v);
    }
    int u, v;
    cout << "Enter two values for checking whether they are in the same component or not: ";
    cin >> u >> v;
    if(findPar(u) != findPar(v))  cout << "Not in the same component";
    else  cout << "In the same component";
    return 0;
}