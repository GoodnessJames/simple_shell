# Project Title: Simple Shell (Simple Command Line Interpreter)

## Overview
This project entails building a command line interpreter that reads commands from either a file or standard input and executes them just like the Unix Shell.

## The Unix Shell
The Unix shell runs a shell script through the command line such as file manipulation, printing, and execution. The shell takes up the form of a command line interpreter. It accepts commands from users, reads, interprets, and executes the built-in shell command and programs.

Unix shell has built-in shell commands that can be used to create directories, list files, print output, modify permission, and even write text.

The shell's environment accommodates variables that can be used in the script and also in the command line interface (variables like path, user settings, and configuration data).

## Simple Shell Description
The simple shell allows command input, execution, and effective error handling for invalid commands. The custom shell when invoked displays a prompt ready to accept input from the user and after execution, the prompt is displayed again.

### Key Functionalities of the Simple Shell:
- Displays a prompt ": ) " and waits for user input.
- Runs all commands of type "executable program" (ls and /bin/ls).
- Runs the following built_in commands: exit, env, setenv, and unsetenv.
- Handles commands with arguments.
- Handles the PATH global variable.
- Handles The EOF (End Of File) condition.
- Handles the Ctrl + C signal

### How to Use the Simple Shell:
The shell is invoked with the following steps:
- **Clone:** Clone the simple shell repository using this command (you need to have git installed on your machine first):

```
  git clone https://github.com/GoodnessJames/simple_shell.git
```

- **Navigate:** Navigate to the simple shell directory by using this command: cd simple_shell
- **Compile:** Compile all the source codes written for the shell program by running this command:

```
  gcc -Wall -Werror -pedantic -std=gnu89 *.c -o hsh
```

- **Execute:** Execute the shell program by typing: ./hsh

Upon issuing the above command, you should notice a change in the command prompt by spotting the smiling emoji. You can interact with the shell as much as you want by issuing valid shell commands.

  **Exit:** When you are done and want to exit, type "exit" to exit the shell prompt or press the key combination: Ctrl + D.

## Content of the Repository
- **AUTHORS:** This file contains the list of collaborators of this project.
- **shell.h:** This is a header file that contains all function prototypes and struct type definitions used in this project.
- **README.md:** This file describes all you need to know about this project.

## List of Allowed Functions and System Calls for this Project:
access, chdir, close, closedir, execve, exit, fflush, fork, free, getcwd, getline, getpid, isatty, kill, malloc, open, opendir, perror, read, readdir, signal, stat(_xstat), lstat(_lxstat), fqstat(_fxstat), strtok, wait, waitpid, wait3, wait4, write.

## Flow of Program Execution
The step-by-step stages of the execution of the shell program written in this project include:
1. The main function is the entry point of the program. It takes two arguments: **ac** (argument count) and **av** (argument vector) which represent the command-line arguments passed to the program.

2. Several variables are declared, including **prompt** and **newline** which are character pointers initialized with specific strings, **ret_val** and **exec_retn** which are integers, and **ret** which is a pointer to an integer.

3. The value of **name** is assigned to **av[0]**, which is the name of the program itself, and the **cmdhistory** variable is set to 1.

4. The signal function is used to set up a signal handler for the SIGINT signal, which is generated when the user presses Ctrl+C. The **check_sig** function is specified as the signal handler.

5. The value of **ret** is set to 0 and the **_envcopy** function is called to create a copy of the environment variables. The result is assigned to the **environ** variable.

6. If the **environ** variable is NULL (indicating a failure to copy the environment variables), the program exits with a status code of -100.

7. If the **ac** argument is not equal to 1 (indicating that command-line arguments were provided), the program proceeds to execute the code inside this block.

8. Inside the block, the **run_commands** function is called with **av[1]** (the first command-line argument) and **ret** as arguments. The return value of **run_commands** is assigned to **ret_val**.

9. The **free_env** function is called to free the memory allocated for the environment variables.

10. The value pointed to by **ret** is returned as the program's exit status.

11. If the **ac** argument is equal to 1 and the standard input is not a terminal (checked using **isatty(STDIN_FILENO))**, the program proceeds to execute the code inside this block.

12. Inside the block, the **handle_args** function is called repeatedly with **ret** as an argument until the return value **(ret_val)** is either _EOF or EXIT.

13. The **free_env** function is called to free the memory allocated for the environment variables.

14. The value pointed to by **ret** is returned as the program's exit status.

15. If the conditions in the previous two blocks are not met, the program enters an infinite loop.

16. Inside the loop, the **write** function is used to display the contents of the prompt string to the **standard output**.

17. The **handle_args** function is called with ret as an argument, and the return value is assigned to **ret_val**.

18. If the value of **ret_val** is either _EOF or EXIT, the program checks which one occurred.

19. If **ret_val** is _EOF, the **newline** character is **written** to the standard output.

20. The **free_env** function is called to free the memory allocated for the environment variables.

21. The value pointed to by **ret** is used as the program's **exit status** and the program exits.

22. If **ret_val** is EXIT, the program follows the same steps as in the previous step **(step 20)**.

23. After the loop is exited, the **free_env** function is called to free the memory allocated for the environment variables.

24. The value pointed to by **ret** is returned as the program's exit status.

## Testing and Validation

The following presents the results of the simple shell test cases, confirming the expected functionality of the shell program:

**Invocation**

To invoke the simple shell, compile all .c files in the repository and run the resulting executable:

```
gcc *.c -o hsh
./hsh
```
The simple shell can be invoked both interactively and non-interactively. If the simple shell is invoked with standard input not connected to a terminal (non-interactively), it reads and executes received commands in order.

Example:
```
:) echo "/bin/ls" | ./hsh
hsh main.c shell.h str_func1.c
:)
```

If the shell is invoked with standard input connected to a terminal, an interactive shell is opened. When executing interactively, the simple shell  displays the prompt :) when it is ready to read a command.

Example:

```
:) ./hsh
:)
```

**Environemt**


## Conclusion
