//
// Created by pcd22 on 27.10.17.
//

#ifndef UNTITLED2_FUNCTION1_H
#define UNTITLED2_FUNCTION1_H

#endif //UNTITLED2_FUNCTION1_H

struct ForwardList
{
    struct Node
    {
        int DATA;
        Node *NEXT;
    };
    Node *HEAD;
    Node *TAIL;
};
ForwardList *initForwardList();
void destroy(ForwardList**);
void destroy(ForwardList** ptr);
ForwardList::Node* pushFront(ForwardList* const list, const ForwardList::int & data);
ForwardList::Node* popFront(ForwardList* const);
