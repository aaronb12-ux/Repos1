#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#include "inputval.h"
#include "playgame.h"


bool isValidFormat(const int numArgsRead, const int numArgsNeed){
    bool formatIsGood = numArgsRead == numArgsNeed;
    char character;
    do{
      scanf("%c", &character);
      if(!isspace(character))
        formatIsGood = false;
    }while(character != '\n');
    return formatIsGood;
}

int getValidInt(int num_cols){
    int num;
    const int numArgsNeeded = 1;
    int numArgsRead;
    do{
       
       printf("Enter a column between 0 and %d to play in : ", num_cols - 1);
       numArgsRead = scanf(" %d", &num);
       
    }while(!isValidFormat(numArgsRead, numArgsNeeded));
    return num;
    }


