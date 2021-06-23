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
    str = word_start(str);
    if(non_space_char(*str)){
    word_count++;
    }
    str = word_terminator(str);
  }
  return word_count;
}

int str_length(char *str){
  int count;
  for(count=0; *str != '\0'; str++){
    count++;
  }
  return count;
}

char *copy_str(char *inStr, short len){
  char *new_string = (char*)malloc(sizeof(char)*len+1);
  int i=0;
  while( i < len){
    new_string = inStr;
    new_string++;
    inStr++;
    i++;
  }
  return new_string;
}





