#include <iostream>
#include<vector>
using namespace std;

int n;
vector<int> temp_v;
vector<vector<int>> v;
int result{0};

int cnt(int a, int b){
    int re = 0;
    for(int i{a};i<a+3;i++){
        for(int j{b};j<b + 3;j++){
            if(v[i][j] == 1){
                re++;
            }
        }
    }
    return re;
}

int main() {
    cin >> n;
    
    for(int i{0};i<n;i++){
        temp_v.push_back(0);
    }
    for(int i{0};i<n;i++){
        v.push_back(temp_v);
    }

    for(int i{0};i<n;i++){
        for(int j{0};j<n;j++){
            cin >> v[i][j];
        }
    }

    for(int i{0};i<=n-3;i++){
        for(int j{0};j<=n-3;j++){
            result = max(cnt(i, j), result);
        }
    }

    cout << result << '\n';
    return 0;
}