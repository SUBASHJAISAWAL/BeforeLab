#include<stdio.h>
#include<stdlib.h>
#define max 5
int queue[max];
int front=-1, rear=-1;

void insert(int x){
    if(front==-1 && rear==-1)
    {
        front=rear=0;
        queue[rear]=x;
    }
    else if(rear+1==front)
    {
        printf("The queue is full, overflow!");
    }
    else
    {
        rear=(rear+1)%max;
        queue[rear]=x;
    }
}
void delete()
{
    if(front==-1&& rear==-1)
    {
        printf("The queue is empty,underflow!");
    }
    else if(front==rear)
    {
        printf("Deleted %d from the queue. ",queue[front]);
        front=rear=-1;
    }
    else
    {
        printf("Deleted %d from the queue.\n",queue[front]);
        front=(front+1)%max;
    }
}
void display()
{

    if(front==-1)
    {
        printf("Queue is empty, nothing to display.");
    }
    printf("queue elements are:\n");
    for (int i=front;i<=rear;i++)
    {
        printf("%d\n",queue[i]);
    }
}

int main()
{
    int choice;
    while(1)
    {
        printf("Enter your choice:\n");
        printf("1. Insert\n2. Delete\n3.Display\n4.Exit\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:printf("Enter the item to insert: ");
                    int item;
                    scanf("%d",&item);
                    insert(item);
                    break;
            case 2: delete();
                    break;
            case 3: display();
                    break;
            case 4: exit(0);
            default: printf("Invalid input! Try again");
        }
    }
}
