
## udhay@udhay-virtual-machine:~/Linux/Dailytask/GDB$ valgrind --tool=memcheck ./memcheck
```
==3619== Memcheck, a memory error detector
==3619== Copyright (C) 2002-2015, and GNU GPL'd, by Julian Seward et al.
==3619== Using Valgrind-3.11.0 and LibVEX; rerun with -h for copyright info
==3619== Command: ./memcheck
==3619== 
==3619== Invalid read of size 1
==3619==    at 0x8048495: main (in /home/udhay/Linux/Dailytask/GDB/memcheck)
==3619==  Address 0x4209029 is 0 bytes after a block of size 1 alloc'd
==3619==    at 0x402C17C: malloc (in /usr/lib/valgrind/vgpreload_memcheck-x86-linux.so)
==3619==    by 0x8048485: main (in /home/udhay/Linux/Dailytask/GDB/memcheck)
==3619== 

 []
==3619== 
==3619== HEAP SUMMARY:
==3619==     in use at exit: 0 bytes in 0 blocks
==3619==   total heap usage: 2 allocs, 2 frees, 1,025 bytes allocated
==3619== 
==3619== All heap blocks were freed -- no leaks are possible
==3619== 
==3619== For counts of detected and suppressed errors, rerun with: -v
==3619== ERROR SUMMARY: 1 errors from 1 contexts (suppressed: 0 from 0)
```
## udhay@udhay-virtual-machine:~/Linux/Dailytask/GDB$ 

