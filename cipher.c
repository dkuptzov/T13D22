#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <dirent.h>

#define LENGTH 100

void menu1(FILE *file);
void menu2(FILE *file, char *file_name);
void menu3(FILE *file);

int main()
{
	FILE *file = NULL;
	int menu = 0, flag_end = 1;
	char file_name[100];
	while (flag_end != 0)
	{
		scanf("%d", &menu);
		switch (menu)
		{
		case 1:
			scanf("%s", file_name);
			file = fopen(file_name, "r");
			menu1(file);
			break;
		case 2:
			menu2(file, file_name);
			break;
		case 3:
			menu3(file);
			break;
		case -1:
			flag_end = 0;
			break;
		default:
			printf("n/a\n");
			break;
		}
	}
	return 0;
}

void menu1(FILE *file)
{
	if (file == NULL)
	{
		printf("n/a\n");
		return;
	}
	char line[LENGTH];
	while (fgets(line, sizeof(line), file))
	{
		fputs(line, stdout);
	}
	fclose(file);
}

void menu2(FILE *file, char *file_name)
{
	if (file == NULL)
	{
		printf("n/a\n");
		return;
	}
	file = fopen(file_name, "a");
	char text[LENGTH];
	getchar();
	fgets(text, sizeof(text), stdin);
	fputs(text, file);
	fclose(file);
	file = fopen(file_name, "r");
	menu1(file);
}

void menu3(FILE *file)
{
	DIR *dir;
    struct dirent *ent;
    char *ext_c = ".c", *ext_h = ".h";
	int enc = 0;
	scanf("%d", &enc);
	if ((dir = opendir("ai_modules")) != NULL)
	{
		while ((ent = readdir(dir)) != NULL)
		{
			char *file_ext = strrchr(ent->d_name, '.');
			if (file_ext != NULL && strcmp(file_ext, ext_h) == 0)
			{
				char path[200] = {"ai_modules/"};
				strcat(path, ent->d_name);
				file = fopen(path, "w");
				if (file == NULL)
				{
					printf("n/a\n");
					return;
				}
				fclose(file);
			}
			if (file_ext != NULL && strcmp(file_ext, ext_c) == 0)
			{
				char path[200] = {"ai_modules/"};
				strcat(path, ent->d_name);
				file = fopen(path, "r");
				char ch_arr[LENGTH], file_in_memory[LENGTH * 100];
				while (fgets(ch_arr, sizeof(ch_arr), file))
				{
					for (int i = 0; ch_arr[i]; i++)
					{
						if (isalpha(ch_arr[i]))
						{
							if (islower(ch_arr[i])) 
								ch_arr[i] = ((ch_arr[i] - 'a') + enc) % 26 + 'a';
							else
								ch_arr[i] = ((ch_arr[i] - 'A') + enc) % 26 + 'A';
						}
					}
					strcat(file_in_memory, ch_arr);
				}
				fclose(file);
				file = fopen(path, "w");
				if (file == NULL)
				{
					printf("n/a\n");
					return;
				}
				fputs(file_in_memory, file);
				fclose(file);
				memset(file_in_memory, 0, sizeof(file_in_memory));
			}
		}
	}
}
