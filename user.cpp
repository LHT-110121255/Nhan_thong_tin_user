#include <stdio.h>
#include <stdlib.h>

#define MAX 1000
typedef struct user
{
    char ho_ten[31];
    int tuoi;
}User;

int read_file(User users[], char file_name[]);
void write_file(User users[], char file_name[], int n);
void nhap(User users[], int fist, int n);
void xuat(User users[], int n);

int main()
{
    FILE *fPtr;
    char file_name[] = "ThongTin.txt";
    User arr_users[MAX];
    int soluong = read_file(arr_users, file_name);
    xuat(arr_users, soluong);
    printf("\nNhap so luong user can nhap : "); int n; scanf("%d", &n);
    nhap(arr_users, soluong,  n);
    soluong += n-1;
    xuat(arr_users, soluong+n);
    write_file(arr_users, file_name, n);
}

int read_file(User users[], char file_name[])
{
    FILE *fPtr;
    fPtr = fopen(file_name , "r");
    printf("Chuan bi doc file %s\n", file_name);
    int i = 0;
    while(fgets(users[i].ho_ten, 32, fPtr) && fscanf(fPtr, "%5d", &users[i].tuoi) != EOF)
    {
        i++;
    }
    printf("So luong thong tin la %d\n", i);
    return i;
    fclose(fPtr);
}

void write_file(User users[], char file_name[], int n)
{
    FILE *fPtr;
    fPtr = fopen(file_name , "w");
    for(int i = 0; i <= n; i++)
        fprintf(fPtr, "%31s%5d", users[i].ho_ten, users[i].tuoi);
    fclose(fPtr);
}

void nhap(User users[], int fist, int n)
{
    for(int i = fist; i < fist + n; i++)
    {
        printf("Nhap thong tin user %d", i);
        printf("Nhap ten: "); fflush(stdin); gets(users[i].ho_ten);
        printf("Nhap tuoi: "); fflush(stdin); scanf("%d", &users[i].tuoi);
        
    }
}
void xuat(User users[], int n)
{
    printf("THONG TIN CAC USER");
    printf("\n+------------Ten------------+--Tuoi--+");
    for(int i = 0; i < n; i++)
    {
        printf("\n|%31s|", users[i].ho_ten);
        printf("%5d|", users[i].tuoi);
    }
}
