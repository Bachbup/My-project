#ifndef STUDENT_H
#define STUDENT_H

#define MAX 100

typedef struct {
    char id[10];
    char name[50];
    float gpa;
} Student;
void inputStudent(Student *s);
void printStudent(Student s);
void printAllStudent(Student list[],int n);
void addStudent(Student list[], int *n);
void findStudent(Student list[], char id[], int count);
void inputID(char *id);
void sort(Student list[], int start, int *count);void deleteStudent(Student list[], char id[], int *count);
void merge(Student list[], int left, int mid, int right);
void mergeSort(Student a[], int left, int right);
void save2File(Student list[], int n );
void read2file(Student list[], int *n);
#endif
