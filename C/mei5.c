/*
 * 相似
 * Author: zhiying
 * Date: 2020.5.19
 * 
 * 两个数是相似的，当且仅当他们位与起来不为0。例如，3和5是相似的，因为3的二进制为001,5的二进制为101,  * 他们位与起来为001不为0。
 * 
 * 输入:
 *     4
 *     3 5 6 1
 * 输出:
 *     -1 -1 1 1
 */

#include <stdio.h>
#include <stdlib.h>

int Dec2Bin(int n,int *bin);
int isnotsimilar(int *a,int len1,int *b,int len2);
void find_not_similar(int *a,int *b,int len);

int main(){
	int n;
	scanf("%d",&n);
	int a[n];
    int result[n]; 
	for (int i=0;i<n;i++){
	
		scanf("%d",&a[i]);
	}
    
	find_not_similar(a,result,n);

	for (int j=0;j<n;j++){
	
		printf("%d",result[j]);
		
	    if (j != (n-1)){
		
			printf(" ");
		}else{
		
			printf("\n");
		}
	}
	
	return 0;
}

// 十进制数转化成二进制
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

int isnotsimilar(int *a,int len1,int *b,int len2){

	int max_len = len1>len2 ? len1:len2;
    int cnt =0;

	for (int i=0;i<max_len;i++){
		if (!((*(a+i)) & (*(b+i)))){
		
			cnt++;
		}
	}

	if (cnt == max_len){
	
		return 1;
	}else{
	
		return 0;
	}
}

void find_not_similar(int *a,int *b,int len){

	for (int i=0;i<len;i++){
	    int a1[15]={0};    // 一定要初始化
		int len1 = Dec2Bin(*(a+i),a1);

		int tmp[len-1];
		int index =0;
		for (int j=i+1;j<len;j++){
		
			tmp[index] = j;
			index++;
		}

		for (int j=i-1;j>=0;j--){
		
			tmp[index] = j;
			index++;
		}
        
		*(b+i) = -1;

		for (int j=0;j<len-1;j++){
		
			int a2[15]={0};
			int len2 = Dec2Bin(*(a+tmp[j]),a2);

			if (isnotsimilar(a1,len1,a2,len2)){
			
				*(b+i) = 1;
				break;
			}
		}

	}
}
