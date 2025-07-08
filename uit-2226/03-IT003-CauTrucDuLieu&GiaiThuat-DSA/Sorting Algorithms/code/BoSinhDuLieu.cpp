#include <iostream>
#include <cstdlib>
#include <ctime>
#include <algorithm>
using namespace std;

// Hàm tạo số thực ngẫu nhiên trong khoảng [a, b]
double randomDouble(double a, double b) {
  return a + (b - a) * rand() / RAND_MAX;
}

// Hàm tạo một mảng gồm n số thực ngẫu nhiên trong khoảng [a, b]
void createRandomArray(double arr[], int n, double a, double b) {
  for (int i = 0; i < n; i++) {
    arr[i] = randomDouble(a, b);
  }
}

// Hàm in một mảng ra màn hình
void printArray(double arr[], int n) {
  for (int i = 0; i < n; i++) {
    cout << arr[i] << " ";
  }
  cout << endl;
}

int main() {
  // Khởi tạo giá trị hạt giống cho hàm rand()
  srand(time(0));

  // Số phần tử của mỗi mảng
  int n = 1000000;

  // Khoảng giá trị của số thực ngẫu nhiên
  double a = -100.0;
  double b = 100.0;

  // Tạo bộ dữ liệu gồm 10 mảng
  double data[10][n];

  // Tạo mảng đầu tiên có thứ tự tăng dần
  createRandomArray(data[0], n, a, b);
  sort(data[0], data[0] + n);

  // Tạo mảng thứ hai có thứ tự giảm dần
  createRandomArray(data[1], n, a, b);
  sort(data[1], data[1] + n, greater<double>());

  // Tạo các mảng còn lại có trật tự ngẫu nhiên
  for (int i = 2; i < 10; i++) {
    createRandomArray(data[i], n, a, b);
  }

  // In ra các mảng đã tạo
  for (int i = 0; i < 10; i++) {
    cout << "Mang thu " << i + 1 << ": ";
    printArray(data[i], n);
    cout << endl;
  }

  return 0;
}
