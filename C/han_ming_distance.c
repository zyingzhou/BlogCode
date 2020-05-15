/* 最大汉明距离
 * Author: zhiying
 * Date: 2020.5.15
 * Description: 输入n(1<=n<=100)个数，计算两两之间的最大汉明距离
 * Case: 
 *      input:3
 *            1 2 3
 *      output:2 
 */

#include <stdio.h>
#include <stdlib.h>

int cal_han_distance(int a1,int a2);
int Dec2Bin(int n,int *bin);


int main(){

	int n;
	scanf("%d",&n);
	int *nums = (int *)malloc(sizeof(int)*n);
	int *free_nums = nums;
	int max_distance = 0;

	for (int i=0;i<n;i++){

		scanf("%d",nums+i);
	}

	for (int i =0;i<n-1;i++){
	    
		for (int j = i+1;j<n;j++){

			int han_ming_distance = cal_han_distance(*(nums+i),*(nums+j));
			max_distance = max_distance > han_ming_distance ? max_distance : han_ming_distance;
		}
	}
	
	printf("%d\n",max_distance);
	free(free_nums);

	return 0;
}


int cal_han_distance(int a1,int a2){
	int *b1 = (int*)malloc(sizeof(int)*15);
	int *free_b1 = b1;
    int *b2 = (int *)malloc(sizeof(int)*15);
	int *free_b2 = b2;
	int n1 = Dec2Bin(a1,b1);
	int n2 = Dec2Bin(a2,b2);
    int distance = 0;
	int max_n = n1 > n2 ? n1 : n2;

	for (int i=0;i<max_n;i++){
	
		if(*(b1+i) != *(b2+i)){
			distance++;
		}
	}

	free(free_b1);
	free(free_b2);
	return distance;
}


// 十进制数转化成二进制,低位在前高位在后
int Dec2Bin(int n,int *bin){

	int len=1;
    int *b = bin;

	while (n != 0){

		*b = n%2;
		n /= 2;
		b++;
		len++;
	}
	*b = n;
    
	return len;
}

