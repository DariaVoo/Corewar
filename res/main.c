#include <stdio.h>

int main()
{
	char *str = " ��Tching tching(Intercepteur), Bouh!Bouh!(bruits d'anti-jeu)                                                                               \0";
	for (int i = 0; i < 100; i++)
	{
		printf("%02x ", str[i]);
	}
	printf("\n");
	return (0);
}
