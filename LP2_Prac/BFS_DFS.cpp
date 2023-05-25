#include<bits/stdc++.h>
using namespace std;

void DFS(int source, vector<int> adj[], vector<bool> &vis, vector<int> &dfsAns){
    if(vis[source] == true) return;
    vis[source] = true;
    // cout << source << " ";
    dfsAns.push_back(source);
    for(auto x: adj[source]){
        DFS(x, adj, vis, dfsAns); 
    }
    return;
}
void BFS(int source, vector<int> adj[], vector<bool> &vis, vector<int> &bfsAns){
    queue<int> q;
    q.push(source);
    if(vis[source] == true) return;
    vis[source] = true;
    
    while(!q.empty()){
        int topElem = q.front();
        q.pop();
        // cout << topElem << " ";
        bfsAns.push_back(topElem);
        for(auto child : adj[topElem]){
            if(vis[child] == false){
                q.push(child);
                vis[child] = true;
            }
        }
    }
    cout <<endl;
    return;
}

int main(){
    int n,m;
    cin >> n >> m;
    vector<int> adj[n+1];
    while(m--){
        int u,v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    //print adjacency list here
    int source; cin >> source;
    // if(source >= 1 && source <= n){
    //     cout << "Vertex exists!" << endl;
    // }
    // int choice; cin >> choice;
    // 1. BFS, 2. DFS, 3. EXIT
    vector<bool> visited(n+1, false), visited1(n+1, false);
    // if(choice == 1) BFS(source, adj, visited);
    // else if(choice == 2) DFS(source, adj, visited);
    // else return 0;
    vector<int> dfsAns, bfsAns;
    DFS(source, adj, visited, dfsAns);
    BFS(source, adj, visited1, bfsAns);

    for(int i=1;i<=n;i++){
        if(visited[i] == false){
            DFS(i, adj, visited, dfsAns);
        }
    }
    for(int i=1;i<=n;i++){
        if(visited1[i] == false){
            BFS(i, adj, visited1, bfsAns);
        }
    }

    cout << "DFS : ";
    for(auto x: dfsAns) cout << x << " ";
    cout <<endl;
    cout << "BFS : ";
    for(auto x: bfsAns) cout << x << " ";
    cout <<endl;

    return 0;
}

/*

void BFS(int source, vector<int> adj[], vector<bool> &vis, vector<int> &bfsAns){
    queue<int> q;
    q.push(source);
    vis[source] = true;
    while(!q.empty()){
        int topElem = q.top();
        q.pop();
        bfsAns.pb(topElem);
        for(auto x: adj[topElem]){
            if(vis[x] == false){
                queue.push(x);
                vis[x] = true;
            }
        }
    }
}

*/