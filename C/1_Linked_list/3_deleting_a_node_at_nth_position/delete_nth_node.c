/*
    Implementation of Linked List in C.
        - By Bhuwan Khatiwada
        - Date: 11th July, 2024
*/ 

# include<stdio.h>
# include<stdlib.h>
#include<string.h>

struct Node
{
    int value; // data field of node.
    struct Node* next; // address field of node.
};

void display_list(struct Node* base)
{
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


int main()
{
    struct Node* head;
    head = NULL;

    // Get the number of elements in the list.
    int n;
    printf("Enter the number of elements:");
    scanf("%d", &n);
    printf("Initializing a linked list for %d elements.\n", n);

    /* Loop to insert elements in the linked list.*/
    for(int i=0; i<n; i++)
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
        
        printf("\nThe updated list is:\n");
        display_list(head);
        printf("\n\n");

    }
    printf("End of list reached.\n");

    while(1)
    {   
        string ans;
        printf("\nDo you want to delete an elements(y/n):");
        scanf("%c", &ans);

        if(ans=="y"||ans=="Y")
        {
            continue;
        }
        else if(ans=="n"||ans =="N")
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