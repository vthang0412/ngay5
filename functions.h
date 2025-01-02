#include "datatypes.h"
// Khai bao nguyen mau ham

void displayMenu(void);
void menuAdmin(void);
//void loginAdmin();
void chooseAdmin(int *choiceStudent,Student students[], int *length,int *choiceAdmin);
void chooseStudent(int *choiceStudent,Student students[], int *length);

void addStudent(Student students[], int *length);
void printfStudent(Student students[], int *length);
void searchStudentByName(Student students[], int *length);
void editStudent(Student students[], int *length);
void deleteStudent(Student students[], int *length);
void sortStudentsByName(Student students[], int *length);

void askToGoBack();
void end();
void saveToFile(Student students[],int length);
void loadFromFile(Student students[],int *length);
