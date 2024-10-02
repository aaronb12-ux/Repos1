#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#include "inputval.h"
#include "playgame.h"

bool isValidFormat(const int numArgsRead, const int numArgsNeed)
//this function validates input. It makes sure that the user enters one argument, and checks if that one argument is followed by nothing
//
{
  bool formatIsGood = numArgsRead == numArgsNeed;
  //format is good if only one argument is entered
  char character;
  do
  {
    scanf("%c", &character);
    //this while loop scans characters in the input stream
    if (!isspace(character))
    //if we come across something that is not white space, then the input is not valid
      formatIsGood = false;
  } while (character != '\n');
  return formatIsGood;
}

int getValidInt(int num_cols)
{
  
  int num;
  const int numArgsNeeded = 1;
  int numArgsRead;
  do
  {

    printf("Enter a column between 0 and %d to play in : ", num_cols - 1);
    numArgsRead = scanf(" %d", &num);
    //reading one integer

  } while (!isValidFormat(numArgsRead, numArgsNeeded));
  return num;
}
