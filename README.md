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
  gcc -Wall -Werror -pedantic -std=gnu89 *.c -o shell
```

- **Execute:** Execute the shell program by typing: ./shell

Upon issuing the above command, you should notice a change in the command prompt by spotting the smiling emoji. You can interact with the shell as much as you want by issuing valid shell commands.

  **Exit:** When you are done and want to exit, type "exit" to exit the shell prompt or press the key combination: Ctrl + D.

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

### Invocation
To invoke the simple shell, compile all .c files in the repository and run the resulting executable:

```
gcc *.c -o shell
./shell
```
The simple shell can be invoked both interactively and non-interactively. If the simple shell is invoked with standard input not connected to a terminal (non-interactively), it reads and executes received commands in order.

Example:
```
$ echo "/bin/ls" | ./shell
hsh main.c shell.h str_func1.c
$
```

If the shell is invoked with standard input connected to a terminal, an interactive shell is opened. When executing interactively, the simple shell  displays the prompt :) when it is ready to read a command.

Example:

```
$ ./shell
:)
```

### Environment
The environment is an array of name-value strings describing variables in the format - NAME=VALUE. Upon invocation, the simple shell receives and copies the environment of the parent process in which it was executed. A few key environmental variables are:

**HOME**

The HOME environment variable refers to the directory path that serves as the home directory for a user in a Unix-like operating system. It represents the default location where user-specific files and directories are stored. Testing the HOME environment variable of the shell in non-interactive mode:

```
$ echo "echo $HOME" | ./shell
/root
```

**PWD**

The PWD environment variable stands for "Present Working Directory." It stores the absolute path of the current directory or folder in which a process or shell session is operating. Testing the PWD environment variable of the shell in interactive mode:

```
:) echo $OLDPWD
/home/vagrant/ALX
```

**PATH**

This is a colon-separated list of directories in which the shell looks for commands. 

```
$ echo "echo $PATH" | ./shell
/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin
```

### Command Execution
Once a command is received, the simple shell tokenizes it by splitting it into individual words using a space (" ") as a delimiter. The first word is identified as the command itself, while the remaining words are recognized as arguments for that specific command. Subsequently, the simple shell proceeds with the subsequent actions outlined below:

- If the command's first character is neither a slash (/) nor a dot (.), the simple shell initiates a search for it within the list of shell builtins. If a shell built-in with a matching name is found, it is invoked and executed.
- If the first character of the command is not a slash (/), dot (.), or a shell built-in, the simple shell proceeds to search each directory specified in the PATH environment variable. The purpose of this search is to locate a directory containing an executable file with a matching name.
- If the first character of the command is a slash (/) or a dot (.) or if any of the previous searches are successful, the simple shell proceeds to execute the named program. Any remaining arguments provided are included in the execution process within a separate execution environment.

### Exit Status
The simple shell returns the exit status of the last command executed, where a value of zero signifies success and a non-zero value indicates failure.

If a command is not found, the return status is 127; if a command is found but is not executable, the exit status is set to 126.

For built-in commands, a return status of zero indicates success, while a value of one or two indicates incorrect usage, accompanied by an appropriate error message.

### Signals
When operating in interactive mode, the simple shell prints a new prompt upon the signal - Ctrl+C from keyboard input. However, if the input of end-of-file (Ctrl+D) is detected, the program will be terminated and exited.

Below, the user presses Ctrl+C twice and hits Ctrl+D in the third line.

```
$ ./shell
:) ^C
:) ^C
$
```

### Variable Replacement
This feature allows the substitution of the value of a variable within a string or command. The simple shell interprets the character "$" for variable replacement.

Example:

```
$ echo "echo $PWD" | ./shell
/root/simple_shell
```

**$?**

The character "?" is substituted with the return value of the last program executed.

Example:

```
$ echo "echo $?" | ./shell
0
```

### Comments
The shell ignores all words and characters preceded by a "#" character on a line.

```
$ echo "echo 'hello' #this will be ignored!" | ./shell 'hello'
```

### Operators
The simple shell interprets the following operator characters:

**Command Separator (;)**

Sequential execution takes place in the simple shell when commands are separated by a semicolon (;).

Example:
```
:) echo Hello ; echo World ; echo !
Hello
World
!
:)
```
**Logical 'AND' Operator (&&)**

In the simple shell, when using the syntax "command1 && command2", command2 is executed only if command1 returns an exit status of zero.

Example:

Consider the scenario where you attempt to remove a non-existent file from your directory using the **'rm'** command. Additionally, you want to display the message "File removed successfully" on the screen using the **'echo'** command. In this case: **rm** is referred to as **command1**. **echo** "File removed successfully" is referred to as **command2**. However, since the file you are trying to remove does not exist, the **rm** command fails to execute and does not return an exit status of **zero** to indicate **success**. Consequently, **command2** (the echo command) will not be executed. 

**Here's a demonstration:**

```
:) ls
main.c shell.h
:) rm strings.c && echo "File removed successfully"
rm: cannot remove 'strings.c': No such file or directory
```
Due to the non-existent file (strings.c), the **rm** command will fail, and the subsequent echo command will not be executed. As a result, you will not see the "File removed successfully" message displayed on the screen.


**Logical 'OR' Operator (||)**

Given: command1 || command2; command2 is executed even if command1 returns a non-zero exit status.

**Here's a demonstration:**

```
:) ls
main.c shell.h
:) rm strings.c || echo "File removed successfully"
rm: cannot remove 'strings.c': No such file or directory
"File removed successfully"
```

The logical operators **&&** and **||** have equal precedence, followed by **;**.

### Simple Shell Buitin Commands

**cd**
- **Usage:** `cd DIRECTORY`
- **Description:** Changes the current directory of the process to the specified `DIRECTORY`.
- If no argument is provided, the command is interpreted as `cd $HOME`, which navigates to the user's home directory. 
- If the argument `-` is provided, the command is interpreted as `cd $OLDPWD`, and the pathname of the new working directory is displayed on the standard output. 
- If the argument `--` is given, the command is interpreted as `cd $OLDPWD`, but the pathname of the new working directory is not displayed. 
- After a directory change, the environment variables `PWD` and `OLDPWD` are updated accordingly.

**Here's a demonstration:**

```
$ ./shell
:) pwd
/root/simple_shell
:) cd
:) pwd
/root
:) cd -
:) pwd
/root/simple_shell
```
**exit**
- **Usage:** `exit [STATUS]`
- **Description:** Exits the shell. 
- The `STATUS` argument is an integer that determines the exit status of the shell. When `exit` is called with a specific `STATUS`, the shell terminates with that exit status. 
- If no `STATUS` argument is provided, the command is interpreted as `exit 0`, which means the shell exits with a successful status (0 indicating success).

**Here's a demonstration:**

```
$ ./shell
:) exit
$
```
**env**
- **Usage:** `env`
- **Description:** Prints the current environment.
- The `env` command is used to display the current environment variables and their values. When executed without any arguments, it retrieves and prints the complete set of environment variables currently in effect.
- The output typically includes information such as system-specific variables, user-specific variables, and variables set by the shell or the user's login scripts.

**Here's a demonstration:**

```
$ ./shell
:) env
HOSTNAME=3a7be2967852
LANGUAGE=en_US:en
PWD=/root/simple_shellTZ=America/Los_Angeles
HOME=/rootLANG=en_US.UTF-8
...
```
**setenv**
- Usage: `setenv [VARIABLE] [VALUE]`
- Description: Initializes a new environment variable or modifies an existing one.
- The `setenv` command is used to set or modify environment variables. 
- It takes two arguments: `[VARIABLE]` represents the name of the variable, and `[VALUE]` represents the desired value to assign to the variable. 
- If the variable does not exist, `setenv` creates a new environment variable with the specified name and assigns it the provided value. 
- If the variable already exists, `setenv` modifies its value to the provided value.
- In case of failure, such as when encountering a permission issue or other errors, `setenv` outputs an appropriate error message to the standard error `(stderr)` stream.

**Here's a demonstration:**

```
$ ./shell
:) setenv NAME Eva
:) echo $NAME
Eva
```
**unsetenv**
- **Usage:** `unsetenv [VARIABLE]`
- Description: Removes an environment variable.
- The `unsetenv` command is used to remove an environment variable. It takes one argument: `[VARIABLE]`, which represents the name of the variable to be removed. 
- When executed,` unsetenv` removes the specified environment variable from the current environment. 
- If the variable does not exist, no action is taken. 
- In case of failure, such as encountering a permission issue or other errors, `unsetenv` outputs an appropriate error message to the standard error `(stderr)` stream.

**Here's a demonstration:**

```
$ ./shell
:) setenv NAME Eva
:) Unsetenv NAME
:) echo $NAME

$
```

## Conclusion

In conclusion, we successfully developed a simple Unix-like command line interpreter, commonly referred to as a simple shell. It provides users with a text-based interface to execute commands, manage files and processes, and perform various operations. Throughout the project, we gained practical experience in systems programming and learned about system calls, process management, and file handling. While this shell is basic compared to more advanced versions, it serves as a solid foundation for future enhancements such as additional commands and scripting capabilities. Overall, this project allowed us to build a tool that enables efficient system interaction and command execution from the command line.

## Authors
- [Akoma Goodness James](https://github.com/GoodnessJames)
- [Nna Ginika Elizabeth](https://github.com/Giniks)
  
## Acknowledgements
This project was written as part of the curriculum for ALX School as a requirement to achieve a milestone and commence the second sprint in software engineering.
ALX is an innovative learning community and leadership development program that offers free, high-quality education in various fields such as software engineering, data science, and entrepreneurship. For more information, visit the link: https://www.alxafrica.com/
