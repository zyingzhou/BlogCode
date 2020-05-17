/* 单科优秀奖
 * Date: 2020.5.17
 * gcc Main.c -o Main -O2 -fno-asm -Wall -lm -static
 * 
 * 某学校的期末考试共有n个学生参加，考试科目共有m科，学校将会给一部分学生颁发单科成绩优秀奖，获奖学生 * 需要满足的条件是某一科的成绩是所有学生中最高的或是最高的之一。请问学校应该给多少名学生颁发单科成绩 * 优秀奖？
 * 
 * 输入第一行包含两个正整数n和m，分别代表学生人数和考试科目数量。
 * (n,m <= 500)
 * 接下来有n行，每行有m个正整数，每个正整数在1-100之间，中间用空格隔开，
 * 表示每个学生的m科考试成绩 
 * 
 * 输入:
 * 5 5
 * 28 35 38 10 19
 * 4 76 72 38 86
 * 96 80 81 17 10
 * 70 64 86 85 10
 * 1 93 19 34 41
 *
 * 输出:
 * 4
 */

#include <stdio.h>
#include <stdlib.h>

int main(){

	int n,m;
	
	scanf("%d %d",&n,&m);
	int *p[n];
	int a[m];    // 每科最高成绩
	int cnt=0;
    
	for (int i=0;i<n;i++){
		p[i] = (int *)malloc(sizeof(int)*m);

		for (int j=0;j<m;j++){
		
			scanf("%d",p[i]+j);
			// p[i]++;
		}
		
	}
    
	// 查找每科最高成绩
	for (int i=0;i<m;i++){
		int max = *(p[0]+i);
		for (int j=1;j<n;j++){
			if (*(p[j]+i)>max){
			    max = *(p[j]+i);
			}

		}
		a[i] = max;
	}
    
	// 比较
	for (int i=0;i<n;i++){
	
		for (int j=0;j<m;j++){
		
			if (*(p[i]+j) == a[j]){
			
				cnt++;
				break;
			}
		}
		//free(p[i]);
	}

	printf("%d\n",cnt);
	free(p);
	return 0;
}
