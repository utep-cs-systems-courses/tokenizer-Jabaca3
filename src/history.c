#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"
#include "history.h"

List *init_history(){
  List *user_history = (List*) malloc(sizeof(Item)*100);
}

void add_history(List *list, char *str){
  Item *node = list->root;
  int id = 1;
  
  //If we are barly starting history
  if (node == NULL) {
    list->root = (Item*) malloc(sizeof (Item));
    list->root->id = id;
    list->root->str = str;
    list->root->next = NULL;
  }
  
  //If history is already started
  else {
    while(node->next != NULL) {
      node = node->next;
      id++;
    }
    node->next = (Item*) malloc(sizeof (Item));
    node->next->id = id++;
    node->next->str = str;
    node->next->next = NULL;
  }
}

char *get_history(List *list, int id){
  Item *node = list->root;

  while(node != NULL){
    if(node->id == id){
      return node->str;
    }
    node = node->next;
  }
  return "YOUR STRING NOT FOUND :(";
}

void print_history(List *list){
  Item *node = list->root;
  while (node != NULL){
    printf("\n%s", node->str);
    node = node->next;
  }
}

void free_history(List *list){
  Item *node = list->root;
  while (node != NULL){
    free(node);
    node = node->next;
  }
  free(list);
}

