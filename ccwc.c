#include <string.h>
#include <stdio.h>

long int findSize(char file[]);

int main(int argc, char *argv[])
{
	char command[] = { argv[1][0], argv[1][1], '\0' };	
	char file[(strlen(argv[2])) + 1];
	int count = 1;
	file[strlen(argv[2]) + 1] = '\0';
	for (int i = 0; i <= strlen(argv[2]) + 1; i++){
		file[i] = argv[2][i];
		count += 1;
	}

	if (strcmp(command, "-c") == 0 ) {
		long int res = findSize(file);
		printf("%ld %s\n", res, file);
	}
	return 0;
}

long int findSize(char file[]){
	FILE* fp = fopen(file, "r");
	if (fp == NULL){
		printf("file error!\n");
		return -1;
	}

	fseek(fp, 0L, SEEK_END);	

	long int size = ftell(fp);

	fclose(fp);
	
	return size;
}
