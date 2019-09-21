#ifndef __LINK_H__
#define __LINK_H__

typedef struct stu
{
    char name[64];
    int num;
    int age;
    char sex[4];

    struct stu *next;

}STU;

extern void help_link(void);
extern void get_order(char *order);
extern void insert_link(STU **head);
extern void print_link(STU *head);
extern void delete_link(STU **head);
extern void clear_link(STU **head);
extern void search_link(STU *head);
extern void reverse_link(STU **head);

#endif