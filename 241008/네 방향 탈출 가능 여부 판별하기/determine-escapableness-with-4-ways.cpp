#include <iostream>
#include <queue>
using namespace std;

struct xy{
    int x, y;
};

int n, m;
int arr[100][100] = {-1};
bool visited[100][100] = {false};
queue<xy> q {};
int X[4] = {-1,1,0,0};
int Y[4] = {0,0,-1,1};

void BFS(){
    while(!q.empty()){
        int xx = q.front().x;
        int yy = q.front().y;
        q.pop();

        for(int i{0};i<4;i++){
            int nx = X[i] + xx;
            int ny = Y[i] + yy;

            if(nx >= 0 && ny >= 0 && nx < n && ny < m){
                if(arr[nx][ny] == 1 && visited[nx][ny] == false){
                    visited[nx][ny] = true;
                    q.push({nx, ny});
                }
            }
        }
    }
}

int main() {
    cin >> n >> m;

    for(int i{0};i<n;i++){
        for(int j{0};j<m;j++){
            cin >> arr[i][j];
        }
    }

    q.push({0, 0});
    visited[0][0] = true;
    BFS();

    if(visited[n-1][m-1] == true){
        cout << 1;
        return 0;
    }
    cout << 0;
    return 0;
}