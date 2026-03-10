#include <stdio.h>

#define MAX 5
typedef int Itemtype;
typedef struct{
    char platNomor[15];
    char jenisKendaraan[15];
    char waktu[115];
} dataParkir;
typedef struct {
    dataParkir item[MAX];
    int count;
    int front;
    int rear;
} Queue;

void Inisialisasi (Queue *q);
int Penuh (Queue q);
int Kosong (Queue q);
void Enqueue (Queue *q, dataParkir x);
dataParkir Dequeue(Queue *q);
void printqueue(Queue q);
int menu();
dataParkir inputData();

int main(){
    Queue q1;
    Inisialisasi(&q1);
    char jawab;

    do{
        int pilih = menu();
        if(pilih == 1){
            dataParkir data = inputData();
            Enqueue(&q1, data);
            printqueue(q1);
        } else if(pilih == 2){
            dataParkir h = Dequeue(&q1);
            printf("Kendaraan Keluar:\n");
            printf("%s | %s | %s\n",
                h.jenisKendaraan,
                h.platNomor,
                h.waktu
            );

            printf("Kendaraan dalam Queue:\n");
            printqueue(q1);        
        } else {
            printqueue(q1);
        }
        printf("Lanjut (Y/N): ");
        scanf(" %c", &jawab);
        printf("\n");
    } while(jawab == 'Y' || jawab == 'y');
}

void printqueue(Queue q){
    if(q.front <= q.rear){
        for(int i = q.front; i < q.rear; i++){
            printf("%s | %s | %s\n", 
                q.item[i].jenisKendaraan,
                q.item[i].platNomor,
                q.item[i].waktu
            );
        }
    } else {
        for(int i = q.front; i < MAX; i++){
            printf("%s | %s | %s\n", 
                q.item[i].jenisKendaraan,
                q.item[i].platNomor,
                q.item[i].waktu
            );
        }
        for(int i = 0; i < q.rear; i++){
            printf("%s | %s | %s\n", 
                q.item[i].jenisKendaraan,
                q.item[i].platNomor,
                q.item[i].waktu
            );
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

void Enqueue (Queue *q, dataParkir x)
{
    if(Penuh(*q))
        printf("Queue Penuh, Data tidak dapat disimpan\n");
    else {
        q->item[q->rear]=x;
        q->rear =(q->rear+1) % MAX;
        q->count++;
    }
}

dataParkir Dequeue(Queue *q)
{
    dataParkir temp;
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

    printf("1. Enqueue Kendaraan\n");
    printf("2. Dequeue Kendaraan\n");
    printf("3. View Kendaraan\n");

    printf ("Pilih: "); 
    scanf("%d", &pilih);
    printf("\n");

    return pilih;
}

dataParkir inputData(){
    dataParkir data;

    printf("Masukkan Plat Nomor: ");
    scanf("%s", &data.platNomor);

    printf("Masukkan Jenis Kendaraan: ");
    scanf("%s", &data.jenisKendaraan);

    printf("Masukkan Waktu: ");
    scanf("%s", &data.waktu);
    return data;
}
