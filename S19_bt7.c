#include<stdio.h>
#include<string.h>

struct SinhVien{
	int id;
	char name[50];
	int age;
	char phone[10];
};

int idDelete(struct SinhVien sv[], int id,int *size){
	if(id <=0 || id > *size){
		printf("\nid khong ton tai trong mang!\n\n");
		return 0;
	}
	for(int i = id-1;i<*size;i++){
		sv[i]=sv[i+1];
	}
	(*size)--;
}


int main(){
	
	struct SinhVien sinhVien[]={
		{1,"Le Duc Anh",20,"0153298751"},
		{2,"Le Minh Son",19,"0152149638"},
		{3,"Nguyen Minh Anh",23,"052154245"},
		{4,"Hoang Nguyen Duc",22,"022543984"},
		{5,"Nguyen Thao Vy",18,"022987184"},
	};
	int size = 5;
	int deleteid;
	printf("Nhap id muon xoa: ");
	scanf("%d",&deleteid);
	
	idDelete(sinhVien, deleteid, &size);
	
	printf("Mang sau khi chinh sua: \n");
	for (int i = 0; i < size; i++){
        printf("Sinh vien %d:\n", sinhVien[i].id);
        printf("Ten: %s\n", sinhVien[i].name);
        printf("Tuoi: %d\n", sinhVien[i].age);
        printf("So dien thoai: %s\n", sinhVien[i].phone);
        printf("\n");
    }
	
	return 0;
}

