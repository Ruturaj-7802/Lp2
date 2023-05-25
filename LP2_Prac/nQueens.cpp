#include <bits/stdc++.h>
using namespace std;

void solve(int col, vector<int> &lr, vector<int> &ud, vector<int> &ld, vector<string> &board, vector<vector<string>> &ans, int n)
{

    if (col == n)
    {
        ans.push_back(board);
        return;
    }

    for (int row = 0; row < n; row++)
    {
        if (lr[row] == 0 && ud[n - 1 + col - row] == 0 && ld[row + col] == 0)
        {

            board[row][col] = 'Q';
            lr[row] = 1;
            ud[n - 1 + col - row] = 1;
            ld[row + col] = 1;
            solve(col + 1, lr, ud, ld, board, ans, n);
            board[row][col] = '.';
            lr[row] = 0;
            ud[n - 1 + col - row] = 0;
            ld[row + col] = 0;
        }
    }
}

int main()
{
    int n;
    cout << "Enter the dimension of the chess road\n";
    cin >> n;

    vector<vector<string>> ans;
    vector<string> board(n);
    string s(n, '.');

    for (int i = 0; i < n; i++)
    {
        board[i] = s;
    }

    vector<int> lr(n, 0);
    vector<int> ud(2 * n - 1, 0), ld(2 * n - 1, 0);
    solve(0, lr, ud, ld, board, ans, n);

    for (int i = 0; i < ans.size(); i++)
    {

        cout << "ANSWER " << i + 1 << endl;

        for (int j = 0; j < ans[i].size(); j++)
        {
            cout << ans[i][j] << endl;
        }
    }
    return 0;
}


// N queens
// #include <bits/stdc++.h>
// using namespace std;

// void solve(int col, vector<int> &leftrow, vector<int> &ud, vector<int> &ld, vector<vector<string>> &v, vector<string> &board, int n)
// {
//     if (col == n)
//     {
//         v.push_back(board);
//         return;
//     }
//     for (int row = 0; row < n; row++)
//     {
//         if (leftrow[row] == 0 && ud[n - 1 + col - row] == 0 && ld[row + col] == 0)
//         {
//             board[row][col] = 'Q';
//             leftrow[row] = 1;
//             ud[n - 1 + col - row] = 1;
//             ld[row + col] = 1;
//             solve(col + 1, leftrow, ud, ld, v, board, n);
//             board[row][col] = '.';
//             leftrow[row] = 0;
//             ud[n - 1 + col - row] = 0;
//             ld[row + col] = 0;
//         }
//     }
// }

// int main()
// {
//     int n;
//     cout << "Enter the dimension of the chess board\n";
//     cin >> n;
//     vector<vector<string>> v;
//     vector<string> board(n);
//     string s(n, '.');

//     for (int i = 0; i < n; i++)
//     {
//         board[i] = s;
//     }
//     vector<int> leftrow(n, 0);
//     vector<int> ud(2 * n - 1, 0), ld(2 * n - 1, 0);

//     solve(0, leftrow, ud, ld, v, board, n);
//     for (int i = 0; i < v.size(); i++)
//     {
//         cout << "ANSWER " << i + 1 << endl;
//         for (int j = 0; j < v[i].size(); j++)
//         {
//             cout << v[i][j] << endl;
//         }
//     }
//     return 0;
// }