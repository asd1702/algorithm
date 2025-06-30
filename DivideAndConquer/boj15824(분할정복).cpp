#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
 
const ll MOD = 1000000007;
 
// 전역 스코빌 배열 (정렬되어 있음)
vector<ll> A;
 
// 분할 정복으로 구간 [l, r]에 대한 정보를 계산하는 구조체
struct Node {
    ll cnt;      // 구간 내 non-empty 부분집합 개수
    ll sum_max;  // 각 부분집합의 최대값 합
    ll sum_min;  // 각 부분집합의 최소값 합
    ll F;        // 각 부분집합의 (최대-최소) 값의 합
};
 
// 두 구간의 정보를 합치는 함수 (배열이 오름차순 정렬되어 있다고 가정)
Node combine(const Node &L, const Node &R) {
    Node res;
    // non-empty 부분집합 개수: L, R 각각의 부분집합과 둘 다 선택한 경우
    res.cnt = (L.cnt + R.cnt + (L.cnt * R.cnt) % MOD) % MOD;
    // cross 부분: L와 R를 합친 부분집합의 최대값은 오른쪽 구간의 최대값이 된다.
    res.sum_max = (L.sum_max + R.sum_max + (R.sum_max * L.cnt) % MOD) % MOD;
    // cross 부분: 최소값은 왼쪽 구간의 최소값이 된다.
    res.sum_min = (L.sum_min + R.sum_min + (L.sum_min * R.cnt) % MOD) % MOD;
    // 기존 구간의 F 값에 더해, cross 부분의 기여: (R.sum_max * L.cnt - L.sum_min * R.cnt)
    res.F = (L.F + R.F + ((R.sum_max * L.cnt) % MOD + MOD - (L.sum_min * R.cnt) % MOD)) % MOD;
    return res;
}
 
// 구간 [l, r]에 대해 Node 정보를 계산 (배열 A는 오름차순 정렬되어 있음)
Node solve(int l, int r) {
    if(l == r) {
        // 단일 원소: non-empty 부분집합은 {A[l]} 뿐이며, 최대=최소=A[l]이므로 F=0
        Node node;
        node.cnt = 1;
        node.sum_max = A[l] % MOD;
        node.sum_min = A[l] % MOD;
        node.F = 0;
        return node;
    }
    int mid = (l + r) / 2;
    Node leftNode = solve(l, mid);
    Node rightNode = solve(mid+1, r);
    return combine(leftNode, rightNode);
}
 
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N;
    cin >> N;
    A.resize(N);
    for (int i = 0; i < N; i++){
        cin >> A[i];
    }
    
    // 정렬: 분할 정복 결합 공식이 올바르게 작동하려면 오름차순이어야 함.
    sort(A.begin(), A.end());
    
    // 전체 구간에 대해 정보를 계산
    Node ans = solve(0, N - 1);
    
    // ans.F는 모든 non-empty 부분집합에 대해 (최대-최소)의 합입니다.
    // (한 원소 부분집합은 차이가 0이므로 자연스럽게 포함되어 있음)
    cout << ans.F % MOD << "\n";
    
    return 0;
}
