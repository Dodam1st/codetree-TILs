#include <iostream>
#include<vector>
using namespace std;

int n, m;
vector<int> temp;
vector<vector<int>> v;
int result{0};

int main() {
    cin >> n >> m;
    
    // input
    for(int i{0};i<n;i++){
        temp.clear();
        for(int j{0};j<n;j++){
            int a;
            cin >> a;
            temp.push_back(a);
        }
        v.push_back(temp);
    }

    // 아래로
    for(int i{0};i<n;i++){
        int temp_var{0}, cnt_temp_var{0}, max_cnt{0};
        for(int j{0};j<n;j++){
            if(v[i][j] == temp_var){
                cnt_temp_var++;
            }
            else{
                temp_var = v[i][j];
                cnt_temp_var = 1;
            }
            max_cnt = max(max_cnt, cnt_temp_var);
        }

        if(max_cnt >= m){
            result++;
        }
    }   

    // 오른쪽으로
    for(int i{0};i<n;i++){
        int temp_var{0}, cnt_temp_var{0}, max_cnt{0};
        for(int j{0};j<n;j++){
            if(v[j][i] == temp_var){
                cnt_temp_var++;
            }
            else{
                temp_var = v[j][i];
                cnt_temp_var = 1;
            }
            max_cnt = max(max_cnt, cnt_temp_var);
        }

        if(max_cnt >= m){
            result++;
        }
    }   

    cout << result << '\n';
    return 0;
}