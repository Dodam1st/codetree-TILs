#include <iostream>
using namespace std;

int n, m;
int arr[200][200];
int result{0};

int main() {
    cin >> n >> m;

    for(int i{0};i<n;i++){
        for(int j{0};j<m;j++){
            cin >> arr[i][j];
        }
    }

    // 오른쪽으로 3개
    for(int i{0}; i < n; i++){
        for(int j{0}; j <= m - 3; j++){
            int sum{0};
            for(int k{j}; k < j + 3; k++){
                sum += arr[i][k];
            }
            result = max(result, sum);
        }
    }

    // 아래로 3개
    for(int i{0}; i <= n - 3; i++){
        for(int j{0}; j < m; j++){
            int sum{0};
            for(int k{i}; k < i + 3; k++){
                sum += arr[k][j];
            }
            result = max(result, sum);
        }
    }

    for(int i{0};i<=n-2;i++){
        for(int j{0};j<=m-2;j++){
            result = max(arr[i][j] + arr[i+1][j] + arr[i][j+1] + arr[i+1][j+1] - min(min(arr[i][j], arr[i+1][j]), min(arr[i][j+1], arr[i+1][j+1])), result);
        }
    }

    cout << result << '\n';
    return 0;
}