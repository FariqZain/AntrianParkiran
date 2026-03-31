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
} Stack;

void Inisialisasi (Stack *s);
int Penuh (Stack s);
int Kosong (Stack s);
void Push (Stack *s, dataParkir x);
dataParkir Pop(Stack *s);
void printstack(Stack s);
int menu();
dataParkir inputData();

int main(){
    Stack s1;
    Inisialisasi(&s1);
    char jawab;

    do{
        int pilih = menu();
        if(pilih == 1){
            dataParkir data = inputData();
            Push(&s1, data);
            printstack(s1);
        } else if(pilih == 2){
            if(!Kosong(s1)){
                dataParkir h = Pop(&s1);
                printf("Kendaraan Keluar:\n");
                printf("%s | %s | %s\n",
                    h.jenisKendaraan,
                    h.platNomor,
                    h.waktu
                );
            } else {
                
                Pop(&s1); 
            }

            printf("Kendaraan dalam Stack:\n");
            printstack(s1);        
        } else {
            printstack(s1);
        }
        printf("Lanjut (Y/N): ");
        scanf(" %c", &jawab);
        printf("\n");
    } while(jawab == 'Y' || jawab == 'y');
    
    return 0;
}

void printstack(Stack s){
    if(Kosong(s))
    {
         printf("Parkiran Kosong\n");
    } else 
    {
        for(int i = s.count - 1; i >= 0; i--){
            printf("%s | %s | %s\n", 
                s.item[i].jenisKendaraan,
                s.item[i].platNomor,
                s.item[i].waktu
            );
        }
    }
    printf("\n");
    printf("Count (Total Kendaraan) = %d\n", s.count);
}

void Inisialisasi (Stack *s)
{
    s->count = 0;
}

int Penuh (Stack s)
{
    return (s.count == MAX);
}

int Kosong (Stack s)
{
    return (s.count == 0);
}

void Push (Stack *s, dataParkir x)
{
    if(Penuh(*s))
        printf("Stack Penuh, Data tidak dapat disimpan\n");
    else {
        s->item[s->count] = x;
        s->count++;
    }
}

dataParkir Pop(Stack *s)
{
    dataParkir temp;
    if(Kosong(*s)) {
        printf("Stack Kosong, tidak ada kendaraan yang bisa keluar\n");
        return temp;
    }
    else {
        s->count--;
        temp = s->item[s->count];
        return(temp);
    }
}

int menu(){
    int pilih;

    printf("Menu\n");

    printf("1. Push Kendaraan (Masuk)\n");
    printf("2. Pop Kendaraan (Keluar)\n");
    printf("3. View Kendaraan\n");

    printf ("Pilih: "); 
    scanf("%d", &pilih);
    printf("\n");

    return pilih;
}

dataParkir inputData(){
    dataParkir data;

    printf("Masukkan Plat Nomor: ");
    scanf("%s", data.platNomor);

    printf("Masukkan Jenis Kendaraan: ");
    scanf("%s", data.jenisKendaraan);

    printf("Masukkan Waktu: ");
    scanf("%s", data.waktu);
    
    return data;
}