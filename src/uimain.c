#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"
#include "history.h"

int main(){
  printf("\n$ ");
  char user_input[100];
  fgets(user_input, 100, stdin);

  // testing function space char / non space char (WORKS)
  //int j = space_char(*user_input);
  //printf("%d\n",j);

  //testing function word start (WORKS)
  //char* start = word_start(user_input);
  //printf("\n%s", "Word start running: \n");
  //printf("%c\n", *start);
  
  //testing function word terminator (Works)
  //char* end = word_terminator(start);
  //printf("%c\n", *end);
    
  //testing count words function (Works)
  //printf("\n%s", "Count words Running: \n");
  //printf("%d\n", count_words(user_input));

  //testing string length this includes zero terminator
  int len = str_length(user_input);
  printf("\n%s", "String length Running: \n");
  printf("%d\n", len);

  //testing copy string
  //char new_string = copy_str(user, len);
  //printf("\n%s", "Copy String: \n");
  //printf("%s\n", new_string);




  
}
