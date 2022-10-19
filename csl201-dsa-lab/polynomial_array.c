#include <stdio.h>

int main() {
	int px[20], qx[20], rx[20], i, m, n;

	for(i=0; i<20; i++) {
		px[i]=0;
		qx[i]=0;
		rx[i]=0;
	}

	printf("Enter the degree of the first polynomial: ");
	scanf("%d", &m);

	printf("Enter the coefficients of first polynomial P(x): ");
	for(i=0; i<=m; i++) {
		scanf("%d", &px[i]);
	}

	printf("\n\nP(x) = ");
	for(i=0; i<=m; i++) {
		if(i!=m) {
			printf("%dx^%d + ", px[i], i);
		}
		else {
			printf("%dx^%d ", px[i], i);
		}
	}
	printf("\n\n");

	printf("Enter the degree of the second polynomial: ");
	scanf("%d", &n);

	printf("Enter the coefficients of second polynomial Q(x): ");
	for(i=0; i<=n; i++) {
		scanf("%d", &qx[i]);
	}

	printf("\n\nQ(x) = ");
	for(i=0; i<=n; i++) {
		if(i!=n) {
			printf("%dx^%d + ", qx[i], i);
		}
		else {
			printf("%dx^%d ", qx[i], i);
		}
	}
	printf("\n\n");

	m=m>n?m:n;

	for(i=0; i<=m; i++) {
		rx[i]=px[i]+qx[i];
	}

	printf("Resultant of P(x)+Q(x) is: \n");
	printf("R(x) = ");
	for(i=0; i<=m; i++) {
		if(i!=m) {
			printf("%dx^%d + ", rx[i], i);
		}
		else {
			printf("%dx^%d ", rx[i], i);
		}
	}
	printf("\n\n");

	return 0;
}