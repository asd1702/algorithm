#include <iostream>
#include <queue>
#include <vector>
using namespace std;
 
struct State {
    int a, b, turn, cost;
};
 
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int n, A, B, DA, DB;
    cin >> n >> A >> B >> DA >> DB;
    // 0-indexed 변환
    A--; B--;
 
    // visited[a][b][turn] : 상태 (A의 위치, B의 위치, 현재 지목할 차례)를 방문했는지.
    vector<vector<vector<bool>>> visited(n, vector<vector<bool>>(n, vector<bool>(2, false)));
    queue<State> q;
    q.push({A, B, 0, 0});
    visited[A][B][0] = true;
 
    while(!q.empty()){
        State cur = q.front();
        q.pop();
 
        int a = cur.a, b = cur.b, turn = cur.turn, cost = cur.cost;
 
        if(turn == 0){ // A가 지목할 차례
            for (int d : {DA, -DA}) {
                int newA = (a + d + n) % n;
                int newCost = cost + 1;
                // A의 지목으로 게임 종료: A가 지목한 사람이 이미 B의 지목권을 가지고 있다면
                if(newA == b){
                    cout << newCost;
                    return 0;
                }
                // 그렇지 않으면, B가 지목할 차례로 전환 (상태: (newA, b, turn=1))
                if(!visited[newA][b][1]){
                    visited[newA][b][1] = true;
                    q.push({newA, b, 1, newCost});
                }
            }
        } else { // turn == 1, B가 지목할 차례
            for (int d : {DB, -DB}) {
                int newB = (b + d + n) % n;
                int newCost = cost + 1;
                // B의 지목으로 게임 종료: B가 지목한 사람이 이미 A의 지목권을 가지고 있다면
                if(newB == a){
                    cout << newCost;
                    return 0;
                }
                // 그렇지 않으면, 다음 턴은 A의 지목 차례 (상태: (a, newB, turn=0))
                if(!visited[a][newB][0]){
                    visited[a][newB][0] = true;
                    q.push({a, newB, 0, newCost});
                }
            }
        }
    }
 
    cout << "Evil Galazy";
    return 0;
}
