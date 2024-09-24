#include <iostream>
using namespace std;

int n, t;
int arr[3][201] = {};

int main() {
    // input
    cin >> n >> t;

    for(int i{0};i<3;i++){
        for(int j{0};j<n;j++){
            cin  >> arr[i][j];
        }
    }

    t = t % (3 * n);

    int temp[3];
    for(int k{0};k<t; k++){
        for(int j{0};j<3;j++){
            for(int i{n-1};i>=0;i--){
                if(i == n-1){
                    temp[j] = arr[j][i];
                }
                arr[j][i] = arr[j][i-1];
            }
            
        }   
        arr[0][0] = temp[2];
        arr[1][0] = temp[0];
        arr[2][0] = temp[1];
    }

    for(int i{0};i<3;i++){
        for(int j{0};j<n;j++){
            cout << arr[i][j] << " ";
        }
        cout << '\n';
    }

    return 0;
}