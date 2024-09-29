#include <iostream>
using namespace std;

int n, m;
int arr[101] = {};
int result_cnt{0};

bool check() {
    bool signal = false;
    int temp = 0;
    int cnt = 0;
    int write_idx = 0; 

    for (int i = 0; i < result_cnt; ) {
        temp = arr[i];
        cnt = 0;

        while (i < result_cnt && arr[i] == temp) {
            cnt++;
            i++;
        }

        if (cnt >= m) {
            signal = true;
        } else {
            for (int j = 0; j < cnt; j++) {
                arr[write_idx++] = temp;
            }
        }
    }

    result_cnt = write_idx;
    return signal;
}

int main() {
    cin >> n >> m;
    result_cnt = n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    while (check());

    cout << result_cnt << '\n';
    for (int i = 0; i < result_cnt; i++) {
        cout << arr[i] << "\n";
    }
}