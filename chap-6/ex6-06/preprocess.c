#include <stdio.h>
#include <ctype.h>
#include "string.h"
#include "table_lookup.h"
#include "char.h"

#define OUT	0
#define IN	1


/* preprocess: pre process the #define directive 
 * no error checking handled, just simple version */
void
preprocess(void){
	
	int c, isword;
	char name[20], defn[20],  *p;
	char word[20], *wp;
	
	wp=word;
	isword=0;
	while ((c=getch()) != EOF){
		if (c == '#'){	/* preprocessor */
			putchar(c);
			p = name;
			while (!isspace(c=getch()))
				*p++ = c;
			*p = '\0';
			printf("%s", name);
			putchar(c);
			if (str_cmp(name, "define") == 0){
				p=name;
				while ((c=getch()) == ' ' || c == '\t')
					putchar(c);
				ungetch(c);
				while (!isspace(c=getch()))
					*p++ = c;
				*p='\0';
				printf("%s", name);
				putchar(c);
				while ((c=getch()) == ' ' || c == '\t')
					putchar(c);
				ungetch(c);
				p = defn;
				while (!isspace(c=getch()))
					*p++ = c;
				*p = '\0';
				printf("%s", defn);
				putchar(c);
				install(name, defn);
			}
		}else if (c == '/'){ /* comment starts */
			c = getch();
			if (c != '*')
				break;
			int prev;
			while ((c=getch()) != EOF){
				if (c == EOF)
					return;
				if (prev == '*' && c == '/')
					break;
				prev=c;
			}
		}else {
			if (isalpha(c)){
				*wp++ = c;
				if (!isword)
					isword=1;
			}else{
				if (isword){
					struct nlist *np;

					isword=0;
					*wp = '\0';
					wp = word;
					np = lookup(word);
					if (np != NULL)
						printf("%s", np->defn);
					else
						printf("%s", word);
					putchar(c);
				}else {
						putchar(c);
				}
			}
		}
	}

}
