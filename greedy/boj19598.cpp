#include<bits/stdc++.h>
using namespace std;

int n;
struct state{
    int st, en;
};

state c[100001];

bool cmp(state& a, state& b){
    return a.st < b.st;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> c[i].st >> c[i].en;        
    }
    sort(c, c+n, cmp);
    priority_queue<int, vector<int>, greater<int>>pq;
    pq.push(c[0].en);
    for (int i = 1; i < n; i++){
        if(pq.top() <= c[i].st) pq.pop();
        pq.push(c[i].en);
    }
    cout << pq.size();
}