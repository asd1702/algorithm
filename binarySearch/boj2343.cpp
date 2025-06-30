#include<bits/stdc++.h>
#define ll long long
using namespace std;

int n, m, a[100001];

bool chk(int target){
    int cnt = 1; 
    ll sum = 0;
    for (int i = 0; i < n; i++){
        if(target < a[i]) return 0;
        if(sum + a[i] > target){
            cnt++;
            sum = a[i];
        }
        else sum += a[i];
    }
    return (cnt <= m);
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;

    int st = 0;
    ll en = 0;
    
    for (int i = 0; i < n; i++){
        cin >> a[i];
        st = max(st, a[i]);
        en += a[i];
    }

    while (st <= en) {
        ll mid = st + (en - st) / 2;
        if (chk(mid)) en = mid - 1;
        else st = mid + 1;
    }
    
    cout << st;
}