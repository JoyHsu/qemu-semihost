#include <stdio.h>
#include <inttypes.h>


//#define READ_COUNTER_ADDR 0x40050000

//int32_t *read_counter = (int32_t *) READ_COUNTER_ADDR;
int main(void)
{
	/*printf("This is a test program for QEMU counter device\n");
	printf("See http://github.com/krasin/qemu-counter for more details\n\n");
	printf("Let's check if the Read Counter device presented\n");
	for (int i = 0; i < 10; i++) {
		printf("The device has been accessed for %"PRId32" times!\n", *read_counter);
	}
	int32_t now = *read_counter;
	if (now == 0) {
		printf("ERROR - No Read Counter detected\n");
	}
	else if (now == 11) {
		printf("OK - Read Counter works as intended\n");
	}
	else {
		printf("ERROR - Something is wrong with Read Counter\n");
	}*/


	// Open file and show file content
	FILE *file_in=fopen("file_in.txt","r");
	if(!file_in)
		printf("Error: file_in do not open");
	char str_in[30];
	fgets(str_in,sizeof(str_in),file_in);
	printf("%s",str_in);
	close(file_in);


	//Enter some words you want to save
	char str_out[100];
	fgets(str_out,sizeof(str_out),stdin);
	for(int i = 0; i < sizeof(str_out); i++)
		{
		if(str_out[i]=='\n')
			{
			str_out[i]='\0';
			break;
			}
		}	

	
	//Save the words that you just enter in file_out
	FILE *file_out=fopen("file_out.txt","w");
	if(!file_out)
		printf("Error: file_out do not open");
	fputs(str_out,file_out);
	close(file_out);
	printf("the words, %s, are saved in file_out.txt\n",str_out);

	return 0;

}
