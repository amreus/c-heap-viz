# c-heap-viz

Windows & Linux version of Jacob Sorber's ["Pulling Back the Curtain.."](https://www.youtube.com/watch?v=GIWeQ2I67rk) video.

## Purpose

- I'm curious and enjoy learning and figuring things out.
- I use any number of computers running either Winows 10 or Debian, and like to use the same source files no matter which I happen to be using that moment.


The Windows port worked pretty much out of the box. The same code segfaulted on
Linux. I found when I removed `fprintf` it worked fine. I ended  up using the
`write(2)` system call for the output, which somewhat surprisingly to me worked
on both platforms.

Note: the format of my `allocs.log` file is different from Jacob's original.  I output
the memory address first in order to use command line sorting tools for quick
inspection of the data.  So you can use `wc` to count lines - proper alloc/free
pairs should result in an even number of lines. If you see 2 consecutive lines
with M(alloc), then you can see immediately a `free` was missed.

## Setup

### Windows

[WinLibs](https://winlibs.com/) standalone build of GCC and MinGW-w64 for Windows, installed via [Scoop](https://github.com/ScoopInstaller/Scoop)

- dlfcn from here: https://github.com/dlfcn-win32/dlfcn-win32
- gcc version 13.2.0 (MinGW-W64 x86_64-msvcrt-posix-seh, built by Brecht Sanders)
- GNU Make 4.4.1 Built for x86_64-w64-mingw32

### Linux

- gcc version 12.2.0 (Debian 12.2.0-14)
- GNU libc version: 2.36
- GNU Make 4.3 Built for i686-pc-linux-gnu

## See also

- https://github.com/davedwards/Heap_C
-
