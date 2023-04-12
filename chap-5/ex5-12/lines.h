#ifndef LINE_H
#define LINE_H

int get_line(char *s, int maxline);
int read_lines(char *lineptr[], int maxline, char *linebuf, int bufsize);
void write_lines(char *lineptr[], int maxlines);

#endif
