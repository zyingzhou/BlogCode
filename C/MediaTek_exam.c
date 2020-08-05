/*
联发科技2021校招提前批-软件-0805北京 Android/Linux开发工程师
2020.8.5 19:00-20:30

统计字符串中出现次数最多的字符

Author: zhiying
Date: 2020.8.5 21:21

*/
#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void count_char(char* str, char* ch, int* num);
void print(char ch, int num);

int main() {
	char* str = (char*)malloc(sizeof(char) * 1001);
	char ch;
	int num = 0;
	scanf("%s", str);
	count_char(str, &ch, &num);
	print(ch, num);
	free(str);
	return 0;
}

void count_char(char* str, char* ch, int* num) {
	char* tmp = str;

	char ch_max=*tmp;
	int max_cnt=0;

	while (*tmp != '\0') {

		if (*tmp == ',') {
			tmp++;
			continue;
		}
		int count = 0;
		char* t = tmp;

		while (*t++ != '\0') {

			if (*t == ',') {
				continue;
			}

			if (*tmp == *t && *t != ',') {
				count++;
				*t = ',';
			}
		}

		if (max_cnt < count) {
			if (*tmp >= 'A' && *tmp <= 'Z' || *tmp >= 'a' && *tmp <= 'z') {
				ch_max = *tmp;
				max_cnt = count;
			}
			
		}
		tmp++;
	}
	*ch = ch_max;
	*num = max_cnt;

}

void print(char ch, int num) {
	printf("result is %c,%d\n", ch, num);
}