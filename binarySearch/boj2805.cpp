#include<bits/stdc++.h>
using namespace std;

int n, m, a[1000001];

bool chk(int h){
    long long cur = 0;
    for (int i = 0; i < n; i++){
        if(a[i]-h <= 0) continue;
        cur += a[i]-h;
    }
    return cur >= m;
}

int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    cin >> n >> m;
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    sort(a, a+n);

    int st = 0, en = a[n-1];
    while(st < en){
        int mid = (st + en +1)/2;
        if(chk(mid)) st = mid;
        else en = mid - 1;
    }
    cout << st;
}