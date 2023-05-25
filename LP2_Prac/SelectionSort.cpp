#include<bits/stdc++.h>
using namespace std;

void selectionSort(vector<int> &v, int n, vector<int> &ans){
    for(int i=0;i<n;i++){
        for(int j= i+1;j<n;j++){
            if(v[i] > v[j]){
                swap(v[i], v[j]);
            }
        }
    }
    return;
}
int main(){
    int n; cin >> n;
    vector<int> v(n, 0);
    for(int i=0;i<n;i++){
        cin >> v[i];
    }
    vector<int> ans = v;
    selectionSort(v, n, ans);
    for(auto x: v) cout << x << " ";
    cout << endl;
    return 0;
}