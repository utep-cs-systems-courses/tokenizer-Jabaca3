#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"

//returns true if the character is a space=' '
int space_char(char c){
  if (c == '\t' || c ==' '|| c=='\0'){
    return 1;
  }
  return 0;
}

//returns true if the character is NOT a space=' '
int non_space_char(char c){
  if (c == '\t' || c ==' ' || c =='\0'){
    return 0;
  }
  return 1;
}

//Returns the start of a word given a pointer 
char *word_start(char *str){
  while(space_char(*str)){
    str++;
  }
  return str;
}

//Returns the end of the word if its not a word terminator
char *word_terminator(char *word){
  while(non_space_char(*word)){
    word++;
  }
  return word;
}

int count_words(char *str){
  int word_count =0;
  while(*str != '\0'){
  }
}






