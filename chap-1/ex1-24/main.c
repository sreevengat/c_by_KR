/*
	page-34
	EX1-24. Write a program to check a
	C program for rudimentary syntax 
	errors like unbalanced paranthesis, 
	brackets and braces. Dont forget about
	quotes, both single and double, escape
	sequences , and comments .(This program
	is hard if you do it in full generality)

*/

/*
	para = ()
	brackets = []
	braces = {}

*/

#include <stdio.h>

#define MAXLINE 1000

int get_line(void);

char line[MAXLINE];

int 
main(void){
	
	int c, para, bracket, braces;
	int squotes, dquotes;
	int esc_err,prev;
	int loop;
	int is_cmt ;

	para=bracket=braces=0;
	squotes=dquotes=0;
	esc_err=0;
	is_cmt=0;
	loop=1;
	while (loop==1 && (c=getchar()) != EOF){
		if (c == '('){
			if (is_cmt==0)
				++para;
		}else if (c == ')'){
			if (is_cmt==0)
				--para;
		}else if (c == '['){
			if (is_cmt==0)
				++bracket;
		}else if (c == ']'){
			if (is_cmt==0)
				--bracket;
		}else if (c == '{'){
			if (is_cmt==0)
				++braces;
		}else if (c == '}'){
			if (is_cmt==0)
				--braces;
		}else if (c == '\''){
			if (is_cmt==0){
				if (squotes == 0)
					++squotes;
				else
					--squotes;
			}
		}else if (c == '"'){
			if (is_cmt==0){
				if (dquotes == 0)
					++dquotes;
				else
					--dquotes;
			}
		}else if (c == '\\'){
			c = getchar();
			if (c == EOF)
				loop=0;
			if (is_cmt==0){
				if (c == ' ' || c == '\t' || c == '\n')
					esc_err=1;
			}
		}else if (squotes == 0 && dquotes == 0 
					&& c == '/' && is_cmt==0){
			is_cmt=1; 	
			c = getchar();
			if (c == '*')
				is_cmt=2;
			else if (c == EOF)
				loop=0;
		}else if (c == '/' && is_cmt == 2){
			if (prev == '*')
				is_cmt=0;
		}
		prev = c;
	}
	
	if (para != 0)
		printf("error: paranthesis\n");
	if (bracket != 0)
		printf("error: bracket\n");
	if (braces != 0)
		printf("error: braces\n");
	if (squotes != 0)
		printf("error: single quotes\n");	
	if (dquotes != 0)
		printf("error: double quotes\n");
	if (esc_err != 0)
		printf("error: escape_sequence\n");
	if (is_cmt != 0)
		printf("error: comments\n");
	return 0;
}


