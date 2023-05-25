#include<bits/stdc++.h>
#define pb push_back
using namespace std;

void solve(int start, vector<int> &col, vector<int> &nd, vector<int> &rd, vector<string> &board, vector<vector<string>> &ans, int n){
    if(start == n){
        ans.pb(board);
        return;
    }
    for(int row = 0; row<n; row++){
        if(col[row] == 0 && nd[row+start] == 0 && rd[n-1+start-row] == 0){
            board[row][start] = 'Q';
            col[row] = 1;
            nd[row + start] = 1;
            rd[n - 1 + start - row] = 1;
            
            solve(start+1, col, nd, rd, board, ans, n);

            board[row][start] = '.';
            col[row] = 0;
            nd[row+start] = 0;
            rd[n - 1 + start - row] = 0;
        }
    }

}

int main(){
    int n; cin >> n;
    string s(n, '.');
    vector<string> board(n, s);
    vector<vector<string>> ans;

    vector<int> col(n, 0);
    vector<int> nd(2*n - 1, 0), rd(2*n -1, 0);

    solve(0, col, nd, rd, board, ans, n);
    if(ans.size()!=0){
        for(int i=0;i<ans.size();i++){
            cout << "\nANSWER " << i+1 << endl;
            for(int j=0;j<ans[i].size();j++){
                cout << ans[i][j] << endl;
            }
        }
    }
    else{
        cout << "Solution not possible" << endl;
    }

    return 0;
}