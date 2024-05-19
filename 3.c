#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct {
    Node* front;
    Node* rear;
    int size;
} Que;

Que* createQueue() {
    Que* queue = (Que*)malloc(sizeof(Que));
    if (queue == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    queue->front = NULL;
    queue->rear = NULL;
    queue->size = 0;
    return queue;
}

int isEmpty(Que* queue) {
    return queue->size == 0;
}

void enqueue(Que* queue, int item) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    if (new_node == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    new_node->data = item;
    new_node->next = NULL;
    if (isEmpty(queue)) {
        queue->front = new_node;
        queue->rear = new_node;
    } else {
        queue->rear->next = new_node;
        queue->rear = new_node;
    }
    queue->size++;
    printf("Enqueued %d to the queue\n", item);
}

int dequeue(Que* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty, cannot dequeue item\n");
        return -1;
    }
    Node* temp = queue->front;
    int item = temp->data;
    queue->front = temp->next;
    free(temp);
    queue->size--;
    if (queue->size == 0) {
        queue->rear = NULL;
    }
    printf("Dequeued %d from the queue\n", item);
    return item;
}

void displayQueue(Que* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue contents: ");
    Node* current = queue->front;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    Que* queue = createQueue();

    enqueue(queue, 10);
    enqueue(queue, 20);
    enqueue(queue, 30);
    enqueue(queue, 40);

    displayQueue(queue);

    dequeue(queue);
    dequeue(queue);

    // Display the queue
    displayQueue(queue);

    // Free the memory allocated for the queue
    free(queue);

    return 0;
}