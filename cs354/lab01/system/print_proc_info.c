/* print_proc_info.c - print_proc_info */

#include <xinu.h>
#include <string.h>

syscall print_proc_info(pid32 pid)
{
    intmask mask;
    struct procent *prptr;
    
    // save interrupt mask
    mask = disable();

    // check if PID is valid
    prptr = &proctab[pid];
    if (pid > NPROC || prptr == NULL)
    {
        return SYSERR;
    }
    
    // print PID information
    kprintf("%s %d %d %s\n", prptr->prname, prptr->prprio, prptr->prstate, prptr->prstkptr);

    // restore interrupt mask
    restore(mask);

    return OK;
}
