#include <iostream>
using namespace std;

//Lomuto
int partition1(int a[], int p, int r) {
    int piv = a[r]; //Chọn pivot là giá trị cuối
    int i = p - 1;
    for(int j = p; j < r ; j ++) {
        if(a[j] <= piv) { //Khi có giá trị <= pivot => hóa vị với vị trí i++
            i++;
            swap(a[i], a[j]);
        }
    }
    swap(a[i + 1], a[r]); //Đưa pivot về đúng vị trí 
    return i + 1; // Trả về vị trí của pivot
} 

void quicksort1(int a[], int p, int r) {
    if(p >= r) return; //Còn 1 phần tử thì dừng
    int pi = partition1(a, p, r); //Vị trí pivot
    quicksort1(a, p, pi - 1); //Đệ quy ra 2 phía 
    quicksort1(a, pi + 1, r);
}

//Hoare
int partition2(int a[], int p, int r) {
    int x = a[p]; //Chonj pivot là giá trị đầu
    int i = p - 1;
    int j = r + 1;
    while(1) { 
        do {
            ++i;
        } while(a[i] < x);
        do {
            --j;
        }while(a[j] > x);
        
        if(i < j) {
            swap(a[i], a[j]);
        } else {
            return j; // Trả về vị trí của pivot
        }
    }
}

void quicksort2(int a[], int p, int r) {
    if(p >= r) return;
    int pi = partition2(a, p, r);
    quicksort2(a, p, pi);
    quicksort2(a, pi + 1, r);
}


int main() {
    int arr[1001];
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    //quicksort1(arr, 0, n - 1); //Lomuto
    quicksort2(arr, 0, n - 1); //Hoare
    
    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}