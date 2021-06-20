#include <stdio.h>
#include <stdlib.h>

struct Stack
{
    int size; //size is the size of the stack
    int top;  //top is the index of the topmost element.
    int *array;
};
int isEmpty(struct Stack *stack) //Function for checking whether the stack is empty or not.
{
    if (stack->top == -1)
    {
        return 1; //Return 1 means the Stack is empty
    }
    else
    {
        return 0;
    }
}
int isFull(struct Stack *stack) //Function for checking whether the stack is full or not
{
    if (stack->top == stack->size - 1)
    {
        return 1;  //Return 1 means Stack is full
    }
    else
    {
        return 0;
    }
}
void push(struct Stack *stack, int element) //Function for pushing an element into the stack.
{
    if (isFull(stack)) //Checking whether the stack is full or not
    {
        printf("\nStack is Full Cannot push %d to the stack!\n", element);
    }
    else
    {
        stack->top++;              
        stack->array[stack->top] = element; //Inserting the element at the topmost index
        printf("Element Pushed Succesfully\n");
    }
}

int pop(struct Stack *stack)
{
    if (isEmpty(stack)) //Condition whether the stack is empty or not.
    {
        printf("\nCannot pop from an empty stack\n");
        return 1;
    }
    else
    {
        int element = stack->array[stack->top];
        stack->top--;
        printf("\nElement Popped Succesfully!\n");
        return element;
    }
}
void display(struct Stack *stack) //Function for printing the elements in the stack.
{
    int index;
    if (stack->top == -1)
    {
        printf("\nThe stack is empty.\n");
    }
    else
    {
        printf("\nThe elements of the stack are:\n");
        for (index = stack->top; index >= 0; index--)
        {
            printf("%d\n", stack->array[index]);
        }
    }
}

int stackTop(struct Stack *stack) //Function to print the topmost element of the stack
{
    if (isEmpty(stack))
        printf("\nNo element present\n");
    else
        printf("\nThe topmost element is: %d\n", stack->array[stack->top]);
}

int main()
{
    int option, element;
    struct Stack *stack = (struct Stack *)malloc(sizeof(struct Stack));  //Creating an instance

    printf("Enter the size of the stack:\n");
    scanf("%d", &stack->size);
    stack->top = -1;
    //Initializing the top to -1 which implies that there are no elements present in the stack.
    stack->array = (int *)malloc(stack->size * sizeof(int));
    //Allocating memory for elements to be stored in the stack.
    do
    {
        printf("\nHere are the list of operations you can perform!\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Display the elements\n");
        printf("4. Display the Topmost element of stack\n");
        printf("5. Exit\n\n");
        scanf("%d", &option);
        switch (option)
        {
        case 1: //Case for pushing an element in the stack.
            printf("\nEnter the element you want to push:\n");
            scanf("%d", &element);
            push(stack, element);
            break;
        case 2: //Case for popping an element in the stack.
            pop(stack);
            break;
        case 3: //Case for printing the elements in the stack.
            display(stack);
            break;
        case 4: //For printing the topmost element of the stack.
            stackTop(stack);
            break;
        case 5: //For exiting 
            exit(0);
            break;

        default:
            printf("\nPlease enter the correct number!\n");
            break;
        }
    }while(option!=5); //Condition for terminating the loop.
    free(stack);
    return 0;
}