#include <iostream>
using namespace std;

int main() {
    int n, X;
    cin >> n >> X;
    
    int ages[100]; 
    for (int i = 0; i < n; ++i) {
        cin >> ages[i];
    }
    
    // Mảng quy hoạch động: dp[j] = true nếu tồn tại tập con có tổng j
    bool dp[10001]; 
    for (int j = 0; j <= X; ++j) {
        dp[j] = false;
    }
    dp[0] = true; // Tổng 0 luôn đạt được (tập rỗng)
    
    // Quy hoạch động
    for (int i = 0; i < n; ++i) {
        for (int j = X; j >= ages[i]; --j) {
            if (dp[j - ages[i]]) {
                dp[j] = true; // Có thể đạt tổng j bằng cách thêm ages[i]
            }
        }
    }
    
    if (dp[X]) {
        cout << "YES";
    } else {
        cout << "NO";
    }
    
    return 0;
}