#include "Sll.h"

int find_loop(Slist *head)
{
        if (head == NULL)
                return LIST_EMPTY;
        
        Slist *slow = head, *fast = head;
        while (slow != NULL && fast != NULL && fast->link)
        {
                slow = slow->link;
                fast = fast->link->link;
                if (slow == fast)
                        return LOOP_DETECTED;
        }
        return LOOP_NOT_DETECTED;
}
