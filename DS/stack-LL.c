#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *next;
};

struct Node *top = NULL;

void push(int item)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if (newNode == NULL)
    {
        printf("Stack Overflow\n");
        return;
    }
    newNode->data = item;
    newNode->next = top;
    top = newNode;
}
int pop()
{
    if (top == NULL)
    {
        printf("stack Underflow\n");
        return -1;
    }
    int item = top->data;
    struct Node *temp = top;
    top = top->next;
    free(temp);
    return item;
}

int peek()
{
    if (top == NULL)
    {
        printf("Stack is empty\n");
        return -1;
    }
    return top->data;
}

int main()
{
    push(1);
    push(2);
    push(3);

    printf("top elements: %d\n", peek());

    printf("Popping elements: ");
    while (top != NULL)
    {
        printf("%d ",pop());
    }
    printf("\n");

    return 0;
}
