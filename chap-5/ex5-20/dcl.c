#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "dcl.h"
#include "string.h"
#include "char.h"

enum {NAME, PARENS, BRACKETS};

static int error;				/* signal that error occured */
static int tokentype;			/* type of last token */
static char token[MAXTOKEN];	/* last token string */
static char name[MAXTOKEN];	/* identifier name */
static char datatype[MAXTOKEN]; /* data type = char, int, etc. */
static char out[1000];			/* output string */

static void dcl(void);
static void dirdcl(void);
static int gettoken(void);

static char *qualifiers[] = {
		"register",
		"const",
		"static",
		"\0",
};
/* convert declaration to words */ 
void
parse_dcl(void){
	
	int i;
	
	while (gettoken() != EOF){	/* 1st token on lines */
		str_cat(datatype, token);	/* is the datatype or qualifier */
		for (i=0; qualifiers[i][0] != '\0'; i++)
			if (str_cmp(qualifiers[i], token) == 0)
				break;
		if (qualifiers[i][0] != '\0'){
			str_cat(datatype, " ");
			continue;
		}
		out[0] = '\0';
		name[0] = '\0';
		dcl();						/* parse reset of line */
		if (tokentype != '\n' && tokentype != '('){
			error=1;
			printf("syntax error\n");
		}
		if (!error){
			if (tokentype == '('){
				char *p = out;
				int c;		
				str_cat(out, " function returning ");
				printf("%s: %s %s, ", name, out, datatype);	
				while ((c=getch()) != ')')
					*p++ = c;
				*p = '\0';
				if (c != ')')
					ungetch(c);
				str_rev(out);
				ungets(out);
				printf("taking argument of ");
			}
			else printf("%s: %s %s\n", name, out, datatype);
		
		}else {
			error=0;
			if (getch() == EOF)
				break;
		}
		datatype[0]='\0';
	}

}

/* dcl: parse a declarator */
static 
void
dcl(void){
	
	int ns;

	for (ns=0; gettoken() == '*';)	/* count *s's */
		ns++;
	dirdcl();
	while (ns-- > 0)
		str_cat(out, " pointer to");
}

/* dirdcl: parse a direct declarator */
static 
void
dirdcl(void){
	
	int type;

	if (tokentype == '('){		/* (dcl) */	
		dcl();	
		if (tokentype != ')'){
			error=1;
			printf("error: missing ) \n");
			return;
		}
	}else if (tokentype == NAME){	/* variable name */
		str_cpy(name, token);
	}else{
		error=1;
		printf("error: expected name or (dcl)\n");
		return ;
	}
	while ((type=gettoken()) == PARENS || type == BRACKETS)
		if (type == PARENS){
			str_cat(out, " function returning");
		}else {
			str_cat(out, " array");
			str_cat(out, token);
			str_cat(out, " of ");
		}
}

/* get_token: return next token */
static
int
gettoken(void){
	
	int c;
	char *p = token;

	while ((c=getch()) == ' ' || c == '\t')
		;
	if (c == '('){
		if ((c=getch()) == ')'){
			str_cpy(token, "()");
			return tokentype = PARENS;
		}else {
			ungetch(c);
			return tokentype = '(';
		}
	}else if (c == '['){
		for (*p++ = c; (*p++ = getch()) != ']';)
			;
		*p='\0';
		return tokentype = BRACKETS;
	}else if (isalpha(c)){
		for (*p++ = c; isalnum (c=getch());)
			*p++ = c;
		*p='\0';
		ungetch(c);
		return tokentype = NAME;
	}
	return tokentype = c;
}

/* undcl: converts word description to declarartion */
void
word_dcl(void){
	
	int type;
	char temp[1000+MAXTOKEN];

	while (gettoken() != EOF){
		strcpy(out, token);
		while ((type = gettoken()) != '\n')
			if (type == PARENS || type == BRACKETS)
				strcat(out, token);
			else if (type == '*'){
				sprintf(temp, "*%s", out);
				str_cpy(out, temp);
			}else if (type == NAME){
				sprintf(temp, "%s %s", token, out);
				str_cpy(out, temp);
			}else 
				printf("invalid input at %s\n", token);
		printf("%s\n", out);
	}
}
