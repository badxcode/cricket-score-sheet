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
    display();

    
}
void display()
{
    system("clear");

    //game-details
    gotorc(1,1);
    printf("Competition:");
    gotorc(1,35);
    printf("Venue:");
    gotorc(3,0);
    printf("Match Between:");
    gotorc(3,35);
    printf("Versus:");
    gotorc(5,0);
    printf("Toss won by:");
    gotorc(5,35);
    printf("Elected to:");
    gotorc(7,0);
    printf("Inning of:");
    gotorc(7,35);
    printf("Date:");
    
    
    //Batting
    // gotorc(9,1);
    // printf("%c",179);
    gotorc(9,9);
    printf("Batsman Name");
    gotorc(11,1);
    for(int i=0; i<11; i++)
        printf("Batsman %d:\n",i+1); //printf("%cBatsman %d:\n",180,i+1);
    gotorc(9,40);
    printf("Runs");
    gotorc(9,53);
    printf("Balls");
    gotorc(9,65);
    printf("4s");
    gotorc(9,75);
    printf("6s");
    
    //matchDetails
    gotorc(23,25);
    printf("Total Runs: ");
    gotorc(23,45);
    printf("Over: ");
    gotorc(23,60);
    printf("Run Rate: ");
    
    //Bowling
    gotorc(25,5);
    printf("Bowlers");
    gotorc(25,37);
    printf("Over");
    gotorc(25,44);
    printf("Maiden");
    gotorc(25,52);
    printf("Run");
    gotorc(25,58);
    printf("Wicket");
    gotorc(25,68);
    printf("Extra");
    gotorc(25,75);
    printf("Econ");
    gotorc(27,0);
    for(int i=0; i<8; i++)
        printf("Bowler %d:\n",i+1); //printf("%cBowler %d:\n",179,i+1);
    
    /*
    //Table
    gotorc(0,3);
    for(int i=0; i<79; i++)
        printf("%c",205);
    gotorc(0,1);
    for(int i=0; i<79; i++)
        printf("%c",205);
    gotorc(0,5);
    for(int i=0; i<79; i++)
        printf("%c",205);
    gotorc(35,0);
    for (int i=0; i<33; i++)
    {
    gotorc(34,i);
        printf("%c",182);
    }
    gotorc(0,7);
    for(int i=0; i<79; i++)
        printf("%c",205);
    gotorc(0,21);
    for(int i=0; i<79; i++)
        printf("%c",205);
    gotorc(0,9);
    for(int i=0; i<79; i++)
        printf("%c",205);
    gotorc(0,23);
    for (int i=0; i<79; i++)
        printf("%c",205);
    gotorc(0,25);
    for (int i=0; i<79; i++)
        printf("%c",205);
    gotorc(0,34);
    for (int i=0; i<79; i++)
        printf("%c",205);
    gotorc(61,10);
    for(int i=0; i<11; i++)
    {
        printf("%c",179);
        gotorc(61,10+(i+1));
    }
    gotorc(71,10);
    for(int i=0; i<11; i++)
    {
        printf("%c",179);
        gotorc(71,10+(i+1));
    }
    gotorc(49,10);
    for(int i=0; i<11; i++)
    {
        printf("%c",179);
        gotorc(49,10+(i+1));
    }
    gotorc(0,40);
    for(int i=0;i<79;i++)
    {
        printf("%c",205);
    }
    */

}