#include <iostream>

/* 
 * Example 1: factorial 
 * input : integer n such that n >= 0
 * output: [n ×(n - 1) ×(n - 2) × … × 1]
 *         if n is 0 or 1, return 1
 *         otherwise, return[n × factorial(n - 1)]
 * end factorial
 */

long long unsigned factorial(int n) {
  // std::cout << "n= " << n << std::endl;
  if (n == 1 || n == 0) return n; 
  auto result = n * factorial(n - 1);
  // std::cout << "n= " << n << "\tn!= " << result << std::endl;
  return result; 
}

int main() {
  int n[] = {1, 2, 3, 4, 5, 8, 12, 20};
  for (auto x: n)
    std::cout << "factorial(" << x << ") = " << factorial(x) << std::endl;
  return 0;
}
