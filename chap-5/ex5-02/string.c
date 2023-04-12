/* reverse: reverse a string using recurrsion */

void
reverse(char s[]){
	
	static int i, j;

	if (s[j] != '\0' && s[j] != '\n'){
		j++;
		reverse(s);
	}
	if (i < j){
		int c;
		c = s[i];
		s[i++] = s[--j];
		s[j] = c;
	}else 
		i=j=0;
}
