#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <dirent.h>

void menu1(FILE *file);
void menu2(FILE *file);
void menu3(FILE *file, char *file_name);

int main()
{
	FILE *file = NULL;
	int menu = 0, flag_end = 1;
	char *file_name = malloc(100);
	while (flag_end != 0)
	{
		scanf("%d", &menu);
		switch (menu)
		{
		case 1:
			scanf("%s", file_name);
			file = fopen(file_name, "r");
			menu1(file);
			fclose(file);
			break;
		
		case 2:
			file = fopen(file_name, "a");
			menu2(file);
			fclose(file);
			file = fopen(file_name, "r");
			menu1(file);
			fclose(file);
			break;
		case 3:
			printf("tut11");
			menu3(file, file_name);
			printf("tut12");
			break;
		case -1:
			flag_end = 0;
			break;
		default:
			printf("n/a1\n");
			break;
		}
	}
	free(file_name);
	
	// char file_name[100], ch, ch_test[100];
	// int menu = 1, err = 1;
	// FILE *file;
	// while (scanf("%d", &menu) == 1 && menu != -1 && err == 1)
	// {
	// 	if (menu == 1)
	// 	{
	// 		scanf("%s", file_name);
	// 		file = fopen(file_name, "r");
	// 		if (file == NULL) err = 0;
	// 		else
	// 		{
	// 			while ((ch = fgetc(file)) != EOF) {
	// 				putchar(ch);
	// 			}
	// 			fclose(file);
	// 		}
	// 	}
	// 	else if (menu == 2)
	// 	{
	// 		char text[100];
	// 		scanf("%s", text);
	// 		file = fopen(file_name, "a");
	// 		if (file == NULL) err = 0;
	// 		fputs(text, file);
    // 		fputs("\n", file);
	// 		fclose(file);
	// 		file = fopen(file_name, "r");
	// 		if (file == NULL) err = 0;
	// 		else
	// 		{
	// 			while ((ch = fgetc(file)) != EOF) {
	// 				putchar(ch);
	// 			}
	// 			fclose(file);
	// 		}
	// 	}
	// 	else if (menu == 3)
	// 	{
	// 		int enc;
	// 		if (scanf("%d", &enc) != 1 || enc < 0 || enc > 27) err = 0;
	// 		char file_c[3] = {"ai_modules//m1.c", "ai_modules//m2.c"};
	// 		char file_h[3] = {"ai_modules//m1.h", "ai_modules//m2.h"};
	// 		for (int i = 0; i < 2; i++)
	// 		{
	// 			file = fopen(file_h[i], "w");
	// 			fputc("", file);
	// 			fclose(file);
	// 			file = fopen(file_c[i], "r");
	// 			if (file == NULL) err = 0;
	// 			else
	// 			{
	// 				int i = 0;
	// 				while ((ch = fgetc(file)) != EOF) {
	// 					if (islower(ch) && ch != '\0' && ch != '\n') ch_test[i] = (((ch - 'a') + enc) % 26) + 'a';
	// 					else if (ch != '\0' && ch != '\n') ch_test[i] = (((ch - 'A') + enc) % 26) + 'A';
	// 					i++;
	// 				}
	// 				fclose(file);
	// 			}
	// 			file = fopen(file_name, "w");
	// 			fputs(ch_test, file);
	// 			fclose(file);
	// 		}
	// 	}
	// 	else if (menu == 4)
	// 	{

	// 	}
	// }
	// if (err == 0 && menu != -1) printf("n/a");
	return 0;
}

void menu1(FILE *file)
{
	char ch;
	if (file == NULL)
	{
		printf("n/a\n");
	}
	else
	{
		while ((ch = fgetc(file)) != EOF) {
			putchar(ch);
		}
		printf("\n");
	}
}

void menu2(FILE *file)
{
	char *text = malloc(100);
	scanf("%s", text);
	fputs(text, file);
	free(text);
}

void menu3(FILE *file, char *file_name)
{
	int enc;
	char ch, *ch_arr = malloc(100);
	scanf("%d", &enc);
	char *file_c[3] = {"ai_modules//m1.c", "ai_modules//m2.c"};
	char *file_h[3] = {"ai_modules//m1.h", "ai_modules//m2.h"};
	for (int i = 0; i < 2; i++)
	{
		file = fopen(file_h[i], "w");
		fputc("", file);
		fclose(file);
		file = fopen(file_c[i], "r");
		int i = 0;
		while ((ch = fgetc(file)) != EOF) {
			if (islower(ch) && ch != '\0' && ch != '\n') ch_arr[i] = ((ch - 'a') + enc) % 26 + 'a';
			else if (ch != '\0' && ch != '\n') ch_arr[i] = ((ch - 'A') + enc) % 26 + 'A';
			i++;
		}
		fclose(file);
		file = fopen(file_name, "w");
		fputs(ch_arr, file);
		fclose(file);
	}
	free(ch_arr);
}