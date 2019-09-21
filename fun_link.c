#include <stdio.h>
#include <stdlib.h>
#include "link.h"

void help_link(void)
{
    printf("***************************\n");
    printf("** intsert：添加学生信息 **\n");
    printf("** delete ：删除学生信息 **\n");
    printf("** print  ：遍历学生信息 **\n");
    printf("** reverse：逆序学生信息 **\n");
    printf("** search ：查找学生信息 **\n");
    printf("** clear  ：清空学生信息 **\n");
    printf("** quit   ：退出         **\n");
    printf("***************************\n");
}

void get_order(char *order)
{
    printf("请输入指令:");
    scanf("%s", order);
    getchar();
}

void insert_link(STU **head)
{
    STU *pi;

    pi = (STU *)calloc(1,sizeof(STU));

    printf("请输入学生的信息 姓名 学号 年龄 性别:");
    scanf("%s %d %d %s", pi->name, &pi->num, &pi->age, pi->sex);
    getchar();

    if(*head == NULL)
    {
        *head = pi;
        pi->next = NULL;
    }
    else
    {
        STU *pb = *head;
        STU *pf = *head;

        while(pb->num < pi->num && pb->next != NULL)
        {
            pf = pb;
            pb = pb->next;
        } 

        if(pb->num >= pi->num)
        {
            if(pb->num == (*head)->num)
            {
                pi->next = *head;
                *head = pi;
            }
            else
            {
                pf->next = pi;
                pi->next = pb;
            }
            
        }
        else if(pb->next == NULL)
        {
            pb->next = pi;
            pi->next = NULL;
        }   
    }    
}

void print_link(STU *head)
{
    if(head == NULL)
    {
        printf("学生信息为空\n");
    }
    else
    {
        STU *pb = head;

        while(pb != NULL)
        {
            printf("学生信息为 姓名:%s 学号:%d 年龄:%d 性别:%s\n", pb->name, pb->num, pb->age, pb->sex);
            pb = pb->next;
        }
    }   
}

void delete_link(STU **head)
{
    if(*head == NULL)
    {
        printf("学生信息为空\n");
        return;
    }

    int num = 0;

    printf("请输入要删除学生的学号:");
    scanf("%d", &num);
    getchar();

    STU *pb = *head;
    STU *pf = *head;

    while(pb->num != num && pb->next != NULL)
    { 
       pf = pb;
       pb = pb->next; 
    }

    if(pb->num == num)
    {
        if(pb == *head)
        {
            *head = pb->next;
            free(pb);
            printf("删除成功\n");
        }
        else if(pb->next == NULL)
        {
            pf->next = NULL;
            free(pb);
            printf("删除成功\n");
        }
        else
        {
            pf->next = pb->next;
            free(pb);
            printf("删除成功\n");
        } 
    }
    else if (pb->next == NULL)
    {
        printf("没有这名学生的信息\n");
    }  
}

void clear_link(STU **head)
{
    if(*head == NULL)
    {
        printf("学生信息已清空\n");
        return;
    }
    else
    {
        STU *pb = *head;

        while(*head != NULL)
        {
            *head = pb->next;
            free(pb);
            pb = *head;
        }
    }

    printf("学生信息已清空\n");  
}

void search_link(STU *head)
{
    if(head == NULL)
    {
        printf("学生信息为空\n");
        return;
    }
    else
    {
        int num = 0;

        printf("请输入要查找学生的学号:");
        scanf("%d", &num);

        STU *pb = head;

        while(pb->num != num && pb->next != NULL)
        {
            pb = pb->next;
        }

        if(pb->num == num)
        {
            printf("要查找的学生信息为 姓名:%s 学号:%d 年龄:%d 性别:%s\n", pb->name, pb->num, pb->age, pb->sex);
        }
        else if (pb->next == NULL)
        {
            printf("没有这名学生的信息\n");
        }
    }  
}

void reverse_link(STU **head)
{
    if(*head == NULL)
    {
        printf("学生信息为空\n");
        return;
    }
    else
    {
        STU *pb = (*head)->next;
        STU *pf = *head;

        (*head)->next = NULL;
        pf = pb->next;

        while(pf != NULL)
        {
            pb->next = *head;
            *head = pb;
            pb = pf;
            pf = pf->next;
        }

        pb->next = *head;
        *head = pb;
    }
}