#include <stdio.h>
#include "favmodel.h"

int main(int argc, char *argv[], char *envp[])
{
	char *pwd = find_pwd(envp);
	printf("this is pwd: %s\n", pwd);
	set_models_directory("teste");
	return 0;
}

