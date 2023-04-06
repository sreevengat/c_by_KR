void ungetch(int c);

void
ungets(char s[]){
	
	int i, c;

	i=0;
	while ((c=s[i++]) != '\0')
		ungetch(c);
}
