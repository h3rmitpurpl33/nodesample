#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node
{
    char name[100];
    int code;
    float grd;
    node *next;
}node;

node *head;
node *tail;

void add_queue(const node *p);
void show_queue(void);
void pop(void);
void free_queue(void);

int read_text(char str[],int size,int flag);

int main(){
    int sel;
    node n;
    head = NULL;

    while(1){
        printf("\nMenu selections\n");
        printf("-----------\n");
        printf("1. Add Student\n");
        printf("2. View all Students\n");
        printf("3. View last Students\n");
        printf("4. Delete top Student\n");
        printf("5. Exit\n");

        printf("\nEnter Choice:  ");
        scanf("%d",sel);

        switch(sel)
        {
        case 1:
            getchar();
            printf("Name:  ");
            read_text(n.name,sizeof(n.name),1);

            printf("Code : ");
            scanf("%d" , &n.code);

            printf("Grade : ");
            scanf("%f",&n.grd);

            add_queue(&n);
            break;
        
            case 2:
                if(head!=NULL)
                {
                    show_queue();
                }else{
                    printf("\nThe queue is empty\n");
                }
            break;

            case 3:
                if(head!=NULL){
                    printf("\nC:%d N:%s G:%.2f\n\n",tail->code,tail->name,tail->grd);
                }else{
                    printf("\nThe queue is Empty");
                }
            break;

            case 4:

            if(head != NULL){
                pop();
            }else{
                printf("\nThe queue is empty");
            }

            break;

            case 5:

            if(head != NULL){
                free_queue();
            }
            return 0;

            default:
                printf("\nWrong choice\n");
            break;
            
        }

    }
    return 0;   
}

int read_text(char string[], int size,int flag)
{
    int len;
    if(fgets(string,size,stdin)==NULL)
    {
        printf("error : fgets() failed\n");
        exit(EXIT_FAILURE);
    }
    len = strlen(string);
    if(len>0)
    {
        if(flag && (string[len-1] == '\n'))
        {
            string[len-1] = '\0';
            len-- ;
        }
    }else
    {
       printf("error : no input\n");
       exit(EXIT_FAILURE);
    }
    return len;
}

void add_queue(const node *p){
    node *new_node;

    new_node = (node*) malloc(sizeof(node));
    if(new_node = NULL)
    {
        printf("error : not available memory\n");
        exit(EXIT_FAILURE);
    }

    *new_node = *p;
    new_node->next = NULL;

    if(head == NULL)
    {
        head = tail = new_node;
    }else{
        tail->next = new_node;
        tail = new_node;
    }
}

void show_queue(void)
{
    node *p;

    p = head;
    printf("\n***** Student data *****\n\n");
    while(p != NULL)
    {
        printf("C:%d N:%s G:%.2f\n\n" , p->code,p->name,p->grd);
        p = p->next;
    }
}

void pop(void)
{
    node *p;
    p = head->next;
    printf("\nStudent with code = %d is deleted\n",head->code);
    free(head);
    head = p;
}

void free_queue(void)
{
    node *p , *next_node;

    p = head;

    while(p!=NULL)
    {
        next_node = p->next;
        free(p);
        p = next_node;
    }
}
