#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "student.h"
//Nhap thong tin sinh vien
void inputStudent(Student *s) {
    printf("Enter ID: ");
    scanf("%s", s->id);
    printf("Enter Name: ");
    getchar(); // Xóa ký tự '\n' còn lại
    fgets(s->name, sizeof(s->name), stdin);
    s->name[strcspn(s->name, "\n")] = '\0'; // Xóa ký tự newline nếu có
    printf("Enter GPA: ");
    scanf("%f", &s->gpa);
}

//In ra man hinh 1 sinh vien
void printStudent(Student s) {
    printf("%-10s %-20s %.2f\n", s.id, s.name, s.gpa);
}

//In ra man hinh tat ca sinh vien
void printAllStudent(Student list[],int n){
	printf("%-10s %-20s %s","ID","Name","CPA");
	printf("\n-----------------------------------\n");
	for (int i=0; i<n; i++){
		printStudent(list[i]);
	}
}

//Them thong tin sinh vien
void addStudent(Student list[], int *n) {
    if (*n >= MAX) {
        printf("Danh sách đã đầy!\n");
        return;
    }
    printf("== Thêm sinh viên thứ %d ==\n", *n + 1);
    inputStudent(&list[*n]);
    (*n)++;
}

//Tim sinh vien theo ID
void findStudent(Student list[], char id[], int count){
	for (int i=0; i < count; i++){
		if (strcmp(list[i].id, id)==0) {
			printf("%-10s %-20s %s","ID","Name","CPA");
			printf("\n-----------------------------------\n");
			printStudent(list[i]);
		    break;
		}
	}
	printf("Khong tim thay sinh vien so ID: %s", id);
}

//Nhap ID
void inputID(char *id){
	getchar();
	printf("\nNhap ID: ");
	int flag;
    do{
    	flag = 0;
    	fgets(id, sizeof(id), stdin);
    	id[strcspn(id, "\n")]='\0';
    	if (atoi(id)< 0 || atoi(id) > 99999999) {
    		printf("\nSo ID khong hop le\nNhap lai so ID: ");
    		flag = 1;
    	}
    }while (flag == 1);
}

//Sap xep mang
void sort(Student list[], int start, int *count){
	for (int i = start; i < *count - 1; i++) {
		list[i] = list[i+1];
	}
	(*count)--;
}

//Xoa sinh vien theo so id
void deleteStudent(Student list[], char id[], int *count){
	for (int i=0; i < *count; i++){
		if (strcmp(list[i].id, id)==0) {
			sort(list, i, count);
		}
	}
	printf("So luong id con lai: %d", *count);
}

void merge(Student list[], int left, int mid, int right){
	int n,m;
	n = mid - left + 1;
	m = right - mid;
	Student L[n], R[m];
	for (int i= 0; i < n; i++){
		L[i] = list[i + left];}
	for (int j= 0 ; j < m; j++){
		R[j] = list[j + mid + 1];}
	int i =0;
	int j=0;
	int k=left;
	while (i < n && j < m){
		if (atoi(L[i].id)<= atoi(R[j].id)) 
			list[k++] = L[i++];
		else
			list[k++] = R[j++];
	}
	//Nhap cac so con thua
	while (i < n){
		list[k++] = L[i++];}
	while (j < m) {
		list[k++] = R[j++];}
}
void mergeSort(Student a[], int left, int right){
		if (left < right){
		int mid = (left + right)/2;
		mergeSort(a, left, mid);
		mergeSort(a, mid +1, right);
		merge(a, left, mid, right);
		}
}

//Luu du lieu vao file
void save2File(Student list[], int n ){
	FILE *f = fopen("Sinhvien.txt", "w");
	if (f == NULL) {
	printf("Loi mo file ghi");
	return;
	}
	fprintf(f, "%-20s %-20s %s\n","ID","Name", "GPA");
	for (int i =0; i < n; i++){
		fprintf(f, "%-20s| %-20s| %2f\n" , list[i].id, list[i].name, list[i].gpa);
	}
	fclose(f);
	printf("Ghi file thanh cong\n");
}
// doc du lieu tu file
void read2file(Student list[], int *n){
    FILE *f = fopen("Sinhvien.txt", "r");
    if (f == NULL) {
        printf("Loi mo file doc\n");
        return;
    }

    char header[100];
    fgets(header, sizeof(header), f); // Bỏ qua dòng tiêu đề

    *n = 0;
    while (fscanf(f, "%[^|]| %[^|]| %f\n", list[*n].id, list[*n].name, &list[*n].gpa) == 3) {
        (*n)++;
    }

    fclose(f);
}
