/*
    Inserting a node at the beginning of the linked list in C.
        - By Bhuwan Khatiwada
        - Date: 10th July, 2024
*/

#include<stdio.h>
#include<stdlib.h>

struct Node 
{
    int value;
    struct Node* next;
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

struct Node* insert_at_beginning(struct Node* top, struct Node* node)
{
    node->next = top;
    top = node;
    return top;
}

void free_memory(struct Node* top)
{
    while(top!=NULL)
    {   
        struct Node* temp;
        temp = top->next;
        printf("\nFreeing memory at: %p", (void*)top);
        free(top);
        top= temp;
    }
    printf("\nRemoved all allocated memory.");

}


int main()
{
    struct Node* head; // pointer that points to the head of the linked list.
    head = NULL;

    int n;
    printf("Enter the number of elements:");
    scanf("%d", &n);
    printf("Initializing a linked list for %d elements.\n", n);

    for(int i=0; i<n; i++)
    {
        struct Node* temp;
        temp = (struct Node*) malloc(sizeof(struct Node));
        // printf("\n%p", (void *)temp); to see the adresses of created nodes.

        printf("New node created at address: %p", (void *)temp);

        int data;
        printf("\nEnter the value of %dth element:", i+1);
        scanf("%d", &data);
        temp->value = data;
        temp -> next = NULL;
        printf("\nYou entered: %d", temp -> value);

        head = insert_at_beginning(head, temp);
        printf("\nNew head at:%p", (void *)head); 
        
        printf("\nThe updated list is:\n");
        display_list(head);
        printf("\n\n");

    }
    printf("End of list reached.");

    free_memory(head);
    return 0;
}