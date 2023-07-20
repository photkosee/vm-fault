# Address Translation
> The source code is maintained on GitLab and could be published after 2025 due to UNSW policy. </br>
Please reach out to me to review the code in person.

Provide virtual memory translation for user programs by implementing a page table data structure and its associated TLB refill handler using hashed page table (HPT).


![vm_show](https://github.com/PhotKosee/vm-fault/assets/114990364/a7f4bc61-b06f-4874-9928-15d2c1f08531)


![HPT](https://github.com/PhotKosee/vm-fault/assets/114990364/b5e2d502-017c-45cb-bdc4-2e760d211504)

- Implementing external chaining to avoid the HPT filling in the presence of sharing
- Using single lock covering the entire HPT to ensure all operations execute mutually exclusively is satisfactory approach
- Using linked list to maintain address space
