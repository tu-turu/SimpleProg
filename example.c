#include <string.h>
#include <stdio.h>
#include <stdlib.h>

void RevertString(char *str);

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		printf("Usage: %s string_to_revert\n", argv[0]);
		return -1;
	}

	char *reverted_str = malloc(sizeof(char) * (strlen(argv[1]) + 1));
	strcpy(reverted_str, argv[1]);

	RevertString(reverted_str);

	printf("Reverted: %s\n", reverted_str);
	free(reverted_str);
	return 0;
}

void RevertString(char *str)
{
	int nextIndex = 0; // contains the index to be altered
	int lastIndex = (int)strlen(str) - 1;
	
	// bubble. Ex: hello -> ohell -> olhhel -> ollhe -> olleh
	while (nextIndex != lastIndex)
	{
		char temp = str[lastIndex];
		
		for (int i = lastIndex; i > nextIndex; i--)
		{
			str[i] = str[i - 1];
		}
		str[nextIndex] = temp;
		nextIndex++;
	}
}