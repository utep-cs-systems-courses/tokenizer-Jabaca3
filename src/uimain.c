#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"
#include "history.h"

int main(){
  List *history = init_history();
  while(1){
    
    printf("\n$ ");
    char user_input[100];
    fgets(user_input, 100, stdin);
    printf("%s\n", user_input);

    //Checking user input for history request
    if(user_input[0] == 33 && (user_input[1] > 47 && user_input[1] < 58)){
      printf("%s\n", "--------recalling history!------------");
      int num = atoi(user_input+1);
      char* token = get_history(history, num);
      
      // If token exist print it
      if(*token){
	printf("%s%s\n","$ ", token);
    }
  }
    // Print history with !p
    else if(user_input[0] == 33 && user_input[1] == 112){
      printf("%s", "-----Printing history-----");
      print_history(history);
    }
    // Free tokens !f
    else if(user_input[0] == 33 && user_input[1]== 102){
      printf("%s", "-----Freeing history-----");
      free_history(history);
    }
    
  else{
    char **tokens= tokenize(user_input);
    print_tokens(tokens);
    printf("%s\n", "---------adding history!---------------");
    char *copy = copy_str(user_input, str_length(user_input));
    printf("%s\n", copy);
    add_history(history, copy);
    
    }
  }
}










