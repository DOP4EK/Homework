#include <iostream>
#include <iomanip>

double CalculateMean(const int* arr, int n) {
  double sum = 0;
  for (int i = 0; i < n; i++) {
    sum += arr[i];
  }
  return sum / n;
}

void FindMinMax(const int* arr, int n, int& min, int& max) {
  max = arr[0];
  min = arr[0];
  for (int i = 0; i < n; i++) {
    if (arr[i] < min) {
      min = arr[i];
    }
    if (arr[i] > max) {
      max = arr[i];
    }
  }
}

int CountBelowZero(const int* arr, int n) {
  int days = 0;
  for (int i = 0; i < n; i++) {
    if (arr[i] < 0) {
      days++;
    }
  }
  return days;
}

int main() {
  int n;
  std::cin >> n;
  int* temperatures = new int[n];
  for (int i = 0; i < n; i++) {
    int a;
    std::cin >> temperatures[i];
  }
  int min;
  int max;
  FindMinMax(temperatures, n, min, max);
  std::cout << std::fixed << std::setprecision(1) << CalculateMean(temperatures, n) << "\n";
  std::cout << min << " " << max << "\n";
  std::cout << CountBelowZero(temperatures, n);
  delete[] temperatures;
}