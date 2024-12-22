#include <stdio.h>
#include <string.h>

struct SinhVien {
    int id;
    char name[50];
    int age;
    char phoneNumber[20];
};

void sapxepSV(struct SinhVien sv[], int n) {
    struct SinhVien temp;
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (strcmp(sv[i].name, sv[j].name) > 0) {
                temp = sv[i];
                sv[i] = sv[j];
                sv[j] = temp;
            }
        }
    }
}

void inDS(struct SinhVien sv[], int n){
    for(int i = 0; i < n; i++){
        printf("ID: %d, Name: %s, Age: %d, Phone: %s\n", sv[i].id, sv[i].name, sv[i].age, sv[i].phoneNumber);
    }
}

int main(){
    struct SinhVien sv[5] = {
        {1, "Nguyen Thi Mai", 20, "0123456789"},
        {2, "Tran Minh Tu", 21, "0987654321"},
        {3, "Le Thanh Son", 22, "0912345678"},
        {4, "Pham Lan Anh", 20, "0934567890"},
        {5, "Hoang Bao Ngoc", 23, "0976543210"}
    };

    sapxepSV(sv, 5);
    printf("\nSinh vien sau khi sap xep: \n");
    inDS(sv, 5);

    return 0;
}

