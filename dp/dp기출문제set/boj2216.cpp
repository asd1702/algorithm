#include<bits/stdc++.h>
#define INF 1e9
using namespace std;

string s1, s2;
int a, b, c;
int dp[3001][3001];

int solve(int i, int j){
    if(i == s1.size()){
        return (s2.size() - j)*b;
    }
    if(j == s2.size()){
        return (s1.size() - i)*b;
    }
    int& ret = dp[i][j];
    if(ret != -1) return ret;

    int score = (s1[i] == s2[j]) ? a : c;
    ret = max({solve(i+1, j+1) + score, solve(i+1, j) + b, solve(i, j+1) + b});

    return ret;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> a >> b >> c >> s1 >> s2;

    memset(dp, -1, sizeof(dp));
    cout << solve(0, 0);
}