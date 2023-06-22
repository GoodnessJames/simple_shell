Project Title: Simple Shell (Unix-like Command Line Interpreter)

Overview
This project entails building a command line interpreter that has similar functionalities to the using Unix Shell. This project depicts a display prompt that waits for commands from users, it executes the command and handles errors effectively.

Flow of Program Execution
The step-by-step stages of the execution of the shell program written in this project includes:
//Betty, we will explain the program execution with the files we have created.//

Unix Shell Description
The Unix shell runs a shell script through the command line such as file manipulation, printing, and execution. The shell takes up form as a COMMAND LINE INTERPRETER. It accepts commands from users, reads interprets, and executes the built-in shell command and programs.

Unix shell has built-in SHELL COMMANDS that can be used to create directories, list files, print output, modify permission, and even write text.

The shell's ENVIRONMENT accommodates VARIABLES that can be used in the script and also in the command line interface (variables like path, user settings and configuration data).

It builds reuseable code. SHELL FUNCTIONS can accept arguments and return value.

Custom Shell Description
The custom shell we created allows command input, execution, and effective error management for invalid commands. The custom shell when invoked display a prompt ready to accept input from the user and after execution, the prompt is displayed again.
The custom shell command interface supports error handling, built-in commands, logical operators, and variable replacement.

HOW TO INVOKE THE CUSTOM SHELL
The shell is invoked with the following steps:
1. Compile: Compile all the source codes written for the shell program by ruuning this command: gcc -Wall -Werror -pedantic -std=gnu89 
2. Execute: Execute the shell program by typing: ./hsh
This will take you straight into the custom shell environment. To verify of you issued the right command, you should notice a change in the commamd prompt by spoting the smiling emoji :).
You can intereact with the command line as much as you can by issuing valid shell commands and when you are done, type "exit" to exit the prompt.
