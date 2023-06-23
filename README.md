# Project Title: Simple Shell (Unix-like Command Line Interpreter)

## Overview
This project entails building a command line interpreter that reads commands from either a file or standard input and executes them just like the Unix Shell.

## The Unix Shell
The Unix shell runs a shell script through the command line such as file manipulation, printing, and execution. The shell takes up the form of a command line interpreter. It accepts commands from users, reads, interprets, and executes the built-in shell command and programs.

Unix shell has built-in shell commands that can be used to create directories, list files, print output, modify permission, and even write text.

The shell's environment accommodates variables that can be used in the script and also in the command line interface (variables like path, user settings and configuration data).

## Simple Shell Description
The custom shell allows command input, execution, and effective error management for invalid commands. The custom shell when invoked displays a prompt ready to accept input from the user and after execution, the prompt is displayed again.

### Key Functionalities of the Simple Shell:
- Displays a prompt ":) " and waits for user input.
- Runs all commands of type "executable program" (ls and /bin/ls).
- Runs the following build_in commands: exit, env, setenv, and unsetenv.
- Handles commands with arguments.
- Handles the PATH global variable.
- Handles The EOF (End Of File) condition.
- Handles the Ctrl + C signal
  
### How to Invoke the Simple shell:
The shell is invoked with the following steps:
- **Compile:** Compile all the source codes written for the shell program by running this command: gcc -Wall -Werror -pedantic -std=gnu89 *.c -o hsh 
- **Execute:** Execute the shell program by typing: ./hsh
This will take you straight into the custom shell environment. To verify of you issued the right command, you should notice a change in the command prompt by spotting the smiling emoji :).
- You can interact with the command line as much as you can by issuing valid shell commands and when you are done, type "exit" to exit the prompt.

## Content of the Repository
- **AUTHORS:** This file contains the list of collaborators of this project.
- **shell.h:** This is the header file that defines and shows all prototypes with their arguments and return type.
- **README.md:** This file describes all you need to know about this project.

## List of Allowed Functions and System Calls for this Project:
access, chdir,close, closedir, execve, exit, fflush, fork, free, getcwd, getline, getpid, isatty, kill, malloc, open, opendir, perror, read, readdir, signal, stat(_xstat), lstat(_lxstat), fqstat(_fxstat), strtok, wait, waitpid, wait3, wait4, write.

## Flow of Program Execution
The step-by-step stages of the execution of the shell program written in this project include:

## Testing and Validation

## Conclusion
