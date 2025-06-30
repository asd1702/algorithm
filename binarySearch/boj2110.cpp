#include<bits/stdc++.h>
using namespace std;

int n, c, a[200001];

bool chk(int mid){
    int cnt = 0, idx = 0;
    while (idx != n){
        idx = lower_bound(a+idx, a+n, a[idx]+mid)-a;
        cnt++;
    }
    return (cnt >= c);
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n >> c;
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    sort(a, a+n);
    int st = 1, en = 1e9;
    while(st < en){
        int mid = (st+en+1)/2;
        if(chk(mid)) st = mid;
        else en = mid-1;
    }
    cout << st;
}