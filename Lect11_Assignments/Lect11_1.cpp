#include <iostream>
#include <fstream>
using namespace std;

const int MAX_N = 101; 
const long long INF = 101; 

long long adj[MAX_N][MAX_N]; // Ma trận mức độ bẩn
long long dist[MAX_N][MAX_N]; // Ma trận khoảng cách (Floyd-Warshall)
long long dijkstra_dist[MAX_N]; // Khoảng cách từ s (Dijkstra)
int parent[MAX_N]; // Truy vết đường đi
bool visited[MAX_N]; 

// Hàm Dijkstra để tìm đường đi nhỏ nhất từ s đến e
void dijkstra(int s, int e, int n) {
    // Khởi tạo
    for (int i = 1; i <= n; i++) {
        dijkstra_dist[i] = INF;
        visited[i] = false;
        parent[i] = -1;
    }
    dijkstra_dist[s] = 0;
    
    // Lặp n lần
    for (int i = 1; i <= n; i++) {
        // Tìm đỉnh chưa thăm có dist nhỏ nhất
        long long min_dist = INF;
        int u = -1;
        for (int j = 1; j <= n; j++) {
            if (!visited[j] && dijkstra_dist[j] < min_dist) {
                min_dist = dijkstra_dist[j];
                u = j;
            }
        }
        if (u == -1) break; // Không còn đỉnh nào
        visited[u] = true;
        
        // Cập nhật khoảng cách
        for (int v = 1; v <= n; v++) {
            if (!visited[v] && adj[u][v] != INF) {
                if (dijkstra_dist[v] > dijkstra_dist[u] + adj[u][v]) {
                    dijkstra_dist[v] = dijkstra_dist[u] + adj[u][v];
                    parent[v] = u;
                }
            }
        }
    }
}

// Hàm Floyd-Warshall để tìm khoảng cách ngắn nhất giữa tất cả các cặp đỉnh
void floydWarshall(int n) {
    // Khởi tạo ma trận dist
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            dist[i][j] = adj[i][j];
        }
    }
    
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (dist[i][k] != INF && dist[k][j] != INF) {
                    if (dist[i][j] > dist[i][k] + dist[k][j]) {
                        dist[i][j] = dist[i][k] + dist[k][j];
                    }
                }
            }
        }
    }
}

// Hàm truy vết đường đi từ s đến e
void tracePath(int e, int path[], int& pathLen) {
    pathLen = 0;
    for (int v = e; v != -1; v = parent[v]) {
        path[pathLen++] = v;
    }
    // Đảo ngược đường đi
    for (int i = 0; i < pathLen / 2; i++) {
        int temp = path[i];
        path[i] = path[pathLen - 1 - i];
        path[pathLen - 1 - i] = temp;
    }
}

int main() {
    // Mở file đầu vào
    ifstream inp("dirty.txt");
    int n, m, s, e;
    inp >> n >> m >> s >> e;
    
    // Khởi tạo ma trận adj
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            adj[i][j] = (i == j) ? 0 : INF;
        }
    }
    
    // Đọc danh sách cạnh
    for (int i = 0; i < m; i++) {
        int u, v, d;
        inp >> u >> v >> d;
        adj[u][v] = min(adj[u][v], (long long)d); // Lấy mức độ bẩn nhỏ nhất
    }
    inp.close();
    
    // Tìm đường đi từ s đến e
    dijkstra(s, e, n);
    
    // Tìm ma trận khoảng cách
    floydWarshall(n);
    
    // Ghi kết quả ra file
    ofstream out("dirty.out");
    
    // Tổng mức độ bẩn
    if (dijkstra_dist[e] == INF) {
        out << "INF" << endl;
    } else {
        out << dijkstra_dist[e] << endl;
    }
    // Đường đi từ s đến e
    int path[MAX_N], pathLen;
    tracePath(e, path, pathLen);
    if (dijkstra_dist[e] == INF) {
        out << "INF";
    } else {
        for (int i = 0; i < pathLen; i++) {
            out << path[i];
            if (i < pathLen - 1) out << " ";
        }
    }
    out << endl;
    
    // n dòng tiếp theo: Ma trận khoảng cách
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (dist[i][j] == INF) {
                out << "INF";
            } else {
                out << dist[i][j];
            }
            if (j < n) out << " ";
        }
        out << endl;
    }
    
    out.close();
    return 0;
}