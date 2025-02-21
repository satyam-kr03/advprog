# mm_mult: A cache optimization testbed

What is the best order to multiply the elements of two matrices and store the corresponding results? Find out using `mm_mult`!

## Building

In your teminal:

```shell
mkdir build
cd build
cmake ..
make
```

## Running

In your terminal:

```shell
./mm_mult
```

## Example output

```shell
$ ./mm_mult 
 ================== 64 ================ 
== loop order: row - column - k ==
sample 0 elapsed time: 4ms MFLOP/s: 131.072
sample 1 elapsed time: 3ms MFLOP/s: 174.763
sample 2 elapsed time: 3ms MFLOP/s: 174.763
sample 3 elapsed time: 3ms MFLOP/s: 174.763
 ================== 128 ================ 
== loop order: row - column - k ==
sample 0 elapsed time: 32ms MFLOP/s: 131.072
sample 1 elapsed time: 31ms MFLOP/s: 135.3
sample 2 elapsed time: 32ms MFLOP/s: 131.072
sample 3 elapsed time: 31ms MFLOP/s: 135.3

...
```
