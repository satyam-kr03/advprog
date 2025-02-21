# caseTrack: A pandemic cases tracker

Version 0.3.0.

caseTrack processes data related to a global pandemic.

## Building

From the base directory (containing `src/` and `data/`), run:

```shell
mkdir build
cd build
cmake ../src/
make
```

## Running

Run the code by executing `./caseTrack`.

## Example output

```shell
$ ./caseTrack 
**********Choose**********
Press (d) for dummy data
Press (r) for real data
r
Afghanistan: 271 351 165 276 460 234 338 310 409 546 346 658 564 783 761 664 556 656 747 684 542 575 791 582 915 787 758 759 545 680 

Albania: 64 72 61 77 78 67 52 68 36 53 50 66 50 82 69 57 48 31 44 42 36 17 14 20 15 13 20 21 6 15 

Algeria: 298 305 283 240 197 172 156 149 140 127 119 117 121 116 112 109 112 109 105 102 117 111 104 115 104 205 0 113 119 127 

Andorra: 0 0 0 0 0 0 0 0 0 0 0 1 0 1 0 0 0 1 0 0 0 0 0 0 0 1 7 79 1 0 
```

## Notes

The skeleton contains all files in the same folder and does not yet contain a `CMakeLists.txt` or a `Makefile`. Part of the worksheet is organizing the code and creating such a `CMakeLists.txt`! 😉
