/*
    Implementation of Linked List in C.
        - By Bhuwan Khatiwada
        - Date: 11th July, 2024
*/ 

# include<stdio.h>
# include<stdlib.h>
#include<string.h>

int NUM =0;

struct Node
{
    int value; // data field of node.
    struct Node* next; // address field of node.
};

void display_list(struct Node* base)
{
    printf("\nThe updated list is:\n");
    while(base != NULL)
    {
        int val = base -> value;
        printf("%d -> ", val);
        base = base -> next;
    }
}


// void insert_nodev0(struct Node* top, struct Node* node)
// {
//         if(top == NULL) // create a link to the head of list
//         {
//             top = node;
//         }
//         else // create a link from end of list to new node.
//         {
//             struct Node* pointer = top;
//             while(pointer -> next != NULL)
//             {
//                 pointer = pointer -> next;
//             }
//             pointer -> next = node;
//         }
// }

void insert_node(struct Node* top, struct Node* node)
{
    struct Node* pointer = top;
    while(pointer -> next != NULL)
    {
        pointer = pointer -> next;
    }
    pointer -> next = node;     
}

struct Node* delete_node(struct Node* top, int total_node)
{
    int pos;
    printf("\nEnter the position of element that you want to delete:");
    scanf("%d", &pos);

    if (pos==1 || total_node==1)
    {
        struct Node* temp_head = top;
        top = top->next;
        free(temp_head);
        NUM--;
        return top;
    }
    else if (pos >= 1)
    {   
        if(pos> total_node)
        {
            pos = total_node;
        }
        struct Node* temp_head = top;

        for(int i=1; i <= pos-2; i++)
        {
            temp_head = temp_head->next;
        }

        struct Node* node = temp_head->next;
        temp_head->next = node -> next;

        free(node);
        NUM--;
        
    }

    else
    {
        printf("Invalid Input!!!");
       
    }
    return top;
}


int main()
{
    struct Node* head;
    head = NULL;

    // Get the number of elements in the list.
    // int n;
    printf("Enter the number of elements:");
    scanf("%d", &NUM);
    printf("Initializing a linked list for %d elements.\n", NUM);

    /* Loop to insert elements in the linked list.*/
    for(int i=0; i<NUM; i++)
    {
        struct Node* temp;
        temp = (struct Node*) malloc(sizeof(struct Node));

        printf("New node created at address: %p", (void *)temp);

        int data;
        printf("\nEnter the value of %dth element:", i+1);
        scanf("%d", &data);
        temp->value = data;
        temp -> next = NULL;
        printf("\nYou entered: %d", temp -> value);

        if(head == NULL) // create a link to the head of list
        {
            head = temp;
        }
        else // create a link from end of list to new node.
        {
            insert_node(head, temp);   
        }
        
        
        display_list(head);
        printf("\n\n");

    }
    printf("End of list reached.\n");

    while(1)
    {   
        char ans;

        printf("\nDo you want to delete an elements(y/n): ");
        scanf(" %c", &ans); // The whitespace at the start accounts for the whitespace characters that may be remaining inthe input buffer.
        printf("You choose: %c", ans);

        if(ans=='y'||ans=='Y')
        {
            head = delete_node(head, NUM);
            // NUM-- ;
            if (NUM==0)
            {
                printf("The List is empty. No more elements left.\n");
                break;
            }
            else
            {
                display_list(head);
                printf("\n\n");
            }
        }
        else if(ans=='n'||ans =='N')
        {
            break;
        }
        else
        {
            printf("\nInvalid Input!!!");
        }


    }

    return 0;
}