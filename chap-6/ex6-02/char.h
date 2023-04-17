#ifndef CHAR_H
#define CHAR_H

#define BUFSIZE	100

int getch(void);
void ungetch(int);
void ungets(char *s);

#endif
