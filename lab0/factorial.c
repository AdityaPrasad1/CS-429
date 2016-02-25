#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
	int factorial = 1;
	int i;

	if(argc == 1) {
		printf("%s\n", "Error: please supply an integer on the command line.");
	}

	else if(atoi(argv[1]) == 0) {
		printf("%i\n", 1);
	}

	else if(atoi(argv[1]) > 0) {
		for(i = atoi(argv[1]); i > 1; i = i-1) {
			factorial *= i;
		}
		printf("%i\n", factorial);
	}

}
