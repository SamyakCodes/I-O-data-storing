#include<stdio.h>

void writeData();
void readData();
void write();
int main(){
	int n;
	printf("\n\nChoose:\n");
	printf("1.Write Data\n2.Read Data\n3.Exit");
	printf("\nChoose[1/2/3]: ");
	scanf("%d", &n);
	switch(n){
		case 1:
			writeData();
			break;
		case 2:
			readData();
			break;
		case 3:
			printf("Good Bye!");
			break;
		default:
			printf("NOT AN OPTION!!");
			main();
	}
	return 0;
}
void writeData(){
	int opt;
	printf("\nChoose:");
	printf("\n1.Write Data\n2.Exit\n");
	printf("Choose[1/2]: ");
	scanf("%d", &opt);
	switch(opt){
		case 1:
			write();
			break;
		case 2:
			main();
			break;
		default:
			printf("Not an Option!!\n");
			writeData();
			break;
	}
}
void write(){
	FILE *fptr;
	char name[100];
	char address[100];
	char phone[100];
	fptr = fopen("project.txt", "a");
	printf("Name: ");
	scanf("%s", name);
	printf("Address: ");
	scanf("%s", address);
	printf("Phone: ");
	scanf("%s", phone);
	fprintf(fptr,"\n%s\t\t\t\t%s\t\t\t\t%s\n", name,address,phone);
	fclose(fptr);
	writeData();
}
void readData(){
	FILE *fptr;
	char ch;
	fptr = fopen("project.txt", "r");
	ch = fgetc(fptr);
	while(ch != EOF){
		printf("%c", ch);
		ch = fgetc(fptr);
	}
	printf("\n");
	fclose(fptr);
	main();
}
