#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
 char choice[10]; 
 char playername[20]; 

 int count2=0,count1=0;
 int countplayer=0;
 int countcomp=0;
int tie_game(void){
     do{
        
        printf("extra turn: %d\n", countplayer+countcomp+1);
        printf("choose one: rock, paper, scissor\n");
        scanf("%s",choice);
        puts(choice);
        printf("computers turn now\n");
        const char* option[]={"rock","paper","scissor"};
        srand(time(NULL));
        const char*choseopt=option[rand()%3];
        printf("computer choosed: %s\n",choseopt);
        if(strcmp(choice,choseopt)==0){ 
            printf("it's a tie, paly again\n");
        }
        else if((strcmp(choice,"rock")==0 && strcmp(choseopt,"scissor")==0)||(strcmp(choice,"paper")==0 && strcmp(choseopt,"rock")==0)||(strcmp(choice,"scissor")==0 && strcmp(choseopt,"paper")==0)){
            printf("player: %s is wins\n",playername);
            countplayer++;
        }
        else{
            printf("computer wins\n");
            countcomp++;
        }
    }while(countplayer==countcomp);

    if(countplayer>countcomp){

        return countplayer;
    }
    else{
        return countcomp;
    }

}
 
int main(){
    printf("********ROCK PAPER SCISSOR GAME*******\n");
    

    printf("enter your name: ");
    scanf("%s",&playername);
    puts(playername);
    
    for(int i=1;i<=3;i++){
        printf("turn: %d\n",i);
        printf("choose one: rock, paper, scissor\n");
        scanf("%s",choice);
        puts(choice);
        printf("computers turn now\n");
        const char* option[]={"rock","paper","scissor"};
        srand(time(NULL));
        const char*choseopt=option[rand()%3];
        printf("computer choosed: %s\n",choseopt);

        if(strcmp(choice,choseopt)==0){
            printf("it's a tie, paly again\n"); 
            tie_game();
            count1+=countplayer;
            count2+=countcomp;
        }
        else if((strcmp(choice,"rock")==0 && strcmp(choseopt,"scissor")==0)||(strcmp(choice,"paper")==0 && strcmp(choseopt,"rock")==0)||(strcmp(choice,"scissor")==0 && strcmp(choseopt,"paper")==0)){
            printf("player: %s is wins\n",playername);
            count1++;
        }
        else{
            printf("computer wins\n");
            count2++;
        }
    }
    
    
    if(count1>count2){
        printf("*****game winner is******\n");
        printf(" %s\n",playername);
    }
    else{
        printf("computer\n");
    }
        return 0;
}