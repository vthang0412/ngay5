#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include "functions.h"
int main(int argc, char *argv[]) {
	int choiceStudent,choiceMenu,choiceAdmin;
	int length=0;
	Student students[100];
	loadFromFile(students, &length);
	do{
		displayMenu();
		scanf("%d",&choiceMenu);
		getchar();
		switch(choiceMenu){
			case 1:
//				system("cls");
//				loginAdmin();
				system("cls");
				chooseAdmin(&choiceStudent,students,&length,&choiceAdmin);
				break;
			case 2: 
				system("cls");
				printfStudent(students,&length);
				askToGoBack();
				system("cls");			
    			break;
    		case 3:
				break; 
    		case 0:
    			system("cls");
    			end();
    			break;
			default:
				printf("Lua chon khong hop le. Vui long chon lai.\n");
				break;
		}
	}while(choiceMenu!=0);
	return 0;
}
