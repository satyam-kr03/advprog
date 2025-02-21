# matvec: Fun with matrices

Version 0.4.0.

This is a fancy calculator for matrices. In contrast to previous weeks, this version delegates most of the functionality to the [Eigen library](https://eigen.tuxfamily.org/).

## Building

Build the code from your terminal using:

```shell
mkdir build
cd build
cmake ..
make
```

If you are calling the compiler directly, remember to specify Eigen in the include directories:

```shell
g++ -I path/to/eigen-version/ -o matvec matvec.cpp
```

## Running

Run the code by executing `./matvec` (no arguments expected).

In this version, the program takes no user input: everything is hard-coded.

## Testing

The `CMakeLists.txt` contains instructions to build a separate test executable.

You can run the tests by building and executing `./testmatvec`.

## Example output

```shell
$ ./matvec 
Matrix: 
1 0 0
0 1 0
0 0 1
vec_a: 
1
2
3
vec_b: 
4
5
6
vec_sum: 
5
7
9
mat_vec
1
2
3
```

```shell
$ ./testmatvec 
Tests passed!
```
