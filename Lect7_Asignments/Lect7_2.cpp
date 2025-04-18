#include <iostream>
#include <fstream>
#include <climits>
using namespace std;

const int MAX_M = 100; // Số hàng tối đa
const int MAX_N = 100; // Số cột tối đa

// Hàm Kadane tìm tổng dãy con lớn nhất và ranh giới của nó
void kadane(int arr[], int n, int& start, int& end, long long& max_sum) {
    long long curr_sum = 0; // Tổng tạm thời
    max_sum = LLONG_MIN; // Tổng lớn nhất
    start = 0;
    end = -1;
    int curr_start = 0; // Vị trí bắt đầu tạm thời

    for (int i = 0; i < n; ++i) {
        curr_sum += arr[i];
        if (curr_sum > max_sum) { // Cập nhật tổng lớn nhất
            max_sum = curr_sum;
            start = curr_start;
            end = i;
        }
        if (curr_sum < 0) { // Nếu tổng âm, reset
            curr_sum = 0;
            curr_start = i + 1;
        }
    }
}

int main() {
    // Mở tệp đầu vào
    ifstream inFile("matrix.txt");
    if (!inFile) {
        cerr << "Không thể mở matrix.txt" << endl;
        return 1;
    }

    // Đọc kích thước ma trận
    int m, n;
    inFile >> m >> n;

    // Đọc ma trận
    int matrix[MAX_M][MAX_N];
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            inFile >> matrix[i][j];
        }
    }
    inFile.close();

    // Biến lưu kết quả
    long long max_sum = LLONG_MIN; // Tổng lớn nhất
    int final_r1, final_c1, final_r2, final_c2; // Tọa độ kết quả

    // Mảng tạm lưu tổng cột
    int temp[MAX_N];

    // Duyệt qua tất cả cặp hàng
    for (int r1 = 0; r1 < m; ++r1) {
        // Khởi tạo mảng tạm bằng 0
        for (int j = 0; j < n; ++j) {
            temp[j] = 0;
        }

        // Mở rộng phạm vi hàng từ r1 đến r2
        for (int r2 = r1; r2 < m; ++r2) {
            // Cộng hàng r2 vào mảng tạm
            for (int j = 0; j < n; ++j) {
                temp[j] += matrix[r2][j];
            }

            // Áp dụng thuật toán Kadane trên mảng tạm
            int c1, c2;
            long long curr_sum;
            kadane(temp, n, c1, c2, curr_sum);

            // Cập nhật kết quả nếu tổng hiện tại lớn hơn
            if (curr_sum > max_sum) {
                max_sum = curr_sum;
                final_r1 = r1 + 1; // Chuyển sang chỉ số bắt đầu từ 1
                final_r2 = r2 + 1;
                final_c1 = c1 + 1;
                final_c2 = c2 + 1;
            }
        }
    }

    // Mở tệp đầu ra
    ofstream outFile("matrix.out");
    if (!outFile) {
        cerr << "Không thể mở matrix.out" << endl;
        return 1;
    }

    // Ghi kết quả
    outFile << final_r1 << " " << final_c1 << " " << final_r2 << " " << final_c2 << " " << max_sum;
    outFile.close();

    return 0;
}