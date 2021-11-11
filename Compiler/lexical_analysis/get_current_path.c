#include <stdio.h>
#include <limits.h>


#ifdef __linux__ 

#elif _WIN32
#include <direct.h>

#else

#endif




int get_current_path(){
	char cwd[PATH_MAX];
	if (getcwd(cwd, sizeof(cwd)) != NULL) 
	{
		printf("Current working dir: %s\n", cwd);
	} else {
		
		perror("getcwd() error");
		return 1;
	}
	return 0;
}

#ifndef main
#define main main
int main() {
	printf(__FILE__);
	get_current_path();

   
   return 0;
}
#endif