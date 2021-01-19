/*****************************************************************************
Copyright: 2018-2019
File name: calendar
Description: �˳����ļ�����Ҫʵ��������ѯ��������ѯ��������ѯ���ܣ�calendar.hͷ�ļ�����Ҫ�����˽ṹ��������ȫ�ֱ�������������ԭ������
Author: ���� ������ ����  �ƿ�ϲ л־��
Version: 1.0
Date: 2019.1.6
History: 2019.1.5�ɵ����޸ģ� ��ԭ��������ѯ�����ϣ�������������ѯ��������ѯ���ܣ�������˽���
*****************************************************************************/
#include<stdio.h>
#include<stdlib.h>
#include"Calendar.h"

int main()
{
	int n = 1;
	system("mode con cols=35 lines=25");                                //���ô��ڴ�С
	system("color 5f");
	while (n)
	{
		printf("\n");
		printf(" �X�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�[\n");
		printf(" �U----------- ������ -----------�U\n");
		printf(" �U------------------------------�U\n");
		printf(" �U-����ߣ����� ������--------�U\n");
		printf(" �U----------����  �ƿ�ϲ--------�U\n");
		printf(" �U-----------л־��-------------�U\n");
		printf(" �U------------------------------�U\n");
		printf(" �U------------------------------�U\n");
		printf(" �U-----------������ѯ----------1�U\n");
		printf(" �U-----------������ѯ----------2�U\n");
		printf(" �U-----------������ѯ----------3�U\n");
		printf(" �U---------- ��0�˳�! ---------0�U\n");
		printf(" �U------------------------------�U\n");
		printf(" �^�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�a\n\n");
		printf("��ѡ���ܼ���");
		scanf_s("%d", &n);
		if (n > 3 || n < 0) {
			printf("  �������\n");
		}
		else {
			switch (n)
			{
			case 0: printf("\n ����������\n");
				n = 0;
				break;
			case 1: SeekYear();
				break;
			case 2: SeekMonth();
				break;
			case 3: SeekDay();
				break;
			}
		}
		system("CLS");
	}
	return 0;
}


void SeekYear(void)
{
	int n = 1;
	while (n)
	{
		system("CLS");
		system("mode con cols=35 lines=25");                                //���ô��ڴ�С
		system("color 5f");
		printf(" �X�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�[\n");
		printf(" �U-----------������-------------�U\n");
		printf(" �U------------------------------�U\n");
		printf(" �U-����ߣ����� ������--------�U\n");
		printf(" �U----------����  �ƿ�ϲ--------�U\n");
		printf(" �U-----------л־��-------------�U\n");
		printf(" �U------------------------------�U\n");
		printf(" �U------------------------------�U\n");
		printf(" �U-----��ӭʹ��������ѯϵͳ-----�U\n");
		printf(" �U-----�ɹ���ѯ������ ----------�U\n");
		printf(" �U-----1582�ꡪ��9999��---------�U\n");
		printf(" �U--------- ��1��ѯ��-----------�U\n");
		printf(" �U--------- ��0�˳�! -----------�U\n");
		printf(" �^�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�a\n\n");
		printf("��ѡ���ܼ���");
		scanf_s("%d", &n);

		if (n > 1 || n < 0) {
			printf("�������");
		}
		else {
			switch (n)
			{
			case 0: printf("\n ����������\n");
				n = 0;
				break;
			case 1: Seekyear();
				break;
			}
		}
	}
}

void Seekyear(void)
{
	int y = 0, c = 0, m = 0;  //w ���ڣ� y �꣬ c �� - 1��m ��
	int w1, w2, w3;
	int result = 0, year;

	printf("������Ҫ��ѯ����ݣ�");
	scanf_s("%d", &y);

	year = y;
	result = IsLeapYear(y);

	c = y / 100;//������ǰ��λ
	y = y % 100;//�����ĺ���λ

	int i, count = 0;

	system("CLS");
	system("mode con cols=85 lines=40");
	printf("\n\t ===========================%d��Calendar===========================\n\n", year);

	/*�� 3 x 4 �ĸ�ʽ��ӡ����*/
	for (i = 0; i < 4; i++)
	{
		Dates Date1 = { 0 }, Date2 = { 0 }, Date3 = { 0 };//Date1��Date2, Date3��ź���ÿ���µ�����

		Month(count, &m);
		w1 = Calculation((count < 2 ? y - 1 : y), c, m);
		Produce(w1, &Date1, month[result][count++]);

		Month(count, &m);
		w2 = Calculation((count < 2 ? y - 1 : y), c, m);
		Produce(w2, &Date2, month[result][count++]);

		Month(count, &m);
		w3 = Calculation((count < 2 ? y - 1 : y), c, m);
		Produce(w3, &Date3, month[result][count++]);

		Print(week, &Date1, &Date2, &Date3, count - 2);
	}
	system("pause");
}

void SeekMonth(void)
{
	int n = 1;
	while (n)
	{
		system("CLS");
		printf(" �X�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�[\n");
		printf(" �U-----------������-------------�U\n");
		printf(" �U------------------------------�U\n");
		printf(" �U-����ߣ����� ������--------�U\n");
		printf(" �U----------����  �ƿ�ϲ--------�U\n");
		printf(" �U-----------л־�� ------------�U\n");
		printf(" �U------------------------------�U\n");
		printf(" �U------------------------------�U\n");
		printf(" �U------��ӭʹ��������ѯϵͳ----�U\n");
		printf(" �U------�ɹ���ѯ������----------�U\n");
		printf(" �U------1�¡���12��-------------�U\n");
		printf(" �U---------- ��1��ѯ! ----------�U\n");
		printf(" �U---------- ��0�˳�! ----------�U\n");
		printf(" �^�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�a\n\n");
		printf("��ѡ���ܼ���");
		scanf_s("%d", &n);
		if (n > 1 || n < 0) {
			printf("�������");
		}
		else {
			switch (n)
			{
			case 0: printf("\n ����������\n");
				n = 0;
				break;
			case 1: Seekmonth();
				break;
			}
		}
	}
}

void Seekmonth(void)
{
	int y = 0, c = 0, m = 0;  //w ���ڣ� y �꣬ c �� - 1��m ��
	int w1;
	int result = 0, year;
	int count = 0;

	printf("������Ҫ��ѯ����ݺ��·ݣ�(��ʽ�磺2019 2)\n");
	scanf_s("%d %d", &y, &count);

	year = y;
	result = IsLeapYear(y);

	c = y / 100;//������ǰ��λ
	y = y % 100;//�����ĺ���λ

	Dates Date = { 0 };//Date1��Date2, Date3��ź���ÿ���µ�����

	Month(count, &m);
	w1 = Calculation((count < 2 ? y - 1 : y), c, m);
	Produce(w1, &Date, month[result][count - 1]);

	system("CLS");
	printf("\n\n--------------%d ��--------------\n", year);
	PrintMonth(week, &Date, count);
	printf("\n");
	system("pause");
}

void SeekDay(void)
{
	int n = 1;
	while (n)
	{
		system("CLS");
		printf(" �X�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�[\n");
		printf(" �U-----------������-------------�U\n");
		printf(" �U------------------------------�U\n");
		printf(" �U-����ߣ����� ������--------�U\n");
		printf(" �U----------����  �ƿ�ϲ--------�U\n");
		printf(" �U-----------л־�� ------------�U\n");
		printf(" �U------------------------------�U\n");
		printf(" �U------------------------------�U\n");
		printf(" �U------��ӭʹ��������ѯϵͳ----�U\n");
		printf(" �U------�ɹ���ѯ������----------�U\n");
		printf(" �U------1�ա���28/29/30/31��----�U\n");
		printf(" �U----------��1��ѯ! -----------�U\n");
		printf(" �U----------��0�˳�!------------�U\n");
		printf(" �^�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�a\n\n");
		printf("��ѡ���ܼ���");
		scanf_s("%d", &n);
		if (n > 1 || n < 0) {
			printf("�������");
		}
		else {
			switch (n)
			{
			case 0: printf("\n ����������\n");
				n = 0;
				break;
			case 1: Seekday();
				break;
			}
		}
	}
}

void Seekday(void)
{
	int y = 0, c = 0, m = 0, d = 0;  //w ���ڣ� y �꣬ c �� - 1��m ��
	int w1;
	int result = 0, year;
	int count = 0;

	printf("������Ҫ��ѯ����ݺ��·��Լ��գ�(��ʽ�磺2019 2 1)\n");
	scanf_s("%d %d %d", &y, &count, &d);

	year = y;
	result = IsLeapYear(y);

	c = y / 100;//������ǰ��λ
	y = y % 100;//�����ĺ���λ

	Month(count, &m);
	y = count < 2 ? y - 1 : y;

	w1 = y + (y / 4) + (c / 4) - 2 * c + (26 * (m + 1) / 10) + d - 1;
	if (w1 < 0) {
		w1 = w1 - (w1 / 7 - 1) * 7;
	}
	else {
		w1 = w1 % 7;
	}
	printf("\n");
	printf("%d��%d��%d�գ�", year, count, d);
	switch (w1)
	{
	case 0: printf("������"); break;
	case 1: printf("����һ"); break;
	case 2: printf("���ڶ�"); break;
	case 3: printf("������"); break;
	case 4: printf("������"); break;
	case 5: printf("������"); break;
	case 6: printf("������"); break;
	}
	printf("\n");
	system("pause");
}


/*���ܣ��ж��ǲ�������
  ������y ��
  ����ֵ��0 ƽ�꣬ 1 ����*/
int IsLeapYear(int y)
{
	int flag = 0;
	if ((y % 4 == 0 && y % 100 != 0) || y % 400 == 0) {
		flag = 1;
	}
	return flag;
}

void Month(int count, int *m)
{
	if (count < 2) {
		*m = count + 13;
	}
	else {
		*m = count + 1;
	}
}

/*���ܣ�����ĳ��ĳ��ĳ�������ڼ�
  ������y �꣨����λ��   c ���� - 1   m ��
  ����ֵ�� w ����*/
int Calculation(int y, int c, int m)
{
	int d = 1;
	int w;
	w = y + (y / 4) + (c / 4) - 2 * c + (26 * (m + 1) / 10) + d - 1;
	if (w < 0) {
		w = w - (w / 7 - 1) * 7;
	}
	else {
		w = w % 7;
	}
	return w;
}

/*���ܣ�����1���������ڣ���������µ�����,����������
  ������ w 1���������� datenmuber һ���µ�����*/
void Produce(int w, Dates * Date, int datenmuber)
{
	int d = 1;
	int i;
	for (i = 0; i < 6; i++)
	{
		int j;
		for (j = 0; j < 7; j++)
		{
			if ((i == 0 && j >= w) || (i > 0 && j >= 0)) {
				Date->date[i][j] = d;
				d++;
			}
			if (Date->date[i][j] >= datenmuber) {
				break;
			}
		}
		if (Date->date[i][j] >= datenmuber) {
			break;
		}
	}
}

void Print(char*week[], Dates * Date1, Dates * Date2, Dates * Date3, int month)
{
	/*��ӡ�¡�1�¡�����2�¡�......*/
	printf("\t");
	int i;
	for (i = 0; i < 3; i++)
	{
		printf(" %d��                 \t", month++);
	}
	printf("\n");

	/*��ӡ���� "��","һ","��","��","��","��","��"*/
	printf("\t");
	for (i = 0; i < 3; i++)
	{

		int j;
		for (j = 0; j < 7; j++)
		{
			printf(" %s", week[j]);
		}
		printf("\t");
	}
	printf("\n");

	/* ��ӡ��
		  1  2  3  4  5  6  7              1  2  3  4                       1
		  8  9 10 11 12 13 14     5  6  7  8  9 10 11     2  3  4  5  6  7  8
		 15 16 17 18 19 20 21    12 13 14 15 16 17 18     9 10 11 12 13 14 15
		 22 23 24 25 26 27 28    19 20 21 22 23 24 25    16 17 18 19 20 21 22
		 29 30 31                26 27 28 29 30 31       23 24 25 26 27 28 29
														 30*/
	for (i = 0; i < 6; i++)
	{
		printf("\t");

		Judge(Date1, i);
		Judge(Date2, i);
		Judge(Date3, i);
		printf("\n");
	}
}

void PrintMonth(char*week[], Dates * Date, int month)
{
	printf("\n\n");
	int i;
	printf("     ");
	printf("  %d��\n", month);

	printf("      ");
	for (i = 0; i < 7; i++)
	{
		printf(" %s", week[i]);
	}
	printf("\n");

	for (i = 0; i < 6; i++)
	{
		printf("      ");
		Judge(Date, i);
		printf("\n");
	}
}

void Judge(Dates * Date, int i)
{
	int j;
	for (j = 0; j < WEEK; j++)
	{
		if (Date->date[i][j] == 0) {
			printf("   ");
		}
		else {
			printf("%3d", Date->date[i][j]);
		}
	}
	printf("\t");
}
