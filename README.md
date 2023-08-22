# Virtual Memory
> Note that the code here is not the complete version of the project. The complete code is maintained on GitLab and could be published after 2025 due to UNSW policy. </br>
Please contact me to review the complete version of the code in person.

Provide virtual memory translation for user programs by implementing a page table data structure and its associated TLB refill handler using hashed page table (HPT).

## Task
The main goal for this assignment is to provide virtual memory translation for user programs. To do this, you will need to implement a page table data structure and its associated TLB refill handler. For this assignment, you will implement a hashed page table (HPT).

Note that a hashed page table is a fixed sized data structure allocated at boot time and shared between all processes. We suggest sizing the table to have twice as many entries as there are frames of physical memory in RAM. The size of physical memory can be obtained via a call to `ram_getsize()`. You can allocate and initialise your HPT together with any other associated variables in `vm_bootstrap()` in `vm.c`.

Given the HPT is a shared data structure, it will have to handle concurrent access by multiple processes. You'll need to synchronise operations that access to avoid potential races. Using single lock covering the entire HPT to ensure all operations execute mutually exclusively is satisfactory approach.

Each entry in the HPT typically has a process identifier, the page number, a link to handle collisions, and a frame number and permissions in EntryLo format for faster TLB loading. A HPT entry should not need to exceed 4 32-bit words.

One can use the OS/161 address space pointer (of type struct addrspace) as the value of the current process ID. It is readily accessible where needed, and is unique to each address space.

A simple hash function that produces and index into the HPT can be derived from the following example code.

index = (((uint32_t )addrspace_ptr) ^ (faultaddr >> 12)) % hpt_size;

Note that (faultaddr >> 12) is the page number of the entry we are looking for.

Hash collisions are always possible even with a good hash function, and you can use either internal or external chaining to resolve collisions. We suggest external chaining to avoid the HPT filling in the presence of sharing (in the advanced/bonus assignments), however internal chaining is sufficient for the basic assignment. </br>

![vm_show](https://github.com/PhotKosee/vm-fault/assets/114990364/a7f4bc61-b06f-4874-9928-15d2c1f08531)


![HPT](https://github.com/PhotKosee/vm-fault/assets/114990364/b5e2d502-017c-45cb-bdc4-2e760d211504)

- Implementing external chaining to avoid the HPT filling in the presence of sharing
- Using single lock covering the entire HPT to ensure all operations execute mutually exclusively is satisfactory approach
- Using linked list to maintain address space
