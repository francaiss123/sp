#include <stdio.h>

int main() {
	int mas[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	for (int i = 0; i<10; i++) {
		if (i%2 == 0) mas[i] <<= 1;
		else mas[i] = mas[i] >> 1;
	printf("%d ", mas[i]);
	}
printf("\n");
return 0;
}
