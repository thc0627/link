#include <stdio.h>
#include <string.h>
#include "link.h"

int main(int argc, char const *argv[])
{
    STU *head = NULL;
    char order[32] = "";

    while(1)
    {
        help_link();

        get_order(order);

        if(strcmp("insert", order) == 0)
        {
            insert_link(&head);
        } 
        else if (strcmp("delete", order) == 0)
        {
            delete_link(&head);
        } 
        else if (strcmp("print", order) == 0)
        {
            print_link(head);
        }
        else if (strcmp("clear", order) == 0)
        {
            clear_link(&head);
        }
        else if (strcmp("search", order) == 0)
        {
            search_link(head);
        }
        else if (strcmp("reverse", order) == 0)
        {
            reverse_link(&head);
        }  
        else if (strcmp("quit", order) == 0)
        {
            clear_link(&head);
            break;
        }        
    }    
    return 0;
}
