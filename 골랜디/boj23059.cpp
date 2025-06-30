#include <bits/stdc++.h>
#define mod 101
using namespace std;

int n;
vector<vector<int>> adj; // 동적 할당: 좌표 압축 후 크기에 맞게 생성
vector<int> indeg;

int hashing(const string &s) {
    int ret = 0;
    const int base = 27;
    for (char c : s) {
        ret = ret * base + (c - 'a' + 1);
    }
    return ret;
}

string ret_str(int x) {
    const int base = 27;
    string s = "";
    while (x > 0) {
        int rem = x % base;
        char c = 'a' + rem - 1;
        s = c + s;
        x /= base;
    }
    return s;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    
    // 모든 해싱된 값을 저장할 집합
    set<int> itemSet;
    vector<pair<int,int>> edges;
    
    for (int i = 0; i < n; i++){
        string a, b;
        cin >> a >> b;
        int ha = hashing(a), hb = hashing(b);
        edges.push_back({ha, hb});
        itemSet.insert(ha);
        itemSet.insert(hb);
    }
    
    // 좌표 압축: 해싱된 값 -> 0 ~ (items.size()-1)
    vector<int> items(itemSet.begin(), itemSet.end());
    unordered_map<int, int> mp;
    for (int i = 0; i < items.size(); i++){
        mp[items[i]] = i;
    }
    
    int sz = items.size();
    adj.assign(sz, vector<int>());
    indeg.assign(sz, 0);
    
    // 간선 구성
    for (auto &p : edges){
        int u = mp[p.first];
        int v = mp[p.second];
        adj[u].push_back(v);
        indeg[v]++;
    }
    
    queue<int> pq;
    for (int i = 0; i < sz; i++){
        if (indeg[i] == 0) {
            pq.push(i);
        }
    }
    
    vector<int> ans;
    while(!pq.empty()){
        int cur = pq.front();
        pq.pop();
        ans.push_back(cur);
        for(auto next : adj[cur]){
            indeg[next]--;
            if(indeg[next] == 0){
                pq.push(next);
            }
        }
    }
    
    if(ans.size() != sz){
        cout << -1;
        return 0;
    }
    else{
        // ans에 담긴 값은 좌표 압축된 인덱스이므로, 이를 다시 원래의 해싱 값으로 변환한 후 ret_str 함수를 사용
        for (int idx : ans){
            cout << ret_str(items[idx]) << '\n';
        }
    }
    return 0;
}
