#include <iostream>
using namespace std;

int main() {
    
    int n, X;
    cin >> n >> X;
    
    //Nhập giá trị 
    int w[100], v[100];  
    for (int i = 0; i < n; ++i) {
        cin >> w[i] >> v[i]; 
    }
    
   
    long long dp[10001]; 
    for (int j = 0; j <= X; ++j) {
        dp[j] = 0; 
    }
    
    // Quy hoạch động
    for (int i = 0; i < n; ++i) {
        for (int j = X; j >= w[i]; --j) {
            dp[j] = max(dp[j], dp[j - w[i]] + v[i]);
        }
    }
    
    cout << dp[X];
    
    return 0;
}