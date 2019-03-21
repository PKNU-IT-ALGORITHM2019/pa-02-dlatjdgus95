#pragma warning(disable:4996)
#include<stdio.h>
#include<math.h>
#define MAX 20
#define MIN 200;

typedef struct dot {
	int index;
	int x;
	int y;
} Dot;

int N;
int tour[MAX];
double getTour(Dot spot[], int k, double min);
double sumDistance(int N, Dot data[]);
double distance(Dot data1, Dot data2);
void swap(Dot spot[], int i, int j);

int main() {
	char input[20];
	printf("파일 입력 : ");scanf("%s", input);
	FILE *fp = fopen(input, "r");
	if (fp == NULL) {
		printf("불러오기 실패\n");
	}
	else {
		printf("불러오기 성공\n");
	}
	fscanf(fp, "%d", &N);
	Dot spot[MAX];
	for (int i = 0; i < N; i++) {
		spot[i].index = i;
		fscanf(fp, "%d %d", &spot[i].x, &spot[i].y);
	}
	double minsh = MIN;
	printf("%lf\n", getTour(spot, 0, minsh));
	printf("경로: [ ");
	for (int i = 0; i < N - 1; i++) printf("%d, ", tour[i]);
	printf("%d ]\n", tour[N - 1]);
	fclose(fp);
	getchar();
	return 0;
}

double getTour(Dot spot[], int k, double min) {
	if (k == N) {
		return sumDistance(N, spot);
	}
	else {
		for (int i = k; i < N; i++) {
			swap(spot, k, i);
			double tmp = getTour(spot, k + 1, min);
			if (min > tmp) {
				min = tmp;
				if (k == N - 1) {
					for (int i = 0; i < N; i++) {
						tour[i] = spot[i].index;
					}
				}
			}
			swap(spot, k, i);
		}
		return min;
	}
}

double sumDistance(int n, Dot data[]){
	double sum = 0;
	for (int i = 0; i < n; i++) {
		if (i == n - 1) {
			sum += distance(data[i], data[0]);
		}
		else {
			sum += distance(data[i], data[i + 1]);
		}
	}
	return sum;
}

double distance(Dot d1, Dot d2)
{
	return sqrt((d1.x - d2.x)*(d1.x - d2.x) + (d1.y - d2.y)*(d1.y - d2.y));
}

void swap(Dot spot[], int i, int j)
{
	Dot tmp = spot[i];
	spot[i] = spot[j];
	spot[j] = tmp;
}