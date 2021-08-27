//Implement a Queue using Array and develop functions to perform enqueue and dequeue operations
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <conio.h>
struct Queue
{
    int *data;       //the array which has items
    int max_capacity; // max_capacity is allocated at the time of creation of the queue
    // if number of elements = max_capacity, the queue is full
    int front; //index of the front item, starts from 0
    int rear;  //index of the rear item, starts from 0
};

int no_of_items(struct Queue *queue)
{
    // printf("calculating no_of_items...\n");
    if (queue->rear == -1 && queue->front == -1)
    {
        return 0;
    }
    else if (queue->rear >= queue->front)
    {
        return (queue->rear - queue->front) + 1;
    }
    else
    {
        return (((queue->max_capacity) - queue->front)) + (queue->rear + 1);
    }
}

int is_full(struct Queue *queue)
{
    // input: the address of the queue
    // output: 1 if full, 0 if not full
    // it checks if the queue is full or not
    if (no_of_items(queue) == queue->max_capacity)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int enqueue(struct Queue *queue, int item)
{
    // input: the address of the queue, item
    // output: 1 if inserted, 0 if not inserted
    // it checks if the queue is full or not
    // increments the rear (circularly) and it adds one element at the rear
    // printf("no_of_items = %d", no_of_items(queue));
    printf("enQueue %d:\n", item);
    if (is_full(queue) == 0)
    {
        // increment the rear (circularly) and add one element at the rear
        if (no_of_items(queue) == 0)
        {
            // printf("empty\n");
            // queue->front = -1 as the queue is empty
            // we have to make it 0 as now we will insert an item
            queue->front = 0;
        }
        queue->rear = (queue->rear + 1) % (queue->max_capacity); // incrementing the rear circularly
        queue->data[queue->rear] = item;
        return 1;
    }
    else
    {
        return 0;
    }
}

int dequeue(struct Queue *queue)
{
    // input: the address of the queue
    // output: the item removed, NULL if the queue is empty
    // check if the queue is empty
    printf("\n\tinside dequeue function...\n");
    if (no_of_items(queue) != 0)
    {
        // copy the front item in a variable (temp)
        int temp = queue->data[queue->front];
        // increment front
        // some change here is needed
        if (queue->front == queue->rear)
        {
            // the front should never cross the rear
            // it means that the queue is going to become empty after this deQueue operation
            queue->front = -1;
            queue->rear = -1;
        }
        else
        {
            queue->front = (queue->front + 1) % (queue->max_capacity); 
        }
        // return the variable (temp)
        return temp;
    }
    else
    {
        return INT_MIN;
    }
}

void print_queue_details(struct Queue *queue)
{
    printf("max_capacity=%d\t  front=%d\t  rear=%d\t \n", queue->max_capacity, queue->front, queue->rear);
}

void print_queue(struct Queue *queue)
{
    int i;
    printf("queue: ");
    i = queue->front;
    if (no_of_items(queue) != 0)
    {
        do
        {
            printf("data[%d]= %d   ", i, queue->data[i]);
            i = (i + 1) % (queue->max_capacity);
        } while (i != (queue->rear + 1) % queue->max_capacity);
        printf("\n");
    }
}

int main()
{
    struct Queue queueA;
    int max_size, choice, element, dequeued, value;
    printf("Enter the size of the queue : ");
    scanf("%d", &max_size);
    queueA.max_capacity = max_size;
    queueA.front = -1;                                             
    queueA.rear = -1;                                              
    queueA.data = (int *)malloc(queueA.max_capacity * sizeof(int)); //memory allocation for the queue
    printf("no_of_items = %d", no_of_items(&queueA));
    do
    {
        printf("\t\n QUEUE OPERATIONS \n");
        printf(" 1. enqueue \n 2. dequeue \n 3. Printing Elements \n 4. Exit \n");
        printf("Enter your choice : ");
        scanf("%d", &choice); // input choice from the user
        switch (choice)
        {
        case 1:
            printf("\n ENQUEUE OPERATION \n");
            printf("Enter the element you want to enQueue in the queue : ");
            scanf("%d", &element);
            if (no_of_items(&queueA) == max_size)
            {
                printf("Queue is full and could not add any item! \n");
            }
            else
            {
                enqueue(&queueA, element);
                printf("\n%d is added.\n", element);
            }
            break;
        case 2:
            printf("DEQUEUE OPERATION \n");
            value = dequeue(&queueA);

            if (value != INT_MIN)
            {
                printf("\n%d is removed\n", value);
            }
            else
            {
                printf("Queue is empty and could not remove any item! \n");
            }
            break;

        case 3:
            print_queue_details(&queueA);
            print_queue(&queueA); 
            break;
        case 4:
            exit(0);
        default:
            printf("\n \t WRONG CHOICE ENTERED !! \n");
            break;
        }
        printf("\nPress enter to continue... \n");
        getch();
    } while (1);
    return 0;
} 