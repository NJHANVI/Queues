#include<stdio.h>
#include<stdlib.h>
#define Max_Size 100
typedef struct queues{
    int items[Max_Size];
    int rear;
    int front;
} Queues;

Queues* create(){
    Queues* new = (Queues*)malloc(sizeof(Queues));
    new->front = -1;
    new->rear= -1;
    return new;
}

Queues* is_empty(Queues* q){
    return  q->front == -1;
}

Queues* is_full(Queues* q){
    return q->rear== Max_Size-1;
}


Queues* enqueue(Queues* q ,int item){
    if(is_empty){
        
        q->front=0;//setting operation
        q->rear+=1;
        q->items[q->rear] = item;
        return 0;
    }

    else if(is_full){
        printf("Queue is full");
        exit(1);
    }

    else{
        q->rear+=1;
        q->items[q->rear]=item;
    }

    return q;

}

Queues* dequeue(Queues* q){
    if(is_empty(q)){
        printf("Queue is empty");
        exit(1);
    }
    else if(!is_empty(q) && (q->front == q->rear) ){
        printf(" element being dequed -%d",q->items[q->front]);
        q->front= -1;
        q->rear= -1;
        return q;
    }
    else {
        printf(" element being dequed -%d ",q->items[q->front]);
        q->front+=1;
    }


    return q;
}


int print_queue( Queues* q){
    int s= q->front;
    while(s<=q->rear){
        printf("%d-",q->items[s]);
        s++;
    }
    return 0;
}

int main(){
    Queues* q= create();
    enqueue(q , 1);
    enqueue(q , 2);
    enqueue(q , 3);
    enqueue(q , 4);
    enqueue(q , 5);
    enqueue(q , 6);
    print_queue(q);
    printf("\n");
    dequeue(q);
    printf("\n");
    print_queue(q);
    return 0;


}
