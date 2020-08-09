# Unix Practice

A Collection of c programs focused around posix/ unix systems basics.

## Scope

In general the scope is high level general purpose C programming all the way down to raw sys calls
in the unix environment. I wanted to collect all the small programs together for future reference.
Additionally, much of the approach phiolosophy follows TLPI.

I redid some very basic c programs to focus from the ground up on evolution of C programming/
feature set additions from ANSI C, C99, C11 and beyond. Some of the programs are inherently ridiculous
in that I imagined trying to teach/ explain it to an absolute beginner and test my understanding. I include
In-line x86 assembly in this list although technicall it should be more in a driver collection/ OS/ embedded probably.

## Things it is not (practice some other time)

kernel hacking, device drivers, Clang / Cmake (I just custom write every makefile)

## Organization

I break up every top level directory by specific topic per my own designation. 


## Goals

1. Gain a rock solid understanding of multi process environments in userland, raw system calls, compilers from a
userland perspective, multithreading, sockets, IPC.. that sort of thing.

2. Implement data structures in C. I already *know* C so doing things like hash maps and sorting via C
is really just to set that information in. Also, I have never implemented those structures with raw ptr access.

3. Maybe make some videos on it. There are some *pretty decent* but quick videos on unix C programming but I find
they kinda lack often. Maybe it will help someone else.


