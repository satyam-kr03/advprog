// g++ gcd.cpp -o gcd

#include <iostream>

// swap variables using arithmetic operations
void swap(int& a, int& b) {
  b += a;
  a = b - a;
  b -= a;
}

// Alternative: swap variables using bitwise operations, only meant if you know what this is.
// Please avoid bitwise operations, they may offer some advantages in low-level code,
// but they are error-prone and reduce readability.
void swapXor(int& a, int& b) {
  b = a ^ b;
  a = a ^ b;
  b = a ^ b;
}

int gcdRecursive(int a, int b) {
  if (0 == b) {
    return a;
  } else {
    return gcdRecursive(b, a % b);
  }
}

int gcdIterative(int a, int b) {
  while (b != 0) {
    int temp = a % b;
    a = b;
    b = temp;
  }
  return a;
}

int gcdIterative2(int a, int b) {
  while (b != 0) {
    a %= b;
    swap(a, b);
  }
  return a;
}

int gcdIterative3(int a, int b) {
  while (b != 0) {
    a %= b;
    std::swap(a, b);
  }
  return a;
}

int main() {
  int a = 8;
  int b = 12;

  std::cout << "gcdRec=" << gcdRecursive(a, b) << std::endl;
  std::cout << "gcdIter=" << gcdIterative(a, b) << std::endl;
  std::cout << "gcdIter2=" << gcdIterative2(a, b) << std::endl;
  std::cout << "gcdIter3=" << gcdIterative3(a, b) << std::endl;
  std::cout << "a=" << a << " b=" << b << std::endl;

  // Side-note: example for swapping operations using logical operations.
  // Please avoid this.
  int c = 245;
  int d = -43;

  swapXor(c, d);
  std::cout << "c=" << c << " d=" << d << std::endl;

  return 0;
}
