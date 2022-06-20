#include<bits/stdc++.h>
using namespace std;

int main(){
    int v, e;
    cout << "Enter no of vertices and edges : ";
    cin >> v >> e;
    int adj[v + 1][v + 1];
    for(int i = 0; i < v + 1; i++)
        for(int j = 0; j < v + 1; j++)
            adj[i][j]  = 0;
    for(int i = 0; i < e; i++) {
        int f, s;
        cout << "Enter two vertices that are connected directly : ";
        cin >> f >> s;
        adj[f][s] = 1;
        adj[s][f] = 1;
    }
    for(int i = 0; i < v + 1; i++) {
        for(int j = 0; j < v + 1; j++)
            cout << adj[i][j] << " ";
        cout << endl;
    }
    return 0;
}