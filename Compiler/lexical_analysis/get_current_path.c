#include <stdio.h>
#include <limits.h>


#ifdef __linux__ 

#elif _WIN32
#include <direct.h>

#else

#endif


#include <windows.h>

int main() {
	
   char cwd[PATH_MAX];
   if (getcwd(cwd, sizeof(cwd)) != NULL) {
       printf("Current working dir: %s\n", cwd);
   } else {
       perror("getcwd() error");
       return 1;
   }
   
   return 0;
}