#include<stdio.h>
#include<stdlib.h>
#include<ucontext.h>
#include "q.h"

#define MEM 64000

struct TCB_t *Curr_Thread, *ReadyQ;
int  thread_count;
void start_thread(void (*function)(void))
{ // begin pseudo code
    //allocate a stack (via malloc) of a certain size (choose 8192)
    int stackSize = 8192;
    void *stackP = malloc(stackSize);

    struct TCB_t *tcb = malloc(sizeof(struct TCB_t));
    tcb->thread_id = thread_count++;
    init_TCB(tcb, function, stackP, stackSize);
    AddQueue(ReadyQ, tcb);
    //end pseudo code
}

void func1() {
    while(1) {
        printf("This is func1");
    }
};


void func2() {
    while(1) {
        printf("This is func2");
    }
};

void run()

{   // real code

    Curr_Thread = DelQueue(ReadyQ);

    ucontext_t parent;     // get a place to store the main context, for faking

    getcontext(&parent);   // magic sauce

    swapcontext(&parent, &(Curr_Thread->context));  // start the first thread
}

int main() {
    printf("Hello, World!\n");
    return 0;
}



//void yield() // similar to run
//{  TCB_t Prev_Thread;
//    AddQueue(ReadyQ, Curr_Thread);
//    Prev_Thread = Curr_Thread;
//    Curr_Thread = DelQueue(ReadyQ);
//    swap the context, from Prev_Thread to the thread pointed to Curr_Thread
//}