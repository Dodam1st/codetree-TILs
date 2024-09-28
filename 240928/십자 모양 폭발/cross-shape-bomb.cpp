#include <iostream>
using namespace std;

int n;
int arr[201][201] = {0};
int temp[201][201] = {0};
int r, c;

int main() {
    // input
    cin >> n;
    for(int i{1}; i<=n; i++){
        for(int j{1}; j<=n; j++){
            cin >> arr[i][j];
        }
    }
    cin >> r >> c;

    int target = arr[r][c];

    for(int i{0};i<target;i++){  // 가로
        if(c - i > 0){
            arr[r][c - i] = 0;
        }
        if(c + i <= n){
            arr[r][c + i] = 0;
        }
    }
    
    for(int i{0};i<target;i++){  // 세로
        if(r - i > 0){
            arr[r - i][c] = 0;
        }
        if(r + i <= n){
            arr[r + i][c] = 0;
        }
    }

    // arr -> temp
    for(int i{1};i<=n;i++){
        int t = n + 1;
        for(int j{n};j>0;j--){
            t--;
            while(arr[j][i] == 0){
                j--;
                if(j == 0){
                    break;
                }
            }
            temp[t][i] = arr[j][i];
        }
    }

    for(int i{1};i<=n;i++){
        for(int j{1};j<=n;j++){
            cout << temp[i][j] << " ";
        }
        cout << '\n';
    }

    return 0;
}