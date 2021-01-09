#include<stdio.h>
#include <string.h>
struct list{
	int number;
	char name[41];
};
void swap(list *a,list *b){
	list temp = *a;
	*a = *b;
	*b = temp;
}
int main () {
	FILE *f = fopen("testdata.in","r");
	int a;
	fscanf(f,"%d\n",&a);
	list ls[a+1];
	for (int i = 0 ; i <a;i++) {
		fscanf(f,"%d#%[^\n]\n",&ls[i].number,ls[i].name);
	}
	
	for (int i = 0 ; i <a;i++) {
		for (int j = a-1 ; j>i;j-- ) {
			if (strcmp(ls[j].name,ls[j-1].name) < 0) {
				swap(&ls[j],&ls[j-1]);
			}
		}
	}
	for (int i = 0 ; i <a;i++) {
		printf("%d %s\n",ls[i].number,ls[i].name);
	}
	return 0;
}
