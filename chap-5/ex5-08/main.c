/*
	page-112
	EX5-8. There is no error checking
	in day_of_year or month_day.
	Remedy this effect.
*/


#include <stdio.h>
#include "date.h"
#include "lines.h"
#include "atof.h"

#define MAXLINE	50

int day_year(void);
int monthday(void);

int
main(void){
	
	while (1){
		if (day_year())
			break;
		if (monthday())
			break;
	}
	putchar('\n');
	return 0;
}
int
day_year(void){
	
	char line[MAXLINE];
	int year_day, month, day;
	
	printf("#####DAY_OF_THE_YEAR#####\n");
	printf("Enter the year : ");
	if (!(get_line(line, MAXLINE) > 0))
		return 1;
	year_day=atoi(line);
	
	printf("Enter the month: ");
	if (!(get_line(line, MAXLINE) > 0))
		return 1;
	month=atoi(line);
	
	printf("Enter the day  : ");
	if (!(get_line(line, MAXLINE) > 0))
		return 1;
	day=atoi(line);

	year_day = day_of_year(year_day, month, day);
	if (year_day <= 0)
		printf("error: not a valid date\n");
	else
		printf("day_of_year: %d\n", year_day);

	return 0;
}

int
monthday(void){
	
	char line[MAXLINE];
	int year_day, year,  month, day;
	
	printf("#####MONTH_DAY#####\n");
	printf("Enter the year    : ");
	if (!(get_line(line, MAXLINE) > 0))
		return 1;
	year=atoi(line);
	
	printf("Enter the year day: ");
	if (!(get_line(line, MAXLINE) > 0))
		return 1;
	year_day=atoi(line);
	
	month=day=0;
	month_day(year, year_day, &month, &day);
	if (month <= 0 || day <= 0)
		printf("error: not a valid date\n");
	else
		printf("month=%d, day=%d\n", month, day);

	return 0;
}
