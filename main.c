#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "student.h"
//Chuong trinh trinh
int main() {
    //Nhap thong tin:
    Student list[MAX];
    int n = 0;
    char choice;
    int count = 0;
    do {
        addStudent(list, &n);
        printf("Tiếp tục thêm? (y/n): ");
        scanf(" %c", &choice);
        count++;
    } while (choice == 'y' || choice == 'Y');
    
    // Tinh nang:
    char id[10];
    char more1, more2, more3;
    int choose;
    printf("Menu:\n1) Hien thi danh sach sinh vien\n2) Xoa sinh vien theo ID\n3) Tim kiem thong tin sinh vien theo ID\n4) Sap xep ds theo ID\n5) doc tu file\n0) Thoat\n");
    do {
    	printf("Lua chon: ");
    	scanf("%d",&choose);
    	switch(choose){
    		case 1: {
    			printf("\n== Danh sách sinh viên ==\n");
    			printAllStudent(list, count);
    			break;}
    		case 2:{
    			printf("\n==Xoa ID==\n");
    			do {
   	 			inputID(id);
  	  			deleteStudent(list, id, &count);
  	  			printf("\nBan con muon xoa ID nao khac khong? (y/n): ");
    				scanf(" %c",&more2);
    			}while(more2=='y'||more2=='Y');
     	       break;
  	  	}
   	 	case 3: {
    			printf("\n==Tim thong tin ID==");
  	  		do {
    				inputID(id);
    				printf("\n Thong tin sinh vien co ID: %s\n",&id);
    				findStudent(list, id, count);
    				printf("\nBan con muon tim ID nao khac khong? (y/n): ");
    				scanf(" %c",&more3);
    			}while(more3=='y'||more3=='Y');
    	        break;
    		}
    		case 4: {
    			printf("Sap xep ds sinh vien theo ID\n");
    			mergeSort(list, 0, count-1);
    			printAllStudent(list, count);
    			break;
    		}
    		case 5: {
    			printf("Doc du lieu tu file\n");
    			Student know[MAX];
    			read2file(know, &n);
    			printAllStudent(know,n);
    			break;
    		}
   	 	case 0: printf("Tam biet\n");break;
   	 	default: printf("Lua chon khong hop le");
 	   }
 	   if (choose==0) break;
 	   printf("\nBan con lua chon gi nua khong? (y/n): ");
 	   scanf(" %c",&more1);
    }while(more1=='y'||more1=='Y');
    save2File(list, count);
    return 0;
}
