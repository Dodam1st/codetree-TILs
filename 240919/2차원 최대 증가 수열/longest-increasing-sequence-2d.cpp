#include <iostream>
using namespace std;

int n, m;
int arr[51][51];
int dp[51][51];

int main() {
    // input
    cin >> n >> m;
    for(int i{0};i<n;i++){
        for(int j{0};j<n;j++){
            cin >> arr[i][j];
        }
    }

    // dp setting
    for (int i{0};i<n;i++){
        for(int j{0};j<m;j++){
            dp[i][j] = -1;
        }
    }
    dp[0][0] = 1;

    // process
    /*for(int i{1};i<n;i++){
        for(int j{0};j<i;j++){
            if(dp[0][j] == -1) continue;

            if(arr[0][i] > arr[0][j]){
                dp[0][i] = max(dp[0][i], dp[0][j] + 1);
            }
        }
    }

    for(int i{1};i<m;i++){
        for(int j{0};j<i;j++){
            if(dp[j][0] == -1) continue;

            if(arr[i][0] > arr[j][0]){
                dp[i][0] = max(dp[i][0], dp[j][0] + 1);
            }
        }
    }*/

    for(int i{1}; i<n; i++){
        for(int j{1}; j<m; j++){
            for(int k{0}; k<i; k++){
                for(int l{0}; l<j; l++){
                    if(dp[k][l] == -1) continue;

                    if(arr[i][j] > arr[k][l]){
                        dp[i][j] = max(dp[i][j], dp[k][l] + 1);
                    }
                }
            }
        }
    }

    /*for(int i{0};i<n;i++){
        for(int j{0};j<m;j++){
            cout << dp[i][j] << " ";
        }
        cout << '\n';
    }*/

    int result{0};
    for(int i{0};i<n;i++){
        for(int j{0};j<m;j++){
            result = max(result, dp[i][j]);
        }
    }
    
    cout << result << '\n';

    return 0;
}