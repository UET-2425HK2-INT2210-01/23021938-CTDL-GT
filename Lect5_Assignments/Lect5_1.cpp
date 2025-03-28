#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Cấu trúc Node để đại diện cho mỗi nút trong cây
struct Node {
    int data;               // Dữ liệu của nút
    Node* firstChild;       // Con trỏ đến nút con đầu tiên
    Node* nextSibling;      // Con trỏ đến nút anh/chị kế tiếp

    // Hàm khởi tạo để khởi tạo một nút với giá trị dữ liệu
    Node(int data) : data(data), firstChild(nullptr), nextSibling(nullptr) {}
};

class Tree {
private:
    int height;            // Để lưu trữ chiều cao của cây
    int numberNode;        // Tổng số nút trong cây
    Node* root;            // Con trỏ đến nút gốc của cây
    Node* nodeList[1000];  // Mảng để lưu trữ tất cả các nút
    bool isChild[1000];    // Mảng để theo dõi xem một nút đã được đánh dấu là nút con chưa

    // Hàm tính chiều cao của cây một cách đệ quy
    int calculateHeight(Node* node) {
        if (node == nullptr) return 0; // Nếu nút là null, trả về 0 (không có chiều cao)
        
        int maxHeight = 0;
        Node* child = node->firstChild; // Bắt đầu với nút con đầu tiên của nút
        while (child) {
            maxHeight = max(maxHeight, calculateHeight(child)); // Lấy chiều cao tối đa từ các nút con( đến khi hết con thì dừng)
            child = child->nextSibling; // Chuyển sang nút sichild = child->nextSliding; // Chuyển sang nút si kế tiếp
        }
        return maxHeight + 1;  // Thêm 1 để bao gồm nút hiện tại vào chiều cao
    }

    // Duyệt cây theo thứ tự Preorder: Gốc -> Trái -> Phải
    void preorderTraversal(Node* node) {
        if (node == nullptr) return; // Nếu nút là null, trả về
        cout << node->data << " ";   // Thăm nút gốc (in dữ liệu)
        Node* child = node->firstChild;
        while (child) {
            preorderTraversal(child); // Đệ quy với nút con đầu tiên
            child = child->nextSibling; // Chuyển sang nút anh/chị kế tiếp
        }
    }

    // Duyệt cây theo thứ tự Postorder: Trái -> Phải -> Gốc
    void postorderTraversal(Node* node) {
        if (node == nullptr) return; // Nếu nút là null, trả về
        Node* child = node->firstChild;
        while (child) {
            postorderTraversal(child); // Đệ quy với nút con đầu tiên
            child = child->nextSibling; // Chuyển sang nút anh/chị kế tiếp
        }
        cout << node->data << " ";   // Sau khi duyệt hết các nút con, thăm nút gốc (in dữ liệu)
    }

    // Duyệt cây theo thứ tự Inorder cho cây nhị phân: Trái -> Gốc -> Phải
    void inorderTraversal(Node* node) {
        if (node == nullptr) return; // Nếu nút là null, trả về
        Node* child = node->firstChild;
        if (child) {
            inorderTraversal(child); // Thăm nút con trái
        }
        cout << node->data << " ";   // Thăm nút gốc
        if (child && child->nextSibling) { // Nếu có con và có con bên phải -> thăm nút con phải
            inorderTraversal(child->nextSibling);
        }
    }

    // Kiểm tra xem cây có phải là cây nhị phân không (Mỗi nút có tối đa 2 con)
    bool isBinaryTree(Node* node) {
        if (node == nullptr) return true; // Cây rỗng là cây nhị phân
        int childCount = 0; // Đếm số lượng con của nút
        Node* child = node->firstChild;
        while (child) {
            childCount++;
            if (childCount > 2) return false; // Nếu có hơn hai con thì không phải cây nhị phân
            if (!isBinaryTree(child)) return false; // Kiểm tra đệ quy với tất cả các nút con
            child = child->nextSibling; // Chuyển sang nút sib kế tiếp
        }
        return true;
    }

public:
    // Hàm khởi tạo để khởi tạo các tham số của cây
    Tree() {
        height = 0;
        numberNode = 0;
        root = nullptr;
        fill(begin(nodeList), end(nodeList), nullptr); // Khởi tạo tất cả các nút là null
        fill(begin(isChild), end(isChild), false); // Khởi tạo tất cả các nút là chưa phải con
    }

    // Thêm một nút con vào cây
    void addChild(int u, int v) {
        // Tạo nút mới nếu chưa tồn tại
        if (nodeList[u] == nullptr ) {
            nodeList[u] = new Node(u);
        }
        if (nodeList[v] == nullptr){
            nodeList[v] = new Node(v);

        }
        Node* parent = nodeList[u];  // Nút cha là u
        Node* child = nodeList[v];   // Nút con là v

        // Nếu nút cha không có con, gán con đầu tiên
        if (parent->firstChild == nullptr) {
            parent->firstChild = child;
        } else {
            // Nếu đã có con, tìm nút anh/chị cuối cùng và thêm con mới vào đó
            Node* temp = parent->firstChild;
            while (temp->nextSibling != nullptr) {
                temp = temp->nextSibling;
            }
            temp->nextSibling = child; // Thêm nút con vào vị trí anh/chị kế tiếp
        }

        isChild[v] = true;  // Đánh dấu nút v là nút con
        updateRoot();  // Cập nhật nút gốc nếu cần thiết
    }

    // Hàm cập nhật nút gốc: Tìm nút không có cha 
    void updateRoot() {
        for (int i = 1; i < 1000; i++) {
            if (nodeList[i] != nullptr && !isChild[i]) {
                root = nodeList[i]; // Nút không có cha là gốc
                break;
            }
        }
    }

    // Tính chiều cao của cây
    void calculateTreeHeight() {
        height = calculateHeight(root); // Sử dụng hàm đệ quy để tính chiều cao
    }

    // Hiển thị thứ tự duyệt cây theo Preorder
    void displayPreorder() {
        preorderTraversal(root); 
        cout << endl;
    }

    // Hiển thị thứ tự duyệt cây theo Postorder
    void displayPostorder() {
        postorderTraversal(root); 
        cout << endl;
    }

    // Hiển thị thứ tự duyệt cây theo Inorder (chỉ khi cây là cây nhị phân)
    void displayInorder() {
        if (isBinaryTree(root)) {
            inorderTraversal(root); 
            cout << endl;
        } else {
            cout << "NOT BINARY TREE" << endl; 
        }
    }

    
    // Hiển thị
    void displayTreeInfo() {
        cout << height << endl;
        displayPreorder();
        displayPostorder();
        displayInorder();
    }
};

int main() {
    Tree tree;
    int N, M;
    cin >> N >> M; // Nhập số lượng nút và số lượng cạnh

    // Khởi tạo nút gốc và danh sách nút
    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v; // Nhập mỗi cạnh u -> v
        tree.addChild(u, v); // Thêm nút con vào cây
    }

    tree.calculateTreeHeight(); // Tính chiều cao của cây
    tree.displayTreeInfo(); // Hiển thị thông tin của cây

    return 0;
}