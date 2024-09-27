#include <iostream>
using namespace std;

int n;
int arr[101] = {};
int temp[101] = {};
int result;
int cnt = 0;

int main() {
    cin >> n;

    for(int i{1};i<=n;i++){
        cin >> arr[i];
    }

    int a, b, c, d;
    cin >> a >> b;
    cin >> c >> d;

    cnt = n - (b - a + 1) - (d - c + 1);

    int j = 0;
    for(int i{1};i<=n;i++){
        j++;
        if(i == a){
            i = b + 1;
        }
        temp[j] = arr[i];
    }

    j = 0;
    for(int i{1};i <= n - (b - a + 1); i++){
        j++;
        if(i == c){
            i = d + 1;
        }

        arr[j] = temp[i];
    }
    
    //output
    cout << cnt << '\n';
    if(cnt != 0){
        for(int i{1};i<=cnt;i++){
            cout << arr[i] << "\n";
        }
    }
    


    return 0;
}