#include <iostream>
#include <vector>
#include <queue>
using namespace std;
//input변수
int N;
int board[25][25];
bool visited[25][25];

int cnt = 0; // 단지 수 카운트
int dx[4] = {-1,0,1,0}; //시계방향 탐색
int dy[4] = {0,1,0,-1};
queue<pair<int,int>> q; // {x,y}값 넣을 큐
vector<int> res; // 각 단지마다 개수 저장 vector
void bfs(void)
{
    int cnt = 0;
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        cnt++;
        q.pop();
        for(int d = 0; d<4; d++)
        {
            int nx = x+dx[d];
            int ny = y+dy[d];
            if(nx<0 || nx >= N || ny <0 || ny >= N) continue; //board범위
            if(visited[nx][ny] == true) continue; // 이미 방문한곳은 패스
            if(board[nx][ny]==1)
            {
                q.push({nx,ny});
                visited[nx][ny] = true;
            }

        }
    }
    res.push_back(cnt); // 각 단지마다의 건물 개수.
}

void solve(void){
    //완전탐색으로 1, visit false인곳 찾아서 시작.
    for(int i = 0 ; i<N; i++)
    {
        for(int j = 0 ; j<N; j++)
        {
            if(board[i][j] ==1 && visited[i][j] == false) // 이미 갔던 곳은 visit에서 걸림.
            {
                cnt++;
                q.push({i,j});
                visited[i][j]=true;
                bfs();
            }
        }
    }
}
int main(void)
{

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    for(int i = 0; i<N; i++)
    {
        string temp;
        cin >> temp;
        for(int j = 0 ; j< N; j++)
        {
            board[i][j] = temp[j]-'0';
        }
    }
    solve();
    sort(res.begin(), res.end()); // 문제 조건 오름차순 출력.
    cout << cnt << '\n';
    for(int i =0 ; i< res.size(); i++)
    {
        cout << res[i] << '\n';
    }
}