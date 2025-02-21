# PanSimul: A simulator of the next pandemic

It's pretty much like a particle interaction code...

## Building

Build the code in your terminal:

```shell
mkdir build
cd build
cmake ..
make
```

## Running

Run the code in your terminal:

```shell
./panSimul
```

No arguments are expected.

In its current form, the code shows only shows the elapsed time and the maximum distance between two people.

## Notes

When compiling the skeleton, you will see that the linker cannor find an implementation for the `Person` class. Maybe that's where you should begin looking at...
