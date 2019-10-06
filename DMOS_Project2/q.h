//
// Created by vivemeno on 10/4/19.
//
#include "TCB.h"
#ifndef DMOS_PROJECT2_Q_H
#define DMOS_PROJECT2_Q_H

#endif //DMOS_PROJECT2_Q_H
struct TCB_t* newQueue() {

    struct TCB_t *head = NULL;
    return head;
}
void AddQueue(struct TCB_t *head, struct TCB_t *item) {
    if (!head) {
        head = item;
        return;
    }
    struct TCB_t *lastNode = head->prev;
    lastNode -> next =item;
    item->next = head;
    head->prev = item;
//    while (node->next != NULL) {
////        node = node ->next;
////    }
}

struct TCB_t* DelQueue(struct TCB_t *head) {
    struct TCB_t *nodeToReturn = head;

    struct TCB_t *lastNode = head->prev;
    head = head->next;
    lastNode->next = head;
    return nodeToReturn;
}