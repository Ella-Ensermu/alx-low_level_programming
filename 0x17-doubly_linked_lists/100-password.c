#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
char password[100];
char command[150];
for (int i = 0; i <= 9999; i++)
{
sprintf(password, "%04d", i);
sprintf(command, "./crackme4 %s | grep OK", password);
if (system(command) == 0)
{
FILE *file = fopen("100-password", "w");
if (file != NULL)
{
fprintf(file, "%s", password);
fclose(file);
break;
}
else
{
fprintf(stderr, "Error: Unable to open file for writing.\n");
return (EXIT_FAILURE);
}
}
}
return (EXIT_SUCCESS);
}
