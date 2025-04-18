#include <iostream>
using namespace std;


//Dùng quay lui(Backtracking)
const int MAX_N = 10; // Số n tối đa được hỗ trợ
int perm[MAX_N];      // Mảng lưu hoán vị hiện tại
bool used[MAX_N];     // Mảng theo dõi số nào đã được dùng

// Hàm in hoán vị hiện tại
void print_permutation(int n) {
    for (int i = 0; i < n; ++i) {
        cout << perm[i];
        // if (i < n - 1) cout << " "; // Thêm dấu cách giữa các số, trừ số cuối
    }
    cout << endl; // Xuống dòng sau mỗi hoán vị
}

// Hàm sinh tất cả hoán vị bằng quay lui
void generate_permutations(int pos, int n) {
    if (pos == n) { // Nếu đã điền đủ n số
        print_permutation(n); // In hoán vị
        return;
    }
    
    for (int i = 1; i <= n; ++i) { // Thử từng số từ 1 đến n
        if (!used[i]) { // Nếu số i chưa được dùng
            used[i] = true; // Đánh dấu số i đã dùng
            perm[pos] = i; // Đặt số i vào vị trí hiện tại
            generate_permutations(pos + 1, n); // Đệ quy cho vị trí tiếp theo
            used[i] = false; // Bỏ đánh dấu để thử số khác
        }
    }
}

int main() {
    int n;
    cin >> n;
    if (n > MAX_N || n < 1) { 
        cout << "n phai tu 1 den " << MAX_N << endl;
        return 1;
    }
    
    generate_permutations(0, n); // Bắt đầu sinh hoán vị từ vị trí 0
    return 0;
}