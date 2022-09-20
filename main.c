#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//linked list node
struct Node {
    int data;
    struct Node* next;
};

void append(struct Node** head, int value)
{
    // Create dynamic node
    struct Node* node
        = (struct Node*)malloc(sizeof(struct Node));
    if (node == NULL) {
        // checking memory overflow
        printf("Memory overflow\n");
    }
    else {
        node->data = value;
        node->next = NULL;
        if (*head == NULL) {
            *head = node;
        }
        else {
            struct Node* temp = *head;

            // finding last node
            while (temp->next != NULL) {
                temp = temp->next;
            }

            // adding node at last position
            temp->next = node;
        }
    }
}

void prepend(struct Node** head_ref, int new_data)
{
    //1. allocate node
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));

    //2. put in the data
    new_node->data  = new_data;

    //3. Make next of new node as head
    new_node->next = (*head_ref);

    //4. move the head to point to the new node
    (*head_ref)    = new_node;
}

static void reverse(struct Node** head_ref)
{
    struct Node* prev = NULL;
    struct Node* current = *head_ref;
    struct Node* next = NULL;
    while (current != NULL) {
        // Store next
        next = current->next;

        // Reverse current node's pointer
        current->next = prev;

        // Move pointers one position ahead.
        prev = current;
        current = next;
    }
    *head_ref = prev;
}

void insert(struct Node** head){
    //UI
    int pos, x;
    printf("type the position of the new node: \n");
    printf(" > ");
    scanf("%d", &pos);
    printf("type the value of the new node: \n");
    printf(" > ");
    scanf("%d", &x);

    //Logic
    struct Node* temp1 = (struct Node*)malloc(sizeof(struct Node));
    temp1->data = x;
    temp1->next = NULL;
    if (pos == 1){
        temp1->next = *head;
        *head = temp1;
        return;
    }

    struct Node* temp2 = *head;
    for (int i = 0; i < pos-2; i++){
        temp2 = temp2 -> next;
    }

    temp1->next = temp2->next;
    temp2->next = temp1;
}


void remove_value(struct Node** head){
    //UI
    int pos;
    printf("type the position of the node to delete: ");
    printf(" > ");
    scanf("%d", &pos);

    //Logic
    struct Node* temp1 = *head;

    if(pos==1){
        *head = temp1->next; //head now points to seconde node
        free(temp1);
        return;
    }
    for (int i = 0; i < pos-2; i++)
        temp1 = temp1->next;
    //temp1 points to (n-1)th Node
    struct Node* temp2 = temp1->next; //nth node
    temp1->next =temp2->next; //(n+1)th node
    free(temp2);
}
//for sort
   struct LinkedNode// structure for linked list
        {
            int data;
            struct LinkedNode *next;
        }*start = NULL;

void sort()
    {
    struct LinkedNode *node=NULL, *temp = NULL;
    int tempvar;//temp variable to store node data
    node = start;
    //temp = node;//temp node to hold node data and next link
    while(node != NULL)
    {
        temp=node;
        while (temp->next !=NULL)//travel till the second last element
        {
           if(temp->data > temp->next->data)// compare the data of the nodes
            {
              tempvar = temp->data;
              temp->data = temp->next->data;// swap the data
              temp->next->data = tempvar;
            }
         temp = temp->next;    // move to the next element
        }
        node = node->next;    // move to the next node
    }
}


bool search_value(struct Node* head, int x)
{
    struct Node* current = head; // Initialize current
    while (current != NULL) {
        if (current->data == x)
            return true;
        current = current->next;
    }
    return false;
}


int main()
{

    struct Node* head = NULL;
    int first_choice,second_choice, number_of_elements;
    //logic variable
    int exit = 0;


    printf("create a linked list?\n [1] yes\n [2] no\n");
    printf(" > ");
    scanf("%d", &first_choice);

    switch (first_choice)
    {
    case 1:
        printf("----------------------------------------\n");
        printf("Type number of list's elements: ");
        scanf("%d",&number_of_elements);
        for (int i = 0; i < number_of_elements; i++){
                int data;
                scanf("%d", &data);
                append(&head, data);
        }
    break;
    case 2:
        printf("you can try something from here or exit bu typing 0");
        break;
    default:
        break;
    }


    while(exit == 0) {
        printf(" \n _______________________________  Meniu  _______________________________ \n");
        printf(" \n |1. Append                                                            |");
        printf(" \n |2. Prepend                                                           |");
        printf(" \n |3. Reverse                                                           |");
        printf(" \n |4. Add a value to the specific index                                 |");
        printf(" \n |5. Remove a value to the specific index                              |");
        printf(" \n |6. Sort the linked lis, with re-arranging the cells                  |");
        printf(" \n |7. Search for a value                                                |");
        printf(" \n |8.Join two linked list                                               |");
        printf(" \n |9.Backwards traversal                                                |");
        printf(" \n |0.Exit the program                                                  |");
        printf(" \n _______________________________________________________________________ \n");

        printf(" \n\n\nChoose an option: ");
        scanf("%d", &second_choice);

        switch (second_choice)
        {

           case 1: {
                int data;
                scanf("%d", &data);
                append(&head, data);

                break;
           }
           case 2: {
                int data;
                scanf("%d", &data);
                prepend(&head, data);
                break;
           }

           case 3: {
           //reverse the list
                reverse(&head);
           break;
           }
           case 4:
           //add value to a specific index
                insert(&head);
           break;

           case 5:
           //add value to a specific index
                remove_value(&head);
           break;

           case 6:
           //sorting with re-arranging the cells
                sort();
           break;

            case 7:{
                int data;
                scanf("%d", &data);
                if (search_value(head, data)) {
                    printf("Yes"); }
                else {
                printf("No"); }
                printf("\n");

                break;
            }


           case 0:
           printf(" \n Program had been stoped. ");
           exit=1;
           break;


           default:
              break;

        }
    }
  return 0;
}

