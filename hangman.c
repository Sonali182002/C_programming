#include<stdio.h>
#include<stdbool.h>
#include<time.h>
#include<stdlib.h>
#include<string.h>

bool check_ans(char*choseword,char *input) {
    // this fuction is checking the user's input with the word to see if they are same or not.
    for(int i=0;i<strlen(choseword);i++){
        bool found=false;
        for(int j=0;j<strlen(input);j++){
            if(choseword[i]==input[j]){
                found=true;
                break;
            }
        }
        
        if(!found){
            return false;
        }
    }
    return true;
    

}
int printbody(int loss){
char* platform[]={
    "    |====|\n"
    "    |    |\n"
    "    |    |\n"
    "    |    |\n"
    "    0    |\n"
    "   -|-   |\n"
    "    /\\   |\n",

    "    |====|\n"
    "    |    |\n"
    "    |    |\n"
    "    0    |\n"
    "   -|-   |\n"
    "    /\\   |\n",

    "    |====|\n"
    "    |    |\n"
    "    0    |\n"
    "   -|-   |\n"
    "    /\\   |\n",

    "    |====|\n"
    "    0    |\n"
    "   -|-   |\n"
    "    /\\   |\n",
};
if(loss==0){
    printf("%s", platform[0]);
    return 0;
}
if(loss==1){
    printf("%s",platform[1]);
    return 0;
}
if(loss==2){
    printf("%s",platform[2]);
    return 0;
}
if(loss==3){
    printf("%s",platform[3]);
    return 0;
}

}
int mainbody(){
    int loss=0;
    printbody(loss);
    char word[10][10]={"india","code","happy","north","fabulous","mitigate","extreme","far","okra","bettles"};
    srand(time(NULL));
    const char *choseword=word[rand()%10];
   //printf("%s",choseword);
   
   printf("word you need to guess: ");
     for(int i=0;i<strlen(choseword);i++){
         if(rand()%2==0){
             printf("-");
         }
         else{
             printf("%c",choseword[i]);
         }
    }
    printf("\n");
    
    //input section code
    int guess;
    char input[20];
    int win=0;
    printf("\nyou can make three guesses\n");
    printf("***guess the letters to complete a word***\n");
    for(guess=1;guess<=3;guess++){
        printf("%d guess\n",guess);
        //printf("***guess the letters to complete a word***\n");
        printf("enter your guess word: \n");
        scanf("%s",input);
        if(input=='*'){
            return 0;
        }
        bool result=check_ans(choseword,input);
        if(result){
            printf(" you've got it!!\n");
            win++;
            break;
        }
        else{
            printf("please try again\n");
            loss++;
            printbody(loss);
        }
        //if(result)break;

    }
   /*/ if(win>loss){
        printf("you win!!!.You are safe!!!!!\n");
    }
    else if(win==loss){
        printf("it's tie!!\n");
    }
    else{
        printf("you got hanged!!!!\n");
    }*/
    printf("the correct word was: %s",choseword);
    
    return 0;

}

int rule(){
    char input;
    
    printf("****GAME RULES****\n 1. you will be given an uncompleted word\n"
            "2. you will have three chances to guess the correct word\n "
            "3. if you guessed correctly you will be save and not get hanged\n"
            "4. if you guessed wrong you will get hanged\n Want to try this game!, press 2 to start OR press '*' to exit!\n");
            printf("enter your choice: ");
            fflush(stdin); // to clear input buffer
            scanf("%c",&input);
            if(input=='2'){
                mainbody();
            }
            else if(input=='*'){
                return 0;
            }
            else{
                printf("invalid input. please try again!\n");
            }
    
return 1;
}


int main(){
    printf("\t------------welcome to the HANGMAN Game-----------\n");
    printf("\n");
    printf(": menu\n1.game rules\n2.play game\n3.exit\n");
    printf("\n");
    int choice;
    printf("please select your choice 1,2, or 3\n");
    scanf("%d",&choice);
    switch(choice){
        case 1:
         rule();
         break;
        case 2:
         printf(" \n****Game begins****\n");
         mainbody();
         break;
        case 3:
         printf("\nenter '*' to exit\n");
         break;
        default:
         printf("invalid input. PLease try again!\n");
         break;    
    }
    

}




    

    


