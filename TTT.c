#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<ctype.h>
#include<time.h>

const char PLAYER='0';
const char CPU='x';
int i,j;
char cell[3][3];

void board(); // to display the board with current contents #DONE
void reset(); //to reset the board #DONE
void player();//player's move
int cpu();//CPU's move
int vacancy();//Checks for empty slots
char winka();//Declares winner
void winner();

void main(){
    reset();
    board();
    while(winka()==' ' && vacancy()!=0){
            player();
            system("cls");
            if(winka()==' ' && vacancy()!=0){
                cpu();
                board();
            }
            else{
                board();
                break;
            }
    }
    winner();
    sleep(4);
    printf("\n\nPLAY AGAIN?");
}

void board(){
    printf("| %c | %c | %c |",cell[0][0],cell[0][1],cell[0][2]);
    printf("\n|---|---|---|\n");
    printf("| %c | %c | %c |",cell[1][0],cell[1][1],cell[1][2]);
    printf("\n|---|---|---|\n");
    printf("| %c | %c | %c |\n",cell[2][0],cell[2][1],cell[2][2]);
}
void reset(){
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            cell[i][j]=' ';
        }
    }
}
void player(){
    do{
        printf("Row #");
        scanf("%d",&i);
        printf("Column #");
        scanf("%d",&j);
        i--;j--;
        if(cell[i][j]!=' '){
            printf("Invalid move\n");
        }
        else{
            cell[i][j]=PLAYER;
            break;
        }
        }while(vacancy()!=0);
}
int cpu(){
    do{
        srand(time(0));
        i=rand()%3;
        j=rand()%3;
    }while(cell[i][j]!=' ');
    cell[i][j]=CPU;
}

int vacancy(){
    int count=0;
    for(i=0;i<3;i++){
        for(j=0;j<3;j++){
            if(cell[i][j]==' ')
                count++;
        }
    }
    return count;
}

char winka(){
    //rows
    for(i=0;i<3;i++){
        if(cell[i][0]==cell[i][1] && cell[i][0]==cell[i][2])
            return cell[i][0];
    }
    //columns
    for(j=0;j<3;j++){
        if(cell[0][j]==cell[1][j] && cell[0][j]==cell[2][j])
            return cell[0][j];
    }
    //Diagonals
    if((cell[1][1]==cell[2][2] && cell[1][1]==cell[0][0]) || (cell[1][1]==cell[0][3] && cell[1][1]==cell[3][0])){
        return cell[1][1];
    }
    return ' ';
}
void winner(){
    if(winka()=='x')
        printf("CPU WINS!");
    else if(winka()=='0')
        printf("PLAYER WINS!");
    else
        printf("Its a DRAW!");
}
