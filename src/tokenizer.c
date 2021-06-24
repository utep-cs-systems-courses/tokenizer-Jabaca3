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

//Counts the words in the array
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

//returns the length of the string
int str_length(char *str){
  int count;
  for(count=0; *str != '\0'; str++){
    count++;
  }
  return count;
}
//Copys the string over to a new memory allocation
char *copy_str(char *inStr, short len){
  char *str_copy= (char*)malloc(sizeof(char)*len);
  while (*inStr != '\0'){
    *str_copy = *inStr;
    str_copy++;
    inStr++;
  }
  str_copy-=len;
  return str_copy;
}


char **tokenize(char* str){

}
void print_tokens(**tokens){

}
void free_tokens(char **tokens){

}





