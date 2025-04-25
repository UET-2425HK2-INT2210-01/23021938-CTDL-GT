#include <iostream>
using namespace std;

void quicksort(double arr[], int left, int right) {
    if(left < right) {
        double pivot = arr[right]; //Chọn pivot là phần từ cuốcuối
        
        int i = left - 1;
        for(int j = left; j < right; ++j) {
            if(arr[j] < pivot) { //Nhỏ hơn thì đưa về bên trái
                i++;
                double tmp = arr[i];
                arr[i] = arr[j];
                arr[j] = tmp;
            }
        }
        
        //Đưa pivot về đúng vị trí
        double temp = arr[i + 1];
        arr[i + 1] = arr[right];
        arr[right] = temp;
        int pi = i + 1; //Vị trí pivot
        
        quicksort(arr, left, pi - 1); //Đệ quy mảng bên trái pivot
        quicksort(arr, pi + 1, right); //Đệ quy mảng bên phải pivot
    }
    
}

int main() {
    int n;
    cin >> n;
    
    double arr[1001];
    for(int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    quicksort(arr, 0, n - 1);
    
    for(int i = 0; i < n; ++i) {
        cout << arr[i] << " ";
    }
    return 0;
}