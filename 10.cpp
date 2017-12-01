#include "function1.h"


ForwardList *initForwardList()
{
    ForwardList *list = new ForwardList();
    list->HEAD = nullptr;
    return list;
}

void destroy(ForwardList** ptr)
{
    ForwardList* list = *ptr;

    ForwardList::Node* head = list->HEAD;
    while (head)
    {
        ForwardList::Node* tmp = head->NEXT;
        delete head;
        head = tmp;
    }
    delete list;

    *list = nullptr;
}

ForwardList::Node* createNode(const int& data, ForwardList::Node* prev, ForwardList::Node* next)
{
    ForwardList::Node* node = new ForwardList::Node();
    node->DATA = data;
    node->NEXT = next;
    return node;
}

ForwardList::Node* pushFront(ForwardList* const list, const ForwardList::int & data)
{
//

  //
    ForwardList::Node* node = createNode(data, nullptr, list->HEAD);

    if (list->HEAD)
    list->HEAD = node;

    if (list->TAIL == nullptr)
        list->TAIL = node;
    return node;
}
ForwardList::Node* popFront(ForwardList* const ptr)
{
    if (ptr->HEAD == nullptr)
        return nullptr;

    ForwardList::Node* node = ptr->HEAD;
    ptr->HEAD = node->NEXT;

    return node;
}

void popFrontAndDelete(ForwardList* const ptr)
{
    ForwardList::Node * node = popFront(ptr);
    delete node;
}

int main()
{
    ForwardList * ls = initForwardList();

    pushFront(ls, 10);

    ForwardList::Node* p = popFront(ls);

    delete p;
}
