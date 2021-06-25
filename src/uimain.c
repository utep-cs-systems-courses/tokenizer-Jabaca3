#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"
#include "history.h"

int main(){
  while(1){
    
  printf("\n$ ");
  char user_input[100];
  List *history = init_history();
  fgets(user_input, 100, stdin);
  printf("%s\n", user_input);

  //Checking user input for history request
  if(user_input[0] == 33 && (user_input[1] > 48 && user_input[1] < 58)){
    
    //Recalling history
    printf("%s\n", "--------recalling history!------------");
    int num = atoi(user_input+1);
    char* token = get_history(history, num);
    printf("%s%s\n","$ ", token);

    //Printing tokens from input
    char** tokenized = tokenize(token);
    print_tokens(tokenized);
  }
  
  else{
    char **tokens= tokenize(user_input);
    print_tokens(tokens);
    printf("%s\n", "---------adding history!---------------");
    char* copy = copy_str(user_input, str_length(user_input));
    add_history(history, copy); //works
    }
  }
}










