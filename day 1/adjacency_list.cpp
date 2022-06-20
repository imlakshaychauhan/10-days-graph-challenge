#include<bits/stdc++.h>
using namespace std;

int main(){
    int v, e;
    cout << "Enter no of vertices and edges : ";
    cin >> v >> e;
    vector<pair<int, int>> adj[v + 1];
    for(int i = 0; i < e; i++) {
        int f, s, wt;
        cout << "Enter two vertices that are connected directly : ";
        cin >> f >> s;
        cout << "Enter the weight : ";
        cin >> wt;
        adj[f].push_back({f, wt});
        adj[s].push_back({s, wt});
    }
    return 0;
}