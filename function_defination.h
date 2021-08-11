#include"function_declaration.h"
FILE *fp;
int currentInnings;
char filename[50];
char extension[] = ".txt";
char directory[60] = "File//";

struct GameDetails {
    char copmetitionName[50];
    char venue[50];
    char matchBetween[20];
    char versus[20];
    char tossWonBy[20];
    char electedTo[15];
    char date[15];
}gameDetails;

struct matchDetails {
    int innings;
    int totalRuns;
    float overPlayed;
    float runRate;
}inningsA, inningsB;

struct batsMan {
    char name[30];
    int runs;
    int balls;
    char status[10];
    int fours;
    int sixes;
}batsManTeamA[11], batsManTeamB[11];

struct bowler {
    char name[30];
    float overs;
    int runs;
    int wicket;
    int maiden;
    float economy;
    int extra;
}bowlerTeamA[8], bowlerTeamB[8];

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
    getchar();
    
    switch(choice)
    {
        case 1: inputGameDetails();
                gotorc(6,90);
                printf("Press Y to save the file: ");
                getchar(); getchar();
                gotorc(7,90);
                fileNameMaker(); 
                fileWrite();
                gotorc(8,90);
                printf("File saved Successfully");
                gotorc(10,90);
                printf("Press Any Key To Return To Main Menu");
                getchar(); menu();
                break;

        case 2: fileRead(); menu(); break;

        case 3: exit(0);

        default:
                gotorc(10,36);
                printf("\033[2;31mInvalid Choice!~ Please try again.");
                menu();
                break;
    }
    
}
void inputGameDetails() {
    system("clear");
    display();

    gotorc(1,16);
    fgets(gameDetails.copmetitionName,50,stdin);
    gotorc(1,47);
    fgets(gameDetails.venue,50,stdin);
    gotorc(3,16);
    fgets(gameDetails.matchBetween,20,stdin);
    gotorc(3,47);
    fgets(gameDetails.versus,20,stdin);
    gotorc(5,16);
    fgets(gameDetails.tossWonBy,20,stdin);
    gotorc(5,47);
    fgets(gameDetails.electedTo,15,stdin);

    int inningsNO;
    gotorc(7,16);
    scanf("%d",&inningsNO);
    if(inningsNO==1) {
        inningsA.innings = 1;
        currentInnings = 1;
    }
    else {
        inningsB.innings = 2;
        currentInnings = 2;
    }
    getchar();
    
    gotorc(7,47);
    fgets(gameDetails.date,15,stdin);

    inputPlayer();
    return;
}
void inputPlayer()
{   
    // display();
    // currentInnings = 1;
    if(currentInnings==1)
    {
        for(int i=0; i<11; i++)
        {
            gotorc(10+(i+1),13);
            fgets(batsManTeamA[i].name,30,stdin);
            gotorc(10+(i+1),39);
            scanf("%d",&batsManTeamA[i].runs);
            gotorc(10+(i+1),53);
            scanf("%d",&batsManTeamA[i].balls);
            gotorc(10+(i+1),65);
            scanf("%d",&batsManTeamA[i].fours);
            gotorc(10+(i+1),75);
            scanf("%d",&batsManTeamA[i].sixes);
            getchar();
        }
        for(int i=0; i<8; i++){
            gotorc(26+(i+1),11);
            fgets(bowlerTeamA[i].name,30,stdin);
            gotorc(26+(i+1),37);
            scanf("%f",&bowlerTeamA[i].overs);
            gotorc(26+(i+1),46);
            scanf("%d",&bowlerTeamA[i].maiden);
            gotorc(26+(i+1),52);
            scanf("%d",&bowlerTeamA[i].runs);
            gotorc(26+(i+1),58);
            scanf("%d",&bowlerTeamA[i].wicket);
            gotorc(26+(i+1),68);
            scanf("%d",&bowlerTeamA[i].extra);
            gotorc(26+(i+1),75);
            scanf("%f",&bowlerTeamA[i].economy);
            getchar();
        }

        gotorc(7,90);
        printf("Press C to continue to Innings 2: ");
        if(getchar()=='c' || getchar()=='C')
        {
            currentInnings = 2;
            inputPlayer();
        }
    }
    else{
        for(int i=0; i<11; i++)
        {
            gotorc(10+(i+1),13);
            fgets(batsManTeamA[i].name,30,stdin);
            gotorc(10+(i+1),39);
            scanf("%d",&batsManTeamA[i].runs);
            gotorc(10+(i+1),53);
            scanf("%d",&batsManTeamA[i].balls);
            gotorc(10+(i+1),65);
            scanf("%d",&batsManTeamA[i].fours);
            gotorc(10+(i+1),75);
            scanf("%d",&batsManTeamA[i].sixes);
            getchar();
        }
        for(int i=0; i<8; i++){
            gotorc(26+(i+1),11);
            fgets(bowlerTeamA[i].name,30,stdin);
            gotorc(26+(i+1),37);
            scanf("%f",&bowlerTeamA[i].overs);
            gotorc(26+(i+1),46);
            scanf("%d",&bowlerTeamA[i].maiden);
            gotorc(26+(i+1),52);
            scanf("%d",&bowlerTeamA[i].runs);
            gotorc(26+(i+1),58);
            scanf("%d",&bowlerTeamA[i].wicket);
            gotorc(26+(i+1),68);
            scanf("%d",&bowlerTeamA[i].extra);
            gotorc(26+(i+1),75);
            scanf("%f",&bowlerTeamA[i].economy);
            getchar();
        }

    }
    calculate();
    return;
}
void calculate()
{
    int count,i;
    
    count = 0;
    for(i=0; i<11; i++)
        count += batsManTeamA[i].runs;
    inningsA.totalRuns = count;

    count = 0;
    for(i=0; i<11; i++)
        count += batsManTeamB[i].runs;
    inningsB.totalRuns = count;

    count = 0;
    for(i=0; i<8; i++)
        count += bowlerTeamA[i].overs;
    inningsA.overPlayed = count;

    count = 0;
    for(i=0; i<8; i++)
        count += bowlerTeamB[i].overs;
    inningsB.overPlayed = count;

    count = 0;

    inningsA.runRate = (inningsA.totalRuns/inningsA.overPlayed);
    inningsB.runRate = (inningsB.totalRuns/inningsB.overPlayed);

    return;
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
void fileWrite()
{   
    fp = fopen(directory,"a+");
    //strcpy(directory,"File//");
    rewind(fp);
    fwrite(&gameDetails,sizeof(gameDetails),1,fp);
    fclose(fp);
    
    fp = fopen(directory,"a+");
    fseek(fp,0,SEEK_END);
    fwrite(&inningsA,sizeof(inningsA),1,fp);
    fclose(fp);
    
    fp = fopen(directory,"a+");
    fseek(fp,0,SEEK_END);
    for(int i=0; i<11; i++)
        fwrite(&batsManTeamA[i],sizeof(batsManTeamA[0]),1,fp);
    fclose(fp);
    
    fp = fopen(directory,"a+");
    fseek(fp,0,SEEK_END);
    for(int i=0; i<8; i++)
        fwrite(&bowlerTeamB[i],sizeof(bowlerTeamB[0]),1,fp);
    fclose(fp);

    fp = fopen(directory,"a+");
    fseek(fp,0,SEEK_END);
    fwrite(&inningsB,sizeof(inningsB),1,fp);

    fp = fopen(directory,"a+");
    fseek(fp,0,SEEK_END);
    for(int i=0; i<11; i++)
        fwrite(&batsManTeamB[i],sizeof(batsManTeamB[0]),1,fp);
    fclose(fp);

    fp = fopen(directory,"a+");
    fseek(fp,0,SEEK_END);
    for(int i=0; i<8; i++)
        fwrite(&bowlerTeamA[i],sizeof(bowlerTeamA[0]),1,fp);
    fclose(fp);
    
    return;
}
void fileRead()
{   
    fileNameMaker();

    fp = fopen(directory,"r");
    strcpy(directory,"File//");
    rewind(fp);
    
    fread(&gameDetails,sizeof(gameDetails),1,fp);
 
    fread(&inningsA,sizeof(inningsA),1,fp);

    for(int i=0; i<11; i++)
        fread(&batsManTeamA[i],sizeof(batsManTeamA[0]),1,fp);
    
    for(int i=0; i<8; i++)
        fread(&bowlerTeamB[i],sizeof(bowlerTeamB[0]),1,fp);


    fread(&inningsB,sizeof(inningsB),1,fp);

    for(int i=0; i<11; i++)
        fread(&batsManTeamB[i],sizeof(batsManTeamB[0]),1,fp);

    for(int i=0; i<8; i++)
        fread(&bowlerTeamA[i],sizeof(bowlerTeamA[0]),1,fp);
    
    fclose(fp);
    getchar();
    system("clear");
    printt();

}
void fileNameMaker()
{   
    printf("Enter the filename: ");
    scanf(" %[^\n]",filename);
    
    // puts("Before cat: ");
    // puts(filename);
    // puts(extension);
    // puts(directory);
    strcat(filename,extension); // imran.txt
    strcat(directory,filename); //File//imran.txt
    // puts("After cat: ");
    // puts(filename);
    // puts(extension);
    // puts(directory);
    // FILE *ft = fopen(directory,"w+");
}
void printt()
{
    system("clear");
    display();

    gotorc(1,16);
    printf("%s",gameDetails.copmetitionName);
    gotorc(1,47);
    printf("%s",gameDetails.venue);
    gotorc(3,16);
    printf("%s",gameDetails.matchBetween);
    gotorc(3,47);
    printf("%s",gameDetails.versus);
    gotorc(5,16);
    printf("%s",gameDetails.tossWonBy);
    gotorc(5,47);
    printf("%s",gameDetails.electedTo);
    gotorc(7,47);
    printf("%s",gameDetails.date);

    int inningsNO;
    gotorc(6,90);
    printf("Enter which innings score you want to see: ");
    scanf("%d",&inningsNO);
    if(inningsNO==1) {
        for(int i=0; i<11; i++)
        {
            gotorc(10+(i+1),13);
            printf("%s",batsManTeamA[i].name);
            gotorc(10+(i+1),39);
            printf("%d",batsManTeamA[i].runs);
            gotorc(10+(i+1),53);
            printf("%d",batsManTeamA[i].balls);
            gotorc(10+(i+1),65);
            printf("%d",batsManTeamA[i].fours);
            gotorc(10+(i+1),75);
            printf("%d",batsManTeamA[i].sixes);
            getchar();
        }
        for(int i=0; i<8; i++){
            gotorc(26+(i+1),11);
            printf("%s",bowlerTeamB[i].name);
            gotorc(26+(i+1),37);
            printf("%0.2f",bowlerTeamB[i].overs);
            gotorc(26+(i+1),46);
            printf("%d",bowlerTeamB[i].maiden);
            gotorc(26+(i+1),52);
            printf("%d",bowlerTeamB[i].runs);
            gotorc(26+(i+1),58);
            printf("%d",bowlerTeamB[i].wicket);
            gotorc(26+(i+1),68);
            printf("%d",bowlerTeamB[i].extra);
            gotorc(26+(i+1),75);
            printf("%0.2f",bowlerTeamB[i].economy);
            getchar();
        }
        gotorc(23,36);
        printf("%d",inningsA.totalRuns);
        gotorc(23,50);
        printf("%.0f",inningsA.overPlayed);
        gotorc(23,70);
        printf("%0.1f",inningsA.runRate);
    }
    else {

        for(int i=0; i<11; i++)
        {
            gotorc(10+(i+1),13);
            printf("%s",batsManTeamB[i].name);
            gotorc(10+(i+1),39);
            printf("%d",batsManTeamB[i].runs);
            gotorc(10+(i+1),53);
            printf("%d",batsManTeamB[i].balls);
            gotorc(10+(i+1),65);
            printf("%d",batsManTeamB[i].fours);
            gotorc(10+(i+1),75);
            printf("%d",batsManTeamB[i].sixes);
            getchar();
        }
        for(int i=0; i<8; i++){
            gotorc(26+(i+1),11);
            printf("%s",bowlerTeamA[i].name);
            gotorc(26+(i+1),37);
            printf("%f",bowlerTeamA[i].overs);
            gotorc(26+(i+1),46);
            printf("%d",bowlerTeamA[i].maiden);
            gotorc(26+(i+1),52);
            printf("%d",bowlerTeamA[i].runs);
            gotorc(26+(i+1),58);
            printf("%d",bowlerTeamA[i].wicket);
            gotorc(26+(i+1),68);
            printf("%d",bowlerTeamA[i].extra);
            gotorc(26+(i+1),75);
            printf("%0.2f",bowlerTeamA[i].economy);
        }
        gotorc(23,36);
        printf("%d",inningsB.totalRuns);
        gotorc(23,50);
        printf("%.0f",inningsB.overPlayed);
        gotorc(23,70);
        printf("%0.1f",inningsB.runRate);
    }
}