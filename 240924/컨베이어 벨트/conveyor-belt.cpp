#include <iostream>
using namespace std;

int n, t;
int arr[2][201] = {};
int temp[1001]= {};

int main() {
    cin >> n >> t;

    for(int i{0}; i < 2; i++){
        for(int j{0}; j < n; j++){
            cin >> arr[i][j];
        }
    }


    t  = t % (2 * n);

    if(t == n){
        // ouput
        for(int i{1};i>=0;i--){
            for(int j{0};j<n;j++){
                cout << arr[i][j] << " ";
            }
            cout << '\n';
        }
        return 0;
    }

    for(int k{0};k<t;k++){
        int temp = 0;
        temp = arr[0][n-1];
        for(int i{n-2};i>=0;i--){
            arr[0][i + 1] = arr[0][i];
        }
        arr[0][0] = arr[1][n-1];
        for(int i{n-2};i>=0;i--){
            arr[1][i + 1] = arr[1][i];
        }
        arr[1][0] = temp;
    }
    
    // ouput
    for(int i{0};i<2;i++){
        for(int j{0};j<n;j++){
            cout << arr[i][j] << " ";
        }
        cout << '\n';
    }
    return 0;
}