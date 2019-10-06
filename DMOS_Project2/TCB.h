//
// Created by vivemeno on 10/4/19.
//
#include <ucontext.h>
# include "string.h"
#ifndef DMOS_PROJECT2_TCB_H
#define DMOS_PROJECT2_TCB_H

#endif //DMOS_PROJECT2_TCB_H
struct TCB_t {
    struct TCB_t *next;
    struct TCB_t *prev;
    int thread_id;
    ucontext_t context;

};

void init_TCB (struct TCB_t *tcb, void (*function)(), void *stackP, int stack_size)
{
    //memset(tcb, "\0", sizeof(struct TCB_t));       // wash, rinse
    getcontext(&tcb->context);              // have to get parent context, else snow forms on hell
    tcb->context.uc_stack.ss_sp = stackP;
    tcb->context.uc_stack.ss_size = (size_t) stack_size;
    makecontext(&tcb->context, function, 0);// context is now cooked
}

