#include <iostream>
using namespace std;

int n;
int arr[1001];
int dp[1001];

int main() {
    cin >> n;

    for(int i{0};i<n;i++){
        cin >> arr[i];
    }

    for(int i{0}; i<n; i++){
        dp[i] = 0;
    }


    for(int i{1}; i<n; i++){
        for(int j{0}; j<i; j++){
            if(arr[j] < arr[i]){
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }

    int result = 0;
    for(int i{0};i<n;i++){
        result = max(dp[i], result);
    }

    cout << result + 1 << '\n';

    return 0;
}