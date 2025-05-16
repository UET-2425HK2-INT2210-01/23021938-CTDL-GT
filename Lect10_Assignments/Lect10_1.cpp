#include <iostream>
using namespace std;

const int MAX_N = 101;
const int MAX_M = 101; 

int adj[MAX_N][MAX_M]; // Danh sách kề
int count[MAX_N]; // Số đỉnh kề của mỗi đỉnh
bool visited[MAX_N]; // Mảng đánh dấu thăm

// Hàm DFS để duyệt một thành phần liên thông
void DFS(int v, int n) {
    visited[v] = true; // Đánh dấu đỉnh v đã thăm
    for (int i = 0; i < count[v]; i++) { // Duyệt các đỉnh kề
        int u = adj[v][i];
        if (!visited[u]) {
            DFS(u, n); // Gọi đệ quy cho đỉnh kề chưa thăm
        }
    }
}

// Hàm components để đếm số thành phần liên thông
int components(int n, int m, int edges[][2]) {
    // Khởi tạo mảng
    for (int i = 1; i <= n; i++) {
        count[i] = 0;
        visited[i] = false;
    }
    
    // Xây dựng danh sách kề từ mảng edges
    for (int i = 0; i < m; i++) {
        int x = edges[i][0];
        int y = edges[i][1];
        adj[x][count[x]++] = y; // Thêm y vào danh sách kề của x
        adj[y][count[y]++] = x; // Thêm x vào danh sách kề của y
    }
    
    int comp = 0; // Đếm số thành phần liên thông
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) { 
            DFS(i, n); // Duyệt thành phần liên thông chứa i
            comp++; // Tăng số thành phần
        }
    }
    
    return comp;
}

int main() {
    int n, m;
    cin >> n >> m;
    
    int edges[MAX_M][2];
    
    // Đọc danh sách cạnh
    for (int i = 0; i < m; i++) {
        cin >> edges[i][0] >> edges[i][1];
    }
    
    cout << components(n, m, edges) << endl;
    return 0;
}