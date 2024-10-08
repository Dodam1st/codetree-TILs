#include <iostream>
#include <queue>
using namespace std;

struct xy{
    int x;
    int y;
};

int n, k;
int arr[100][100] = {-1};
bool visited[100][100] = {false};
queue<xy> q = {};
int X[4] = {0,0,-1,1};
int Y[4] = {1,-1,0,0};
int result{0};

void BFS() {
    while(!q.empty()){
        int xx = q.front().x;
        int yy = q.front().y;
        q.pop();

        for(int i{0};i<4;i++){
            int nx = xx + X[i];
            int ny = yy + Y[i];

            if(nx >= 0 && ny >= 0 && nx <n && ny < n){
                if(arr[nx][ny] == 0 && visited[nx][ny] == false){
                    visited[nx][ny] = true;
                    result++;
                    q.push({nx, ny});
                }
            }
        }
    }
}

int main() {
    
    cin >> n >> k;

    for(int i{0};i<n;i++){
        for(int j{0};j<n;j++){
            cin >> arr[i][j];
        }
    }

    int a, b;
    for(int i{0};i<k;i++){
        cin >> a >> b;
        if(arr[a-1][b-1] == 0 && visited[a-1][b-1] == false){
            q.push({a-1,b-1});
            visited[a-1][b-1] = true;
            result++;
            BFS();
        }
    }

    cout << result;
    return 0;
}