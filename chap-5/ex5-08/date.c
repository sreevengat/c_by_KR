
/* multi dimensional array */
static char daytab[2][13] = {
	{0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
	{0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
};

/* day_of_year: set day of year from month & day */
int
day_of_year(int year, int month, int day){
	
	if (!year)
		return -1;
	else if (month <= 0  || month > 12)
		return -1;
	else if (day <= 0 || day > 31)
		return -1;

	int i, leap;

	leap = (year%4==0 && year%100 != 0) || year%400 == 0;
	if (month == 2)
		if (day > daytab[leap][2])
			return -1;	
	for (i=1; i < month; i++)
		day += daytab[leap][i];
	return day;
}

/* month_day: set month, day from day of year */
void
month_day(int year, int yearday, int *pmonth, int *pday){
	
	*pmonth = *pday = -1;
	if (!year)
		return ;
	else if (yearday <=0 && yearday > 366)
		return ;
	
	int i, leap;

	leap = (year%4==0 && year%100 != 0) || year%400 == 0;
	if (yearday == 366)
		if (!leap)
			return ;	
	for (i=1; yearday > daytab[leap][i]; i++)
		yearday -= daytab[leap][i];
	*pmonth = i;
	*pday = yearday;
}
