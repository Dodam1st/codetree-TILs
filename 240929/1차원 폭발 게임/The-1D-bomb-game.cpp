#include <iostream>
using namespace std;

int n, m;
int arr[101] = {};
int result_cnt{0};

bool check(){
    int signal = false;
    int temp = 0;
    int cnt = 0;
    for(int i{0};i<result_cnt;i++){
        if(i == 0){
            temp = arr[i];
            cnt = 1;
            continue;
        }

        if(arr[i] == temp){
            cnt++;
        }
        else{
            if(cnt >= m && temp != 0){
                signal = true;
                for(int j{i};j<result_cnt;j++){
                    arr[j - cnt] = arr[j];
                }

                result_cnt -= cnt;
                i = i - cnt + 1;
            }
            temp = arr[i];
            cnt = 1;
        }

        if(i == result_cnt - 1){
            if(cnt >= m && temp != 0){
                signal = true;

                result_cnt -= cnt;
                i = i - cnt + 1;
            }
        }
    }
    return signal;
}

int main() {
    cin >> n >> m;
    result_cnt = n;
    for(int i{0};i<n;i++){
        cin >> arr[i];
    }
    while(true){
        if(!check()){
            break;
        }
    }

    cout << result_cnt << '\n';
    for(int i{0};i<result_cnt;i++){
        cout << arr[i] << "\n";
    }
    return 0;
}