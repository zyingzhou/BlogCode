/* 
 * 城市修建　360 2019年
 * Author: zhiying
 * Date: 2020.5.23
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct {

	long long X;
	long long Y;
}Point;

/*
int input(Point *pts){
	// static int N;
	// static Point points[N];
    int N;
	scanf("%d",&N);
    Point *points[N];
	for (int i=0;i<N;i++){
        points[i] = (Point *)malloc(sizeof(Point));
		scanf("%d %d",&(points[i]->X),&(points[i]->Y));
	}
	pts = points[0];
	return N;
	
}
*/

void find_spec_point(Point *points,int N,Point *point1,Point *point2){
	long long X_min,Y_min,X_max,Y_max;
    X_min = points[0].X;
	X_max = points[0].X;
	Y_min = points[0].Y;
	Y_max = points[0].Y;

	// X min
	for (int i=1;i<N;i++){
		
		if (points[i].X<X_min){
		
			X_min = points[i].X;
		}
	}

	// X max
	for (int i=1;i<N;i++){
		if (points[i].X>X_max){
		
			X_max = points[i].X;
		}
	}

	// Y min
	for (int i=1;i<N;i++){
		if (points[i].Y<Y_min){
		
			Y_min = points[i].Y;
		}
	}

	// Y max
	for (int i=1;i<N;i++){
		if (points[i].Y>Y_max){
		
			Y_max = points[i].Y;
		}
	}

	point1->X = X_min;
	point1->Y = Y_min;
	point2->X = X_max;
	point2->Y = Y_max;
}

long long cal_area(Point point1,Point point2){
	long long width = point2.X-point1.X;
	long long  height = point2.Y-point1.Y;
    long max = width >height ? width:height;
	return max * max;
}


void output(long long area){
	printf("%lld\n",area);
}
int main(){
	int N;
	scanf("%d",&N);
    Point points[N];
    for (int i=0;i<N;i++){
       
        scanf("%lld %lld",&(points[i].X),&(points[i].Y));
    }
	long long area;
	Point point1,point2;
	find_spec_point(points,N,&point1,&point2);
	area = cal_area(point1,point2);
	output(area);
	
	return 0;
}
