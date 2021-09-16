//Implement a Doubly Linked List and develop functions to perform insertion, deletion and linear search operations.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
struct Node
{
    int data;
    struct Node *next; //next points to the next node
    struct Node *prev; //prev points to the prev node
} *head = NULL;        //points to the first node
                       //Initially, there is no node and thus no linked list, so we have initialized head with NULL

void insert(int element)
{
    struct Node *node = head; //node is structure pointer
    // If head node is not present
    if (node == NULL)
    {
        node = (struct Node *)malloc(sizeof(struct Node));  //Allocating memory
        node->data = element;
        node->next = NULL;
        node->prev = NULL;
        head = node;    //Change head to point to recently created node
    }
    else
    {
        while (node->next != NULL)
        {
            node = node->next; //traversing
        }
        // Now node is pointing to last node
        struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
        node->next = newNode;
        newNode->prev = node;
        newNode->data = element;
        newNode->next = NULL;
    }
}

int linearSearch(int searchElement)
{
    struct Node *node = head;
    int position = -1;
    int count = 1;
    while (node != NULL)
    {
        if (node->data == searchElement)
        {
            position = count;
            break;
        }
        count++;
        node = node->next;
    }
    return position;
}

int delete (int element)
{
    int removedElement = INT_MIN;
    int position = linearSearch(element);
    if (position != -1) //the element is present
    {
        // special case: deleting head node, we need to update the head of the linked list.
        if (position == 1)
        {
            struct Node *temp = head;
            removedElement = head->data;
            if (temp->next != NULL)
            {

                head = head->next;
                head->prev = NULL;
            }
            else
            {
                head = NULL;
            }

            free(temp);
        }
        else
        {

            struct Node *prev = NULL, *temp = head;
            while (position > 1)
            {
                prev = temp;
                temp = temp->next;
                position--;
            }
            // next is pointing to the node that needs to be removed
            // Case for last node
            removedElement = temp->data;
            if (temp->next == NULL)
            {
                prev->next = NULL;
            }
            // Delete in-between node
            else
            {
                prev->next = temp->next;
                temp->next->prev = prev;
            }
            free(temp);
        }
    }
    return removedElement;
}

void print()
{
    int choice;
    printf("Press '1' for Start->End\nPress '2' for End->Start\n");
    printf("\nEnter your choice\n");
    scanf("%d", &choice);
    // Printing the list from start to end
    if (choice == 1)
    {
        struct Node *node = head;
        if (node == NULL)
        {
            printf("Empty.");
        }
        else
        {
            while (node != NULL)
            {
                printf("%d->", node->data);
                node = node->next;
            }
            printf("NULL");
        }
    }
    // Printing the list from end to start
    else if (choice == 2)
    {
        struct Node *end = head;
        if (end == NULL)
        {
            printf("Empty.");
        }
        else
        {
            // Moving end to last
            while (end->next != NULL)
            {
                end = end->next;
            }

            while (end != NULL)
            {
                printf("%d->", end->data);
                end = end->prev;
            }
            printf("NULL");
        }
    }
    printf("\n");
}
int main()
{

    int option, element, deletion, searchElement;
    do
    {
        printf("\nChoose the desired option:\n");
        printf("1.Insertion\n");
        printf("2.Deletion\n");
        printf("3.Linear Search\n");
        printf("4.Display\n");
        printf("5.Exit\n");
        scanf("\n%d", &option);
        switch (option)
        {
        case 1:
            printf("\nEnter the element you want to insert:\n");
            scanf("%d", &element);
            insert(element);
            break;
        case 2:
            printf("\nEnter the element you want to delete:\n");
            scanf("%d", &element);
            deletion = delete (element);
            if (deletion != INT_MIN)
            {
                printf("%d Removed.\n", deletion);
            }
            else
            {
                printf("Element not found\n");
            }
            break;
        case 3:
            printf("\nEnter the element you want to search for:\n");
            scanf("%d", &searchElement);
            int search = linearSearch(searchElement);
            if (search != -1)
            {
                printf("\nElement found at position : %d\n", search);
            }
            else
            {
                printf("\nElement not found\n\n");
            }
            break;
        case 4:
            print();
            break;
        case 5:
            exit(0);
            break;

        default:
            printf("Please enter the correct option\n");
            break;
        }
    } while (option != 5);

    return 0;
}