#include <stdio.h>
#include <stdlib.h>

// Queue node
struct node
{
    int data;
    struct node *next;
};

struct node *front = NULL;
struct node *rear = NULL;

// Enqueue
int enqueue(int data)
{
    struct node *new = (struct node *)malloc(sizeof(struct node));

    // Queue is empty
    if (front == NULL)
    {
        new->data = data;
        new->next = NULL;

        front = rear = new;
    }

    // Queue is not empty
    else
    {
        struct node *new = (struct node *)malloc(sizeof(struct node));
        new->data = data;
        new->next = NULL;

        rear->next = new;
        rear = new;
    }

    return 1;
}

// Display Queue
int display()
{

    // Queue is empty
    if (front == NULL)
    {
        printf("Queue is empty\n");
        return 1;
    }

    struct node *index = front;

    printf("\nQueue : \n");

    while (index != NULL)
    {
        printf("%d - ", index->data);
        index = index->next;
    }
}

// Dequeue
int dequeue()
{

    // Queue is empty
    if (front == NULL)
    {
        printf("Queue is empty");
        return 1;
    }

    struct node *temp = front;
    front = front->next;

    free(temp);

    return 1;
}

int main()
{

    enqueue(10);
    enqueue(20);
    enqueue(30);

    display();

    dequeue();
    display();
    return 1;
}