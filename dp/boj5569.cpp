#include<bits/stdc++.h>
#define mod 100000
#define ll long long
using namespace std;

int w, h;
ll dp[101][101];
ll comb[101][101];

ll combination(int n, int r){
    if(n == r || r == 0) return 1;
    if(comb[n][r]) return comb[n][r];
    return comb[n][r] = (combination(n-1, r-1) + combination(n-1, r)) % mod;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> w >> h;

    for (int i = 0; i < w; i++){
        for (int j = 0; j < h; j++){
            if(j == 0){
                dp[i][0] = 1;
            }
            
        }
    }
    
}