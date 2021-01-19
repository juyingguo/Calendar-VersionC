#ifndef _DATE_H_
#define _DATE_H_

#define MONTH 12
#define WEEK 7

int month[2][MONTH] = { { 31,28,31,30,31,30,31,31,30,31,30,31 },   //ƽ��ÿ���µ�����
							{ 31,29,31,30,31,30,31,31,30,31,30,31 } }; //����ÿ���µ�����
char *week[WEEK] = { "��","һ","��","��","��","��","��" };

typedef struct _date {
	int date[6][WEEK];
}Dates;

void SeekMonth(void);
void SeekYear(void);
void SeekDay(void);

void Seekyear(void);
void Seekday(void);
void Seekmonth(void);

void Produce(int w, Dates * Date, int datenmuber);
void PrintMonth(char*week[], Dates * Date, int month);
void Print(char*week[], Dates * Date1, Dates * Date2, Dates * Date3, int month);
int Calculation(int y, int c, int m);
void Judge(Dates * Date, int i);
void Month(int count, int *m);
int IsLeapYear(int y);

#endif