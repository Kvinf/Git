#include <stdio.h>
#include <string.h>
struct matkul {
	char name [11];
	int id;
};
void swap (matkul *a , matkul *b ) {
	matkul temp = *a;
	*a = *b;
	*b = temp;
}

int main () {
	int a;
	scanf("%d",&a);
	matkul mk[a+1];
	for (int i = 0 ; i<a;i++) {
		getchar();
		scanf("%s %d",mk[i].name,&mk[i].id);
	}
	for (int i = 0 ; i<a;i++) {
		for (int j = a ; j>i;j--) {
			if (mk[j].id == mk[j-1].id) {
				int need = strcmp(mk[j].name,mk[j-1].name);
				if (need < 0) {
					swap (&mk[j],&mk[j-1]);
				}
			} else if (mk[j].id < mk[j-1].id) {
				swap (&mk[j],&mk[j-1]);
			}
		}
	}
	for (int i = 1 ; i<=a;i++) {
		printf("%s\n",mk[i].name);
	}
	return 0;
}

