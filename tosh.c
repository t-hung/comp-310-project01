/*
 The Torero Shell (TOSH)
 *
 * Add your top-level comments here.
 */

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h> 
#include <sys/wait.h>
#include <readline/readline.h>

typedef enum { false, true } bool;

// TODO: add your function prototypes here as necessary


int main(int argc, char* argv[]){ 

	// TODO: add a call to signal to register your signal handler on 
	//       SIGCHLD here

	while(1) {
		// (1) read in the next command entered by the user
		char *cmdline = readline("tosh$ ");
		char *curDir;
		bool found;
		char newDirectory[100];

		// NULL indicates EOF was reached, which in this case means someone
		// probably typed in CTRL-d
		if (cmdline == NULL) {
			fflush(stdout);
			exit(0);
		}
		else if(cmdline == "exit") {
			fprintf(stdout, "Thank you for using tosh. Have a nice day!\n\n");
			exit(0);
		}
		else if(cmdline == "cd") {
			getcwd(curDir,50);

			if(argv[1] == NULL){
				getenv(curDir);
				chdir(curDir);
			}
			else if(argv[1] == ".."){
				char curChar;
				int i = strlen(curDir)-1;
				for(i; i>=0; i--){
					curChar = curDir[i];
					if(curChar == '/')
					{
						found = true;
					}

					if(found == true)
					{
						newDirectory[i] = curDir[i];
					}
				}
				curDir = newDirectory;
				chdir(curDir);
			}
			else if(chdir(argv[1]) == -1){
				fprintf(stderr, "%sDirectory not found.\n");
				exit(0);
			}
		}
		else{
			//some other stuff
			//parse the args
			//fork
			int child_pid=fork();
			if(child_pid==-1){
				//fork failed
			}
			else if(child_pid==0){
				//child
			}
			else{
				//parent
			}
			
		}

		fprintf(stdout, "DEBUG: %s\n", cmdline);

		// TODO: complete the following top-level steps
		// (2) parse the cmdline

		// (3) determine how to execute it, and then execute it

	}

	return 0;
}
