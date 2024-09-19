#include <iostream>
using namespace std;

int n;
int arr[1001] = {0};
int dp[1001] = {-1};
int result{0};

void input(){
    cin >> n;

    for(int i{0};i<n;i++){
        cin >> arr[i];
    }

    for(int i{0};i<n;i++){
        dp[i] = -1;
    }
    dp[0] = 0;
}

void process(){
    dp[0] = 0;
    for(int i{1};i<n;i++){
        for(int j{0}; j<i;j++){
            if(dp[j] == -1){                
                continue;
            }

            if(i-j <= arr[j]){
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }
}

void output(){
    for(int i{0};i<n;i++){
        result = max(result, dp[i]);
    }

    cout << result << '\n';
}

int main() {
    input();

    process();

    output();
}