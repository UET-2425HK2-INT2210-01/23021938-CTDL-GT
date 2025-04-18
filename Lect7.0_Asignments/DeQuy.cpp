#include <iostream>
using namespace std;
//Tính tổng 1->n
int tong(int n) {
    if(n == 1) return 1;
    return n + tong(n - 1);
}

//Tính giai thừa
unsigned long long giaiThua(int n) {
    if(n == 0 || n == 1) return 1;
    return n * giaiThua(n - 1);
}

//Tính số Fibo thứ n
int Fibo(int n) {
    if(n == 0) return 0;
    if(n == 1) return 1;
    return Fibo(n - 1) + Fibo(n -2);
}

//Tính lũy thừa
unsigned long long luyThua(int x, int n) {
    if(n == 0) return 1;
    return x * luyThua(x, n - 1);
}

//Đếm số chữu số của n
int demChuSo(int n) {
    if (n < 10)
        return 1;
    return 1 + demChuSo(n / 10); //Bớt đi 1 hàng đơn vị
}

//Tổng các chữ số của n
int tongChuSo(int n) {
    if(n < 10) return n;
    return (n / 10) + tongChuSo(n/10);
}

//Đảo ngược số nguyên n
int daoNguoc(int n, int revNum = 0) {
    if (n == 0)
        return revNum;
    return daoNguoc(n / 10, revNum * 10 + n % 10);
}