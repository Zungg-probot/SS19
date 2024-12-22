#include <stdio.h>
#include <string.h>

struct SinhVien {
    int id;
    char name[50];
    int age;
    char phone[20];
};


void inSinhVien(struct SinhVien sv[], int size){
    if (size == 0){
        printf("Chua co sinh vien\n");
    }else{
        printf("\nDanh sach sinh vien:\n");
        for (int i = 0; i < size; i++){
            printf("ID: %d, Name: %s, Age: %d, Phone: %s\n", sv[i].id, sv[i].name, sv[i].age, sv[i].phone);
        }
    }
}

void addSinhVien(struct SinhVien sv[], int *size){
    struct SinhVien newSinhVien;
    printf("Nhap ID sinh vien: ");
    scanf("%d", &newSinhVien.id);
    fflush(stdin);
    printf("Nhap ten sinh vien: ");
    fgets(newSinhVien.name, 50, stdin);
    printf("Nhap tuoi sinh vien: ");
    scanf("%d", &newSinhVien.age);
    fflush(stdin);
    printf("Nhap so dien thoai sinh vien: ");
    fgets(newSinhVien.phone, 15, stdin);
    sv[*size] = newSinhVien;
    (*size)++;
}

void editSinhVien(struct SinhVien sv[], int size){
    int id;
    printf("Nhap ID sinh vien can sua: ");
    scanf("%d", &id);
    for(int i = 0; i < size; i++){
        if(sv[i].id == id){
            printf("Nhap ten moi: ");
            fflush(stdin);
            fgets(sv[i].name, 50, stdin);
            printf("Nhap tuoi moi: ");
            scanf("%d", &sv[i].age);
            fflush(stdin);
            printf("Nhap so dien thoai moi: ");
            fgets(sv[i].phone, 15, stdin);
            return;
        }
    }
    printf("Khong tim thay ID\n");
}

void deleteSinhVien(struct SinhVien sv[], int *size){
    int id;
    printf("Nhap ID sinh vien can xoa: ");
    scanf("%d", &id);
    for(int i = 0; i < *size; i++){
        if(sv[i].id == id){
            for(int j = i; j < *size - 1; j++){
                sv[j] = sv[j + 1];
            }
            (*size)--;
            return;
        }
    }
    printf("Khong tim thay  ID\n");
}

void timSinhVien(struct SinhVien sv[], int size){
    int id;
    printf("Nhap id sinh vien can tim: ");
    scanf("%d",&id);
    int found = 1;
    for(int i = 0; i < size; i++){
        if(sv[i].id == id){
            printf("ID: %d, Name: %s, Age: %d, Phone: %s\n", sv[i].id, sv[i].name, sv[i].age, sv[i].phone);
            found = 0;
        }
    }
    if (found){
        printf("Khong tim thay sinh vien voi id %d\n", id);
    }
}

void sapxepSinhVien(struct SinhVien sv[], int size){
    struct SinhVien temp;
    for(int i = 0; i < size - 1; i++){
        for(int j = i + 1; j < size; j++){
            if(strcmp(sv[i].name, sv[j].name) > 0){
                temp = sv[i];
                sv[i] = sv[j];
                sv[j] = temp;
            }
        }
    }
    printf("Danh sach sinh vien da duoc sap xep theo ten\n");
}

int main(){
	struct SinhVien sv[100];
	int size = 0;
    int chose;
    do{
        printf("\nMENU\n");
        printf("1. Hien thi danh sach sinh vien\n");
        printf("2. Them sinh vien\n");
        printf("3. Sua thong tin sinh vien\n");
        printf("4. Xoa sinh vien\n");
        printf("5. Tim kiem sinh vien\n");
        printf("6. Sap xep danh sach sinh vien\n");
        printf("7. Thoat\n");
        printf("Lua chon cua ban: ");
        scanf("%d", &chose);
        switch(chose){
            case 1:
                inSinhVien(sv,size);
                break;
            case 2:
                addSinhVien(sv,&size);
                break;
            case 3:
                editSinhVien(sv,size);
                break;
            case 4:
                deleteSinhVien(sv,&size);
                break;
            case 5:
                timSinhVien(sv,size);
                break;
            case 6:
                sapxepSinhVien(sv,size);
                break;
            case 7:
                break;
        }
    } while (chose != 7);
    return 0;
}

