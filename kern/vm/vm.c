#include <types.h>
#include <kern/errno.h>
#include <lib.h>
#include <thread.h>
#include <addrspace.h>
#include <vm.h>
#include <machine/tlb.h>
#include <synch.h>
#include <spl.h>
#include <proc.h>
#include <current.h>


void
vm_bootstrap(void)
{
    /* Initialise any global components of your VM sub-system here.  
     *  
     * You may or may not need to add anything here depending what's
     * provided or required by the assignment spec.
     */

    return;
}

int
vm_fault(int faulttype, vaddr_t faultaddress)
{
  struct addrspace *as;
  /* EntryHi to match page# and ASID */
  /* EntryLo to match frame# and permissions */

  if (curproc == NULL) {
    /*
		 * No process. This is probably a kernel fault early
		 * in boot. Return EFAULT so as to panic instead of
		 * getting into an infinite faulting loop.
		 */
    return EFAULT;
	}

	as = proc_getas();
	if (as == NULL) {
    /*
		 * No address space set up. This is probably also a
		 * kernel fault early in boot.
		 */
		return EFAULT;
	}
  
  /* check faulttype (cant be VM_FAULT_READONLY) */
  switch (faulttype) {
		case VM_FAULT_READONLY:
			return EFAULT;
		case VM_FAULT_READ:
		case VM_FAULT_WRITE:
			break;
	  default:
			return EINVAL;
	}

  /* look up pt */

  return EFAULT;
}

/*
 * SMP-specific functions.  Unused in our UNSW configuration.
 */

void
vm_tlbshootdown(const struct tlbshootdown *ts)
{
	(void)ts;
	panic("vm tried to do tlb shootdown?!\n");
}

