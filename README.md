# c-heap-viz

Windows & Linux version of Jacob Sorber's ["Pulling Back the Curtain.."](https://www.youtube.com/watch?v=GIWeQ2I67rk) video.


## How

- compile the allocators (type `make`)
- run any of the allocators: `simple`, `batch`, `random`, `leaky`. This should to create a `allocs.log` file.
- run the `mapper.rb`

## Purpose

- Recreation. I'm just curious and enjoy learning and figuring things out.

The code worked pretty much out of the box on Windows. The code segfaulted when
compiled on Linux. I found when I removed `fprintf` it worked. So I ended  up
using the `write(2)` system call for the output, which somewhat surprisingly to
me worked on both platforms.

Note: the format of my `allocs.log` file is slightly different from Jacob's
original.  I output the memory address first in order to use command line
sorting tools for quick inspection of the data.  So you can use `wc` to count
lines - proper alloc/free pairs should result in an even number of lines. If
the sorted lines have consecutive Mallocs, then you can see immediately a
`free` was missed.

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
