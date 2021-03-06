#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "dictionary.h"

void print_anagram(VNode* head){
	VNode* current = head;
	while(current !=NULL){
		printf("%s ", current->value);
		current = current->next;
	}
}


int com(const void *a, const void *b){
	return *(char*)a - *(char*)b;
}

int main (int argc, char ** argv) {
	static DNode* dictionary [DEFAULT_HASH_SIZE];

	FILE * fp = fopen("words.txt","r");
	if(fp == NULL)  {
  		printf("Error opening file words.txt\n");
  		return 1;
  	}

	char buffer[30];
	while(fscanf(fp, "%s", buffer) != EOF){
		char * str = copystr(buffer);
		qsort(str, strlen(str), sizeof(char), com);
		set(dictionary, DEFAULT_HASH_SIZE, str, buffer);
	}
	fclose(fp);

	int count = 0;
	for (int i = 0; i < DEFAULT_HASH_SIZE; i++){
		if (dictionary[i] != NULL){
			DNode *current = dictionary[i];
			while (current != NULL){
				if ((current -> values) -> next != NULL){
					print_anagram(current -> values);
					printf("\n");
					count ++;
				}
				current = current -> next; 
				}
				
			}
		}
	
	printf("The total number of anagram is %d\n", count);
	free_dictionary(dictionary, DEFAULT_HASH_SIZE);



  	return 0;
}