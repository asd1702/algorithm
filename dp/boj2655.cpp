#include<bits/stdc++.h>
using namespace std;

struct block{
    int area, height, weight, idx;
};

int n;
block b[101];
int dp[101];

bool cmp(block& a, block& b){
    return a.area < b.area;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> b[i].area >> b[i].height >> b[i].weight;
        b[i].idx = i;
    }
    sort(b+1,b+n+1, cmp);
    int maxh = 0;
    for (int i = 1; i <= n; i++){
        for (int j = 0; j < i; j++){
            if(b[i].weight < b[j].weight) continue;
            dp[i] = max(dp[i], dp[j] + b[i].height);
        }
        maxh = max(maxh, dp[i]);
    }
    vector<int>res;
    while(n){
        if(maxh == dp[n]){
            res.push_back(b[n].idx);
            maxh -= b[n].height;
        }
        n--;
    }
    cout << res.size() << '\n';
    for (int i = res.size()-1; i >= 0; i--){
        cout << res[i] << '\n';
    }
}