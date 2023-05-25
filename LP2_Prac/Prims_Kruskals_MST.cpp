#include<bits/stdc++.h>
using namespace std;
void Prims(vector<pair<int,int>> adj[], int n, int m, int &costP, vector<int> &vis, int cnt, vector<pair<int,int>> &primsMST){
    if(vis.empty()) vis.push_back(1);
    while(cnt != n){
        int maxE = 1000;
        pair<int,int> pp = {0 ,0};
        for(auto x: vis){
            for(auto y: adj[x]){
                auto it = find(vis.begin(), vis.end(), y.first);
                if(it == vis.end()){
                    if(y.second < maxE){
                        pp.first = x;
                        pp.second = y.first; 
                        maxE = y.second;   
                    }
                }
            }
        }
        primsMST.push_back(pp);
        costP += maxE;
        cnt+=1;
        vis.push_back(pp.second);
    }
    return;
}

// void Kruskals(vector<pair<int,int>> adj[], int n, int m, int &costK, int cnt, vector<pair<int,int>> &kruskalsMST, vector<pair<int, pair<int,int>>> &vpp){
//     vector<bool> visited(n+1, false);
//     for(int i=0;i<m;i++){
//         if(!(visited[vpp[i].second.first] == true && visited[vpp[i].second.second] == true)){
//             // cnt+=1;
//             visited[vpp[i].second.first] = true;
//             visited[vpp[i].second.second] = true;
//             costK += vpp[i].first;
//             kruskalsMST.push_back({vpp[i].second.first, vpp[i].second.second});
//         }
//     }
//     return;
// }
int main(){
    int n, m; cin >> n >> m;
    vector<pair<int,int>> adj[n+1];
    for(int i=0;i<m;i++){
        int u,v,w; cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    int costP =0 ,costK=0;
    int source = 1;
    vector<int> visited;
    vector<pair<int,int>> primsMst, kruskalsMst;
    visited.push_back(1);
    int cnt =1;
    Prims(adj, n, m, costP, visited, cnt, primsMst);
    cout << "Prims MST : " << endl;
    for(auto x: primsMst){
        cout << "(" << x.first << ", " << x.second << "), ";
    }
    cout << "\nCOST : " << costP << endl;


    // for(int i =1;i<=n;i++){
    //     cout << i << " -> ";
    //     for(auto x: adj[i]){
    //         cout << "(" << x.first << ": " << x.second<< " ), ";
    //     }
    //     cout <<endl;
    // }
    // cout << endl;

    // vector<pair<int, pair<int,int>>> vpp;
    // for(int i=1;i<=n;i++){
    //     for(auto x: adj[i]){
    //         vpp.push_back({x.second, {i, x.first}});
    //     }
    // }
    // sort(vpp.begin(), vpp.end());
    // cnt=0;
    // Kruskals(adj, n, m, costK,cnt, kruskalsMst, vpp);
    // cout << "Kruskals MST : " << endl;
    // for(auto x: kruskalsMst){
    //     cout << "(" << x.first << ", " << x.second << "), ";
    // }
    // cout << "\nCOST : " << costK << endl;

    return 0;
}