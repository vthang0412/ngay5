#include <stdio.h>
#include <string.h>
#include "functions.h"
#include <stdlib.h>
// Logic ham
// Menu Ten He Thong
void displayMenu(void){
	printf("\n***Student Management System Using C***\n");
	printf("CHOOSE YOUR ROLE\n");
	printf("===================\n");
	printf("[1]: Admin.\n");
	printf("[2]: Student.\n");
	printf("[3]: Teacher.\n");
	printf("[0]: Exit the Program.\n");
	printf("===================\n");
	printf("Enter The Choice: ");
}
// Menu Admin
void menuAdmin(void){
	printf("\n***Student Management System Using C***\n");
	printf("			Menu\n");
	printf("==============================\n");
	printf("[1]: Students management.\n");
	printf("[2]: ClassRooms managemment.\n");
	printf("[3]: Teacher management.\n");
	printf("[4]: User Guideline.\n");
	printf("[5]: About Us.\n");
	printf("[0]: Exit the Program. \n");
	printf("Enter The Choice: ");
}
// Menu Sinh vien
void menuStudent(void){
	printf("\n***Student Management System Using C***\n");
	printf("		Student Menu\n");
	printf("==============================\n");
	printf("[1]: Add a new students.\n");
	printf("[2]: Show all students.\n");
	printf("[3]: Search a students.\n");
	printf("[4]: Edit a students.\n");
	printf("[5]: Delete a student.\n");
	printf("[6]: Sort Students By Name.\n") ;
	printf("[0]: Exit the Program.\n");
	printf("Enter The Choice: ");
}
// Login Admin
//void loginAdmin() {
//    char email[50];  
//    const char correctEmail[] = "vthang041206@gmail.com";  
//    const char correctPassword[] = "123";  
//    char password[50];
//    while (1) {
//        printf("**** STUDENT MANAGEMENT **** \n");
//        printf("\n\t    LOGIN \n");
//        printf("Nhap Email: ");
//        fgets(email, 50, stdin);
//        email[strcspn(email, "\n")] = '\0'; 
//        printf("Nhap Mat Khau: ");
//        fgets(password, 50, stdin);
//        password[strcspn(password, "\n")] = '\0'; 
//        if (strcmp(email, correctEmail) == 0 && strcmp(password, correctPassword) == 0) {
//            printf("Dang nhap thanh cong.\n");
//            break;
//        } else {
//            printf("Email hoac mat khau sai, vui long nhap lai.\n");
//        }
//    }
//}
// Menu Admin
void chooseAdmin(int *choiceStudent,Student students[], int *length,int *choiceAdmin) {
	do{
		system("cls");
		menuAdmin();
		scanf("%d",choiceAdmin);
		getchar();
		system("cls");
		switch(*choiceAdmin){
			case 1:
				chooseStudent(choiceStudent,students,length);
                break;
			case 2:				
				break;
			case 3:			
				break;
			case 4: 			
				break;
			case 5:
				break; 
			case 0:  
				break;
			default:
				printf("Lua chon khong hop le. Vui long chon lai.\n");
				break;
		}	
	}while(*choiceAdmin!=0);
}
// Menu sinh vien
void chooseStudent(int *choiceStudent,Student students[], int *length) {
	do{
		system("cls");
		menuStudent();
		scanf("%d",choiceStudent);
		getchar();
		system("cls");
		switch(*choiceStudent){
			case 1:
				system("cls");
                addStudent(students,length);
                saveToFile(students, *length);
                askToGoBack();
                break;
			case 2:	
				system("cls");
				printfStudent(students,length);
				askToGoBack();
				break;
			case 3:
				system("cls");
				searchStudentByName(students, length);
				askToGoBack();
				break;
			case 4: 
				system("cls");
				editStudent(students, length);
				saveToFile(students, *length);
				askToGoBack();
				break;
			case 5: 
				system("cls");
				deleteStudent(students, length);
				saveToFile(students, *length);
				askToGoBack();
				break;
			case 6:
				system("cls");
				sortStudentsByName(students, length);
				askToGoBack();
				break; 
			case 0: 
				break;
			default:
				printf("Lua chon khong hop le. Vui long chon lai.\n");
				break;
		}	
	}while(*choiceStudent!=0);
}
// Ham them sinh vien
void addStudent(Student students[], int *length) {
    int quantity;
    printf("\t **** Add A New Student ****\n");
    printf("Nhap so luong sinh vien: ");
    scanf("%d", &quantity);
    getchar();  
	int i;
    for (i = 0; i < quantity; i++) {
        printf("Nhap thong tin cho sinh vien %d\n", i + 1);     
        int id;
        do {
            printf("Nhap ID sinh vien: ");
            if (scanf("%d", &id) != 1) {
                printf("ID khong hop le. Vui long nhap lai.\n");
                getchar(); 
                continue;
            }
            getchar(); 
            int isDuplicate = 0;
			int j; 
            for (j = 0; j < *length; j++) {
                if (students[j].id == id) {
                    printf("\nID %d da ton tai. Vui long nhap ID moi.\n", id);
                    isDuplicate = 1;
                    break;
                }
            }
            if (id <= 0) {
                printf("ID phai la so duong. Vui long nhap lai.\n");
                isDuplicate = 1; 
            }
            if (!isDuplicate) 
                break; 
        } while (1);
        students[*length].id = id;
//Nhap thong tin sinh vien
        void inputString(char *field, const char *prompt, int (*validate)(const char *)) {
            do {
                printf("%s", prompt);
                fgets(field, sizeof(students[*length].name), stdin);
                field[strcspn(field, "\n")] = '\0';  
                if (validate(field)) break;
            } while (1);
        }
// Kiem tra ten sinh vien
        int validateName(const char *name) {
        	int j; 
            for (j = 0; name[j]; j++) {
                if (!isalpha(name[j]) && !isspace(name[j])) {
                    printf("Ten khong hop le. Vui long chi su dung chu cai va dau cach.\n");
                    return 0;
                }
            }
            return 1;
        }
        inputString(students[*length].name, "Nhap ten sinh vien: ", validateName);
//Kiem tra email
        int validateEmail(const char *email) {
            char *at = strchr(email, '@');
            char *dot = strrchr(email, '.');
            if (!at || !dot || at > dot) {
                printf("Dinh dang email khong hop le(Phai la a@b.c).\n");
                return 0;
            }
            return 1;
        }
        inputString(students[*length].email, "Nhap email sinh vien: ", validateEmail);
// Kiem tra so dien thoai
        int validatePhone(const char *phone) {
            int len = strlen(phone);
            if (len < 10 || len > 11) {
                printf("So dien thoai phai co tu 10 den 11 chu so.\n");
                return 0;
            }
            int j; 
            for (j = 0; j < len; j++) {
                if (!isdigit(phone[j])) {
                    printf("So dien thoai chi duoc chua chu so.\n");
                    return 0;
                }
            }
            return 1;
        }
        inputString(students[*length].phone, "Nhap so dien thoai sinh vien: ", validatePhone);
// Nhap khoa hoc cho sinh vien
        printf("Nhap khoa hoc cho sinh vien: ");
        scanf("%d", &students[*length].courses);
        getchar(); 
        (*length)++;  
    }
}
// Ham sua sinh vien
void editStudent(Student students[], int *length) {
    if (*length == 0) {
        printf("Danh sach sinh vien hien dang trong. Khong co gi de sua.\n");
        return;
    }
    int id;
    printf("\t **** Edit A Student ****\n") ;
    printf("Nhap ID sinh vien muon sua: ");
    scanf("%d", &id);
    getchar();    
// Tim sinh vien de sua 
    int found = -1;
    int i; 
    for (i = 0; i < *length; i++) {
        if (students[i].id == id) {
            found = i;
            break;
        }
    }
    if (found == -1) {
        printf("Khong tim thay sinh vien voi ID: %d\n", id);
        return;
    }
// Hien thi thong tin hien tai cua sinh vien
    printf("\nThong tin hien tai cua sinh vien:\n");
    printf("ID: %d\n", students[found].id);
    printf("Ho Va Ten: %s\n", students[found].name);
    printf("So Dien Thoai: %s\n", students[found].phone);
    printf("Email: %s\n", students[found].email);
    char input[100];
    int valid;
// Nhap ten moi
    do {
        printf("Ho Va Ten (Nhap so 0 de bo qua): ");
        fgets(input, sizeof(input), stdin);
        input[strcspn(input, "\n")] = '\0';
        if (strcmp(input, "0") == 0) break;
        valid = 1;
        int i;
        for (i = 0; input[i]; i++) {
            if (!isalpha(input[i]) && !isspace(input[i])) {
                valid = 0;
                printf("Ten khong hop le. Vui long nhap lai (chi chu va khoang trang).\n");
                break;
            }
        }
        if (valid) strcpy(students[found].name, input);
    } while (!valid);

// Nhap so dien thoai moi
    do {
        printf("So Dien Thoai (Nhap so 0 de bo qua): ");
        fgets(input, sizeof(input), stdin);
        input[strcspn(input, "\n")] = '\0';
        if (strcmp(input, "0") == 0) break;
        valid = 1;
        int len = strlen(input);
        if (len < 10 || len > 11) {
            valid = 0;
            printf("So dien thoai khong hop le. Vui long nhap lai (do dai 10-11 ky tu).\n");
        } else {
        	int i;
            for (i = 0; i < len; i++) {
                if (!isdigit(input[i])) {
                    valid = 0;
                    printf("So dien thoai chi duoc chua so. Vui long nhap lai.\n");
                    break;
                }
            }
        }
// Kiem tra so dien thoai co bi trung khong
        if (valid) {
        	int i;
            for (i = 0; i < *length; i++) {
                if (i != found && strcmp(students[i].phone, input) == 0) {
                    valid = 0;
                    printf("So dien thoai %s da ton tai. Vui long nhap so dien thoai khac.\n", input);
                    break;
                }
            }
        }
        if (valid) strcpy(students[found].phone, input);
    } while (!valid);
// Nhap email moi 
    do {
        printf("Nhap Email (Nhap so 0 de bo qua): ");
        fgets(input, sizeof(input), stdin);
        input[strcspn(input, "\n")] = '\0';
        if (strcmp(input, "0") == 0) break;
        valid = 1;
        char *at = strchr(input, '@');
        char *dot = strrchr(input, '.');
        if (!at || !dot || at > dot) {
            valid = 0;
            printf("Email khong hop le. Vui long nhap lai (dinh dang x@y.z).\n");
        }
//Kiem tra email co bi trung khong 
        if (valid) {
        	int i;
            for (i = 0; i < *length; i++) {
                if (i != found && strcmp(students[i].email, input) == 0) {
                    valid = 0;
                    printf("Email %s da ton tai. Vui long nhap email khac.\n", input);
                    break;
                }
            }
        }
        if (valid) strcpy(students[found].email, input);
    } while (!valid);
    printf("Thong tin sinh vien da duoc cap nhat.\n");
}
// Ham xoa sinh vien
void deleteStudent(Student students[], int *length) {
    int id, i, found = -1;
// Nhap id sinh vien muon xoa
    printf("\t **** Delete A Student ****\n") ;
    printf("Nhap ID sinh vien muon xoa: ");
    scanf("%d", &id);
// Tim sinh vien co ID trong danh sach
    for (i = 0; i < *length; i++) {
        if (students[i].id == id) {
            found = i;
            break;
        }
    }
// Neu khong tim thay sinh vien
    if (found == -1) {
        printf("Khong tim thay sinh vien voi ID: %d\n", id);
        return;
    }
// Hien thi thong tin sinh vien can xoa
    printf("\nThong tin sinh vien can xoa:\n");
    printf("ID: %d\n", students[found].id);
    printf("Ho Va Ten: %s\n", students[found].name);
    printf("Email: %s\n", students[found].email);
    printf("So Dien Thoai: %s\n", students[found].phone);
    printf("So Khoa Hoc: %d\n", students[found].courses);
// Yeu cau xac nhan xoa
    char confirm;
    printf("\nBan co chac chan muon xoa sinh vien nay (y/n)? ");
    getchar();  
    scanf("%c", &confirm);
    if (confirm == 'y' || confirm == 'y') {
// Xoa sinh vien
        for (i = found; i < *length - 1; i++) {
            students[i] = students[i + 1]; 
        }
        (*length)--; 
        printf("Sinh vien da duoc xoa thanh cong.\n");
    } else {
        printf("Huy thao tac xoa sinh vien.\n");
    }
}
// Ham Sap xep sinh vien 
void sortStudentsByName(Student students[], int *length) {
    if (*length == 0) {
        printf("Danh sach sinh vien trong. Khong co gi de sap xep.\n");
        return;
    }
    int choiceSort;
    printf("\t **** Sort Students By Name ****\n") ;
    printf("Chon thu tu sap xep danh sach:\n");
    printf("1. Tang dan theo ten\n");
    printf("2. Giam dan theo ten\n");
    printf("Nhap lua chon (1 hoac 2): ");
    scanf("%d", &choiceSort);
    getchar(); 
    if (choiceSort!= 1 && choiceSort != 2) {
        printf("Lua chon khong hop le. Quay lai menu chinh.\n");
        return;
    }
// Sap xep 
    int i,j;
    for (i = 0; i < *length - 1; i++) {
        for (j = i + 1; j < *length; j++) {
            int compare = strcmp(students[i].name, students[j].name);
            if ((choiceSort == 1 && compare > 0) || (choiceSort == 2 && compare < 0)){
                Student temp = students[i];
                students[i] = students[j];
                students[j] = temp;
            }
        }
    }
    printf("Danh sach ten sinh vien da duoc sap xep ");
	if (choiceSort == 1) {
	    printf("Tang dan.\n");
	} else {
	    printf("Giam dan.\n");
	}
    printf("\t----------***All Students***----------\n");
    printf("|==========|====================|========================|====================|============|\n");
    printf("|    ID    |        Name        |          Email         |        Phone       |  NO.Course |\n");
    printf("|==========|====================|========================|====================|============|\n");
    for (i = 0; i < *length; i++) {
        printf("| %-8d | %-18s | %-22s | %-18s | %-10d |\n", 
               students[i].id, 
               students[i].name, 
               students[i].email, 
               students[i].phone, 
               students[i].courses);
        printf("|==========|====================|========================|====================|============|\n");
    }
    printf("\t \t---------------------\n");
}
// Ham Tim kiem sinh vien
void searchStudentByName(Student students[], int *length) {
    if (*length == 0) {
        printf("Danh sach sinh vien hien dang trong. Khong co gi de tim kiem.\n");
        return;
    }
    char searchName[50];
    printf("\t **** Search A Student ****\n");
    printf("Nhap ten sinh vien muon tim kiem: ");
    fgets(searchName, sizeof(searchName), stdin);
    searchName[strcspn(searchName, "\n")] = '\0';

//Kiem tra xem nhap co bi trong hay khong
    if (strlen(searchName) == 0) {
        printf("Ten sinh vien khong duoc de trong.\n");
        return;
    }
    printf("\nKet qua tim kiem cho chuoi: \"%s\"\n", searchName);   
    int found = 0;
    int i;
    for (i = 0; i < *length; i++) {
        // Dùng strstr() tim chuoi trong ten sinh vien
        if (strstr(students[i].name, searchName) != NULL) {
            if (!found) {
                found = 1;
                printf("\t----------***All Students***----------\n");
                printf("|==========|====================|========================|====================|============|\n");
                printf("|    ID    |        Name        |          Email         |        Phone       |  NO.Course |\n");
                printf("|==========|====================|========================|====================|============|\n");
            }
            printf("| %-8d | %-18s | %-22s | %-18s | %-10d |\n", 
                   students[i].id, 
                   students[i].name, 
                   students[i].email, 
                   students[i].phone, 
                   students[i].courses);
            printf("|==========|====================|========================|====================|============|\n");
        }
    }

    if (!found) {
        printf("Khong tim thay sinh vien nao voi ten chua chuoi: \"%s\"\n", searchName);
    }
    printf("\t \t---------------------\n");
}
// Ham chuc nang back hoac end chuong trinh
void askToGoBack() {
    char choice;
    printf("\nGo Back (b) or Exit (0): ");
    choice = getchar();
    getchar(); 
	fflush(stdin);  
    if (choice == 'b' || choice == 'B') {
        return;  
    } else if (choice == '0') {
    	system("cls");
        end();
		exit(0); 
	}
}
// Ham end chuong trinh
void end(){
	printf("=========Thank You=========\n");
	printf("=========See You Soon======\n");
}
// Ham in sinh vien
void printfStudent(Student students[], int *length) {
    if (*length == 0) {
        printf("\nKhong co sinh vien trong danh sach.\n");
        return;
    }
    printf("\t **** Show All Students ****\n") ;
    printf("\t----------***All Students***----------\n");
    printf("|==========|====================|========================|====================|============|\n");
    printf("|    ID    |        Name        |          Email         |        Phone       |  NO.Course |\n");
    printf("|==========|====================|========================|====================|============|\n");
	int i;
    for (i = 0; i < *length; i++) {
        printf("| %-8d | %-18s | %-22s | %-18s | %-10d |\n", 
               students[i].id, 
               students[i].name, 
               students[i].email, 
               students[i].phone, 
               students[i].courses);
        printf("|==========|====================|========================|====================|============|\n");
    }
    printf("\t \t---------------------\n");
}
//void saveToFile(const Student students[], int length) {
//    FILE *file = fopen(DATA_FILE, "wb");
//    if (file == NULL) {
//        printf("Khong the luu du lieu.\n");
//        return;
//    }
//    fwrite(&length, sizeof(int), 1, file);
//    fwrite(students, sizeof(Student), length, file);
//    fclose(file);
//    printf("Du lieu da duoc luu thanh cong!\n");
//}
//
//void loadFromFile(Student students[], int *length) {
//    FILE *file = fopen(DATA_FILE, "rb");
//    if (file == NULL) {
//        *length = 0;
//        return;
//    }
//    fread(length, sizeof(int), 1, file);
//    fread(students, sizeof(Student), *length, file);
//    fclose(file);
//    printf("Du lieu da duoc tai thanh cong!\n");
//    system("cls");
//}
void saveToFile(Student students[],int length) {
    FILE *fptr = fopen("studentsData.dat", "wb");
    if (fptr == NULL) {
        printf("Khong the mo tep de ghi.\n");
        return;
    }
    fwrite(&length, sizeof(int), 50, fptr); // Ghi s? lu?ng sinh viên tru?c
    fwrite(students, sizeof(Student), length, fptr); // Ghi danh sách sinh viên
    printf("Du lieu sinh vien duoc luu thanh cong.\n");
    fclose(fptr);
}
void loadFromFile(Student students[],int *length) {
    FILE *fptr = fopen("studentsData.dat", "rb");
    if (fptr == NULL) {
        printf("Khong tim thay du lieu.\n");
        *length = 0; // N?u không tìm th?y t?p, d?t danh sách r?ng
        return;
    }
    fread(length, sizeof(int), 50, fptr); // Ð?c s? lu?ng sinh viên
    fread(students, sizeof(Student), *length, fptr); // Ð?c danh sách sinh viên
    fclose(fptr);
    printf("Du lieu sinh vien duoc tai thanh cong.\n");
}

