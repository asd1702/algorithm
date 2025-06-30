#include<bits/stdc++.h>
#define INF 1e9
using namespace std;

int n;
int dp[401][401][401];
int a_size, b_size;
vector<int>a, b;

int solve(int i, int j, int len){
    if(i == a_size || j == b_size) return 0;
    int& ret = dp[i][j][len];
    if(ret != -INF) return ret;
    
    ret = max(ret, solve(i+1, j+1, len+1) + a[i] * b[j]);
    if(n - a_size > len - i){
        ret = max(ret, solve(i, j+1, len+1));
    }
    if(n - b_size > len - j){
        ret = max(ret, solve(i+1, j, len+1));
    }
    return ret;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++){
        int x;
        cin >> x;
        if(x != 0) a.push_back(x);
    }
    for (int i = 0; i < n; i++){
        int x;
        cin >> x;
        if(x != 0) b.push_back(x);
        
    }
    a_size = a.size();
    b_size = b.size();
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            for (int k = 0; k < n; k++){
                dp[i][j][k] = -INF;
            }
        }
    }
    cout << solve(0, 0, 0);
}