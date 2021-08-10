#include"function_declaration.h"

void gotorc(int row, int column) {
    printf("\033[%d;%df", row, column);
}
void menu() {
    system("clear");

    int choice;
    gotorc(2,40);
    printf("\033[1;4;31mCricket Score Sheet");
    gotorc(4,40);
    printf("\033[32;m1. New ScoreSheet");
    gotorc(5,40);
    printf("\033[32;m2. View ScoreSheet");
    gotorc(6,40);
    printf("\033[32;m3. Exit");
    gotorc(8,38);
    printf("\033[5;1;37m Enter your choice: \033[0;m ");
    scanf("%d",&choice);
    fflush(stdin);
    
    switch(choice)
    {
        case 1: inputGameDetails(); break;

        case 2: puts("case 2"); break;

        case 3: puts("case 3"); break;

        default:    gotorc(10,36);
                    printf("\033[2;31mInvalid Choice!~ Please try again.");
                    menu();
                    break;
    }
    
}
void inputGameDetails() {
    system("clear");
    //display();
}