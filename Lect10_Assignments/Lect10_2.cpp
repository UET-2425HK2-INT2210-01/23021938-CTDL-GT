#include <iostream>
using namespace std;

const int MAX_N = 101; 
const int MAX_M = 101; 

int adj[MAX_N][MAX_M]; // Danh sách kề
int count[MAX_N]; // Số đỉnh kề của mỗi đỉnh
bool visited[MAX_N]; // Mảng đánh dấu thăm
int dist[MAX_N]; // Mảng lưu khoảng cách
int queue[MAX_N]; // Hàng đợi tĩnh
int front, rear; // Con trỏ hàng đợi
// Đồ thị có hướng

// Hàm BFS để tìm đường đi ngắn nhất từ X đến Y
int shortestPath(int n, int m, int X, int Y, int edges[][2]) {
    // Khởi tạo
    for (int i = 1; i <= n; i++) {
        count[i] = 0;
        visited[i] = false;
        dist[i] = -1;
    }
    
    // Xây dựng danh sách kề
    for (int i = 0; i < m; i++) {
        int x = edges[i][0];
        int y = edges[i][1];
        adj[x][count[x]++] = y; // Thêm y vào danh sách kề của x
    }
    
    // Khởi tạo hàng đợi
    front = 0;
    rear = 0;
    queue[rear++] = X; // Thêm X vào hàng đợi
    visited[X] = true;
    dist[X] = 0;
    
    // BFS
    while (front < rear) {
        int v = queue[front++]; // Lấy đỉnh đầu hàng đợi
        for (int i = 0; i < count[v]; i++) {
            int u = adj[v][i]; // Đỉnh kề
            if (!visited[u]) {
                visited[u] = true;
                dist[u] = dist[v] + 1;
                queue[rear++] = u; // Thêm u vào hàng đợi
                if (u == Y) {
                    return dist[u]; // Tìm thấy Y
                }
            }
        }
    }
    
    return -1; // Không tìm thấy đường đi
}

int main() {
    int n, m, X, Y;
    cin >> n >> m >> X >> Y;
    
    int edges[MAX_M][2];
    for (int i = 0; i < m; i++) {
        cin >> edges[i][0] >> edges[i][1];
    }
    
    cout << shortestPath(n, m, X, Y, edges) << endl;
    
    return 0;
}