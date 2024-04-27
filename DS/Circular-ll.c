#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *last = NULL;

void addToEmpty(int data)
{
    if (last != NULL)
        return;

    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    last = newNode;
    last->next = last;
}

void addToFront(int data)
{
    if (last == NULL)
    {
        addToEmpty(data);
        return;
    }

    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = last->next;
    last->next = newNode;
}

void addToEnd(int data)
{
    if (last == NULL)
    {
        addToEmpty(data);
        return;
    }

    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = last->next;
    last->next = newNode;
    last = newNode;
}

void display()
{
    if (last == NULL)
    {
        printf("List is empty\n");
        return;
    }

    struct Node *temp = last->next;
    do
    {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != last->next);
    printf("\n");
}

int main()
{
    addToEnd(1);
    addToEnd(2);
    addToEnd(3);
    addToFront(4);

    display();

    return 0;
}
