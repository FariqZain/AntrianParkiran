#include <stdio.h>

#define MAX 5
typedef int Itemtype;
typedef struct {
    Itemtype item[MAX];
    int count;
    int front;
    int rear;
} Queue;

void Inisialisasi (Queue *q);
int Penuh (Queue q);
int Kosong (Queue q);
void Enqueue (Queue *q, Itemtype x);
Itemtype Dequeue(Queue *q);
void printqueue(Queue q);
int menu();
Itemtype inputData();

int main(){
    Queue q1;
    Inisialisasi(&q1);
    char jawab;

    do{
        int pilih = menu();
        if(pilih == 1){
            Itemtype data = inputData();
            Enqueue(&q1, data);
            printqueue(q1);
        } else if(pilih == 2){
            Itemtype h = Dequeue(&q1);
            printf("Hasil Dequeue: %d\n", h);
            printqueue(q1);        
        } else {
            printqueue(q1);
        }
        printf("Lanjut: (Y/N)");
        scanf(" %c", &jawab);
    } while(jawab == 'Y' || jawab == 'y');
}

void printqueue(Queue q){
    if(q.front <= q.rear){
        for(int i = q.front; i < q.rear; i++){
            printf("%d ", q.item[i]);
        }
    } else {
        for(int i = q.front; i < MAX; i++){
            printf("%d ", q.item[i]);
        }
        for(int i = 0; i < q.rear; i++){
            printf("%d ", q.item[i]);
        }
    }
    printf("\n");
    printf("Front = %d, Rear = %d, Count = %d\n", q.front, q.rear, q.count);
}

void Inisialisasi (Queue *q)
{
	q->count=0;
    q->front = 0;
    q->rear = 0;
}

int Penuh (Queue q)
{
    return (q.count==MAX);
}

int Kosong (Queue q)
{
    return (q.count==0);
}

void Enqueue (Queue *q, Itemtype x)
{
    if(Penuh(*q))
        printf("Queue Penuh, Data tidak dapat disimpan\n");
    else {
        q->item[q->rear]=x;
        q->rear =(q->rear+1) % MAX;
        q->count++;
    }
}

Itemtype Dequeue(Queue *q)
{
   Itemtype temp = -1;
   if(Kosong(*q)) {
      printf("Queue Kosong, tidak dapat mengambil data\n");
      return temp;
   }
   else {
      temp=q->item[q->front];
      q->front = (q->front+1) % MAX;
      q->count--;
      return(temp);
   }
}

int menu(){
    int pilih;

    printf("Menu\n");

    printf("1. Enqueue\n");
    printf("2. Dequeue\n");
    printf("3. View\n");

    printf ("Pilih: "); 
    scanf("%d", &pilih);

    return pilih;
}

Itemtype inputData(){
    Itemtype data;

    printf("Masukkan data: ");
    scanf("%d", &data);

    return data;
}