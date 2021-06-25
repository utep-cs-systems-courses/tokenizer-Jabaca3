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
int word_count;
//Counts the words in the array
int count_words(char *str){
  word_count =0;
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

//Copies the string over to a new memory allocation
char *copy_str(char *inStr, short len){
  char *str_copy= (char*)malloc(sizeof(char)*len);
  int i=0;
  while (i < len){
    *str_copy = *inStr;
    str_copy++;
    inStr++;
    i++;
  }
  str_copy-=len;
  return str_copy;
}


//TODO incrament tokens
char **tokenize(char* str){
  
  int word_size=0;
  int i =0;
  int total_words=count_words(str);
  
  char *word_end;
  char *word_begin;
  
  char **tokens = (char**)malloc(sizeof(char*)*total_words); // Where the tokens are stored
  char *pointer = word_start(str); // temp pointer for incramenting
  char **startAddress = tokens;
  while(i < total_words){
    
    word_begin = pointer;
    word_end = word_terminator(word_begin);    // Finding end of word
    pointer = word_end;                        // Preparing pointer for next iteration
    word_size = word_end - word_begin;         // Finding exact word size to copy over
    *tokens = copy_str(word_begin, word_size); // Coping over word to *tokens
    tokens++;
    pointer = word_start(word_end);            // Itterators for next word
    i++;
  } 
   return startAddress;
}
  

void print_tokens(char **tokens){
  while(*tokens){
    printf("\n%s", *tokens);
    tokens++;
  }
}

void free_tokens(char **tokens){
  while(*tokens){
    free(*tokens);
    tokens++;
  }
}





