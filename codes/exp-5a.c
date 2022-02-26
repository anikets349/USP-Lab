#include<stdio.h>
#include<stdlib.h>
int main(int argc, char *argv[], char *envp[]) {
	printf("1. using envp\n2. using environ\n3. using getenv\n");
	printf("Enter your choice : ");
	int choice;
	scanf("%d", &choice);
	
	int i;
	extern char ** environ;
	char **ptr;
	char *env;

	
	switch (choice) {
		case 1 :
			// Print environment list using global variable environ
			for (i = 0; envp[i] != (char *) 0; i++) {
				printf("%s\n", envp[i]);
			}
			break;
		case 2 :
			// Print environment list using envp
			for (ptr = environ; *ptr; ptr++) {
				printf("%s\n", *ptr);
			}
			break;
		case 3 :
			// Print environment string using getenv function
			env = getenv("HOME");
			printf("%s\n", env);
			env = getenv("SHELL");
			printf("%s\n", env);
			env = getenv("PATH");
			printf("%s\n", env);
			env = getenv("TERM");
			printf("%s\n", env);
			break;
		default :
			printf("No matching choice found.");
	}
	return 0;
}
