#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Stack
{
    char *array; // stores the elements in the stack
    int top;     // top is the index of the topmost element
    int maxSize; // maxSize is the maximum size of the stack
};

int isFull(struct Stack *stack) // Function for checking whether the stack is full or not
{
    if (stack->top == stack->maxSize - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int isEmpty(struct Stack *stack) // Function for checking whether the stack is empty or not
{
    if (stack->top == -1) // condition for empty stack
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void push(struct Stack *stack, char element) //Function for pushing an element into the stack.
{
    if (isFull(stack))
    {
        printf("\nStack is Full, cannot push %d to the stack!\n", element);
    }
    else
    {
        stack->top++;
        stack->array[stack->top] = element; //Inserting the element at the topmost index
    }
}

int pop(struct Stack *stack) //Function for popping the element from the stack
{
    if (isEmpty(stack))
    {
        return '\0';
    }
    else
    {
        int character = stack->array[stack->top];
        stack->top--;
        return character;
    }
}

int main()
{
    int sizeOfExpression, index;
    char expression[50];
    struct Stack stack;
    stack.top = -1; // initializing top to -1 as initially no elements are present

    printf("\nEnter the expression :\n ");
    gets(expression);                                           // Input the expression using gets()
    sizeOfExpression = strlen(expression);                      // strlen is used to find the length of the string
    stack.maxSize = sizeOfExpression;                           // Assigning the size of the expression as the maximum size of the stack.
    stack.array = (char *)malloc(stack.maxSize * sizeof(char)); // Allocating memory for elements to be stored in the stack.

    for (index = 0; index < sizeOfExpression; index++)
    {
        if (expression[index] == '(' || expression[index] == '{' || expression[index] == '[')
        {
            push(&stack, expression[index]); // if the character is the starting bracket,then push into the stack.
            continue;
        }
    
        if (expression[index] == ')' || expression[index] == '}' || expression[index] == ']')
        {
            // if the character is a closing bracket, checking if the character at topmost position is its pair or not
            if ((stack.array[stack.top] == '(' && expression[index] == ')') || (stack.array[stack.top] == '{' && expression[index] == '}') || (stack.array[stack.top] == '[' && expression[index] == ']'))
            {
                pop(&stack);
            }
            else
            {
                printf("\nUnbalanced Expression\n"); 
                return 0;
                break;
            }
        }
    }
    
        if (isEmpty(&stack))
        {
            // if the stack is empty, the expression is balanced.
            printf("\nBalanced Expression\n");
        }
        else
        {
            // if the stack is not empty, the expression is not balanced.
            printf("\nUnbalanced Expression\n");
        }
    
     return 0;
}