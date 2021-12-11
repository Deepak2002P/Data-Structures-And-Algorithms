#include<stdio.h>
#include<stdlib.h>

struct CircularQueue
{
    int size;
    int f;
    int r;
    int* arr;
};

int isEmpty(struct CircularQueue *q){
    if(q->f==q->r){
        return 1;
    }
    return 0;
}

int isFull(struct CircularQueue *q){
    if((q->r+1)%q->size==q->f){
        return 1;
    }
    return 0;
}

void enqueue(struct CircularQueue *q,int val){
    if(isFull(q)){
        printf("Queue is Full\n");
    }
    else{
        q->r=(q->r+1)%q->size;
        q->arr[q->r]=val;
        printf("Enqued Element is:%d\n",val);
    }
}

int dequeue(struct CircularQueue *q){
    int a=-1;
    if(isEmpty(q)){
        printf("Queue is Empty\n");
    }
    else{
       q->f=(q->f+1)%q->size;
       a=q->arr[q->f];
    }
    return a;
}

int main(){
    struct CircularQueue q;
    q.size=4;
    q.f=q.r=0;
    q.arr=(int*)malloc(q.size*sizeof(int));
    // Enqueue Few Elements
    enqueue(&q,12);
    enqueue(&q,14);
    enqueue(&q,54);
    enqueue(&q,1);
    enqueue(&q,45);
    printf("Dequeuing Element:%d\n",dequeue(&q));
    printf("Dequeuing Element:%d\n",dequeue(&q));
    printf("Dequeuing Element:%d\n",dequeue(&q));
    printf("Dequeuing Element:%d\n",dequeue(&q));
    printf("Dequeuing Element:%d\n",dequeue(&q));
    return 0;
}
