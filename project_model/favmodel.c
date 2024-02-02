#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "mystrings.h"

char*
find_pwd(char *envp[])
{
	int i = 0;
	char *env_var = envp[i];
	while(env_var != NULL)
	{
		//	printf("%s\n", env_var);
		
		char *key = strtok(env_var, "=");
		char *value = strtok(NULL, "=");
		if(strcmp(key, "PWD") == 0)
		{
			return value;
		}	
		i++;
		env_var = envp[i];
	}
}

void
set_models_directory(char *path)
{
	char *path_env_var = "PATH_OF_MY_MODELS=";
	strcat(path_env_var, path);
	printf("%s\n", path_env_var);
}




