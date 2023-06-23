# Project Title: Simple Shell (Simple Command Line Interpreter)

## Overview
This project entails building a command line interpreter that reads commands from either a file or standard input and executes them just like the Unix Shell.

## The Unix Shell
The Unix shell runs a shell script through the command line such as file manipulation, printing, and execution. The shell takes up the form of a command line interpreter. It accepts commands from users, reads, interprets, and executes the built-in shell command and programs.

Unix shell has built-in shell commands that can be used to create directories, list files, print output, modify permission, and even write text.

The shell's environment accommodates variables that can be used in the script and also in the command line interface (variables like path, user settings, and configuration data).

## Simple Shell Description
The custom shell allows command input, execution, and effective error management for invalid commands. The custom shell when invoked displays a prompt ready to accept input from the user and after execution, the prompt is displayed again.

### Key Functionalities of the Simple Shell:
- Displays a prompt ": ) " and waits for user input.
- Runs all commands of type "executable program" (ls and /bin/ls).
- Runs the following build_in commands: exit, env, setenv, and unsetenv.
- Handles commands with arguments.
- Handles the PATH global variable.
- Handles The EOF (End Of File) condition.
- Handles the Ctrl + C signal
  
### How to Use the Simple Shell:
The shell is invoked with the following steps:
- **Clone:** Clone the simple shell repository using this command (you need to have git installed on your machine first):

  git clone https://github.com/GoodnessJames/simple_shell.git
- **Navigate:** Navigate to the simple shell directory by using this command: cd simple_shell
- **Compile:** Compile all the source codes written for the shell program by running this command:

  gcc -Wall -Werror -pedantic -std=gnu89 *.c -o hsh 
- **Execute:** Execute the shell program by typing: ./hsh
This will take you straight into the custom shell environment. To verify of you issued the right command, you should notice a change in the command prompt by spotting the smiling emoji. You can interact with the command line as much as you can by issuing valid shell commands.

  **Exit:** When you are done and want to exit, type "exit" to exit the shell prompt or press the key combination: Ctrl + D. 

## Content of the Repository
- **AUTHORS:** This file contains the list of collaborators of this project.
- **shell.h:** This is the header file that contains all function prototypes with their parameters and return type.
- **README.md:** This file describes all you need to know about this project.

## List of Allowed Functions and System Calls for this Project:
access, chdir, close, closedir, execve, exit, fflush, fork, free, getcwd, getline, getpid, isatty, kill, malloc, open, opendir, perror, read, readdir, signal, stat(_xstat), lstat(_lxstat), fqstat(_fxstat), strtok, wait, waitpid, wait3, wait4, write.

## Flow of Program Execution
The step-by-step stages of the execution of the shell program written in this project include:
- The entry point of the program is the **main** function. In this function, several variables are declared, including **len** and **size** as ssize_t and size_t respectively, **buffer** as a character pointer, **value**, **pathname**, and **args** as character pointers, **head** as a pointer to a **list_path** struct, and **fpt** as a function pointer. 
- It sets the **SIGINT** signal handler to the **‘check_sig’** function using signal. 
- It enters a while loop that continues until len is equal to EOF (end of file). Within the loop, it calls **‘check_input’**(isatty ) to print the prompt if the input is coming from a terminal. 
- It uses **‘getline’** to read a line of input from stdin into a buffer, storing the number of characters read in len and the allocated size of buff in size. 
- It calls **‘check_EOF’** function to handle the end of file condition based on the value of len and buff. 
- It uses **‘splitStr’** to split the line of input stored in buff into an array of strings (av), using spaces and newline characters as delimiters. 
- It checks if av is empty or if the first element av[0] is empty. If so, it calls the **‘execute’** function. 
- If av is not empty and av[0] is not empty, it proceeds to the next steps. It retrieves the value of the "PATH" environment variable using **‘_getenv’** and stores it in value.
- It creates a linked list of directories from the "PATH" value by calling **‘linkpath’** and passing value. The resulting list is stored in ‘head’. 
- It uses **‘findpath’** to find the full path of the command specified by av[0] by traversing the linked list of directories (head). The result is stored in pathname. 
- It calls **‘checkbuiltin’** to check if the command is a built-in command. If a matching built-in command is found, the corresponding function is stored in fpt. 
- If a built-in command function is found (fpt is not NULL), it frees buff and calls the built-in command function with arv as an argument. 
- If a built-in command function is not found and pathname is not found (meaning the command is not a built-in and not found in any of the directories in the "PATH"), it calls **‘execute’** with av as an argument. 
- If pathname is found (meaning the command is not a built-in and found in one of the directories in the "PATH"), it updates av[0] to be the full path stored in pathname, frees the previous av[0], and calls ‘execute’ with av as an argument. 
- After the loop ends, it frees the linked list of directories using free_list. 
- It frees the av array of strings using free_av. 
- It frees the buffer allocated by **getline.** 
- Finally, it returns 0 to indicate successful execution of the program.

## Testing and Validation

## Conclusion
