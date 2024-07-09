/*
    Implementation of Linked List in C.
        - By Bhuwan Khatiwada
        - Date: 9th July, 2024
*/ 

# include<stdio.h>
# include<stdlib.h>

struct Node
{
    int value; // data field of node.
    struct Node* next; // address field of node.
};

void display_list(struct Node* base)
{
    while(base -> next != NULL)
    {
        int val = base -> value;
        printf("%d -> ", val);
        base = base -> next;
    }
}


int main()
{
    // struct Node* head = NULL; (alternative way)
    struct Node* head;
    head = NULL;
    // printf("%p",(void *)head); prints (nil)

    // Get the number of elements in the list.
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

        if(head == NULL) // create a link to the head of list
        {
            head = temp;
        }
        else // create a link from end of list to new node.
        {
            struct Node* pointer = head;
            while(pointer -> next != NULL)
            {
                pointer = pointer -> next;
            }
            pointer -> next = temp;
        }

        printf("\nThe updated list is:\n");
        display_list(head);
        printf("\n\n");

    }


    return 0;
}