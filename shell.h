#ifndef SHELL_H
#define SHELL_H

void check_input(void);
void check_EOF(int len, char *buffer);
void check_sig(int sig);
char **splitstr(char *str, const char *delim);
#endif
