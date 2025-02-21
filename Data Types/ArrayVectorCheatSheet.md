# Arrays in C++ 
(Small Cheatsheet)

## std::array
- Used as a static array
- Size known at compile time
- Stored fully on the stack

```cpp
#include <array>

// std::array<type, size>
std::array<int, 3> myInts = {4, 7, 9};
std::array<double, 4> myDoubles{5.8, 8.2, 2.0, 1.11};
std::array<float, 8> myZeros{}; // {0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0}

// Accessing elements
int myNum = myInts[0];

// Multidimensional Arrays
std::array<std::array<int, 3>, 3> myMatrix{}; // A 3x3 matrix of zeroes
int myMatrixElem = myMatrix[1][2];

```

## std:: vector 
- Used for dynamic arrays
- Size can vary
- Elements are stored on the heap

```cpp
#include <vector>

// std::vector<type>
std::vector<int> myNums = {4, 8, 6};
std::vector<double> myZeros(5); // 5 zeros

// Careful!
std::vector<int> smallVec{4, 2}; // {4, 2}
std::vector<int> bigVec(4, 2); // {2, 2, 2, 2}

// Append an element to the end of the vector
myNums.push_back(7);

// Looping over a vector
for (int i = 0; i < myNums.size(); i++) {
	std::cout << myNums[i] << " ";
}

// Range-based for loop
for (auto &myElement : myNums) {
	myElement = myElement + 10;
}
// Note: Adding the Ampersand (&), leads to `myElement` being a reference instead of a copy (default behavior). This is needed when we want to modify elements inside the array/vector.
```