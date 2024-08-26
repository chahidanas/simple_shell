#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <limits.h>
#include <fcntl.h>
#include <errno.h>

/*read/write buffers */
#define READ_BUF_SIZE 1024
#define WRITE_BUF_SIZE 1024
#define BUF_FLUSH -1

/*strings.c*/
int _strlength(char *);
int _strcmp(char *, char *);
char *starts_with(const char *, const char *);
char *_strcat(char *, char *);

/* strings1.c */
char *_strcopy(char *, char *);
char *_dupstr(const char *);
void _puts(char *);
int _putchar(char);

/* cp_strings.c */
char *_strncpy(char *, char *, int);
char *_strncat(char *, char *, int);
char *_strchr(char *, char);

/*spl_string.c */
char **strtow(char *, char *);
char **strtow1(char *, char);

/* memo_func.c */
char *_memset(char *, char, unsigned int);
void free(char **);
void *_realloc(void *, unsigned int, unsigned int);

/* memo_func1.c */
int bfr(void **);

/* interactive.c */
int interact(info_t *);
int does_delime(char, char *);
int _doesalpha(int);
int _stoi(char *);

/* converterror.c */
int _convtoi(char *);
void print_error(info_t *, char *);
int print_d(int, int);
char *convert_number(long int, int, int);
void remove_comments(char *);













#endif
