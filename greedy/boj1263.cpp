#include<bits/stdc++.h>
using namespace std;

struct state{
    int t, s;
};
state a[1001];
int n;

bool cmp(state& a, state& b){
    return a.s < b.s;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> a[i].t >> a[i].s;
    }
    sort(a, a+n, cmp);
    int cur = a[n-1].s;
    for (int i = n-1; i >= 0; i--){
        cur = min(cur, a[i].s) - a[i].t;
        if(cur < 0){
            cout << -1;
            return 0;
        }
    }
    cout << cur;
}