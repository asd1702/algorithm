#include<bits/stdc++.h>
using namespace std;

int n, m, k;
string s[2001];

int solve(char color){
    int psum[n+1][m+1], val = 0;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            if((i+j)%2) val = (color != s[i][j]);
            else val = (color == s[i][j]);
            psum[i+1][j+1] = psum[i][j+1] + psum[i+1][j] - psum[i][j] + val;
        }
    }
    int res = 1e9;
    for (int i = 0; i <= n-k; i++){
        for (int j = 0; j <= m-k; j++){
            int sum = psum[i+k][j+k] - psum[i][j+k] - psum[i+k][j] + psum[i][j];
            res = min(res, sum);
        }
    }
    return res;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m >> k;
    for (int i = 0; i < n; i++){
        cin >> s[i];
    }
    cout << min(solve('W'),solve('B'));
}