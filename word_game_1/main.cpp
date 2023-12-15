#pragma warning (disable:4996)
#include <stdlib.h>
#include <stdio.h>
#include "colorize.h"
#include "helper_windows.h"
#include <Windows.h>
#include <time.h>
#include <string.h>
#include <ctype.h>

struct time_and_data {
	int score;
	char level[8];
	char time_data[30];
};

typedef struct USER_INFO {
	char name[20];
	char last_name[20];
	int age;
	char pasword[20];
}user;

typedef struct NODE {
	char word[5];
	struct NODE* next;
	struct NODE* last;
}node;

node* addnode(char word[]) {
	node* ptr;
	ptr = (node*)malloc(sizeof(node));
	strcpy(ptr->word, word);
	ptr->next = NULL;
	ptr->last = NULL;
	return ptr;
}

void addend(node* head, node* addnode) {
	node* curr;
	for (curr = head; curr->next != NULL; curr = curr->next);
	addnode->last = curr;
	curr->next = addnode;
}

int tmp_add[] = { 0,0,0,0,0,0,0 };

void print(node * *head, int n, int strlen, int tmp_add[]) {
	node* curr;
	int j = 0;
	int x = 1;
	for (curr = (*head), j = 0; j < n; curr = curr->next, ++j);
	gotoxy(4, x);
	for (; curr->last != NULL; curr = curr->last) {

		gotoxy(4, x);
		printf("%s\n", curr->word);
		++x;
	}
	//print head
	for (int l = 0; l < strlen; ++l) {
		if (tmp_add[l] == 0) {
			gotoxy(4 + l, x);
			setcolor(15);
			printf("%c", (*head)->word[l]);
			setcolor(15);
		}
		else if (tmp_add[l] == 1) {
			gotoxy(4 + l, x);
			setcolor(2);
			printf("%c", (*head)->word[l]);
			setcolor(15);
		}
		else if (tmp_add[l] == -1) {
			gotoxy(4 + l, x);
			setcolor(4);
			printf("%c", (*head)->word[l]);
			setcolor(15);
		}
	}
}


void delet_head(node * *head) {
	node* curr;
	curr = (*head)->next;
	(*head) = curr;
	(*head)->last = NULL;
}

char tmp[] = "ali";
node* head = addnode(tmp);

void my_callback_on_key_arrival(char c);

//make our periphry
void perifery(int i, int j) {
	setcolor(3);
	for (int m = 0; m < i; ++m) {
		for (int n = 0; n < j; ++n) {
			if (m == 0 || m == i - 1)
				printf("#");
			else if (n == 0 || n == j - 1)
				printf("#");
			else
				printf(" ");
		}
		printf("\n");
	}
	setcolor(15);
}

void perifery_game(int i, int j) {
	setcolor(4);
	for (int m = 0; m < i; ++m) {
		for (int n = 0; n < j; ++n) {
			if (m == 0 || m == i - 1)
				printf("#");
			else if (m == 20) {
				setcolor(6);
				printf("#");
				setcolor(4);
			}
			else if (n == 0 || n == j - 1)
				printf("#");
			else
				printf(" ");
		}
		printf("\n");
	}
	setcolor(15);
}

//////////
int score = 0;                // count score
//////////
int flag = 0;                // a temporary variable for print
//////////
int pa = 0;                   //for cunt word
//////////

int main(void)
{
	//////////
	//////////
	//greeting whit user
	perifery(9, 30);
	setcolor(10);
	gotoxy(13, 2);
	printf("Hi");
	setcolor(6);
	gotoxy(5, 4);
	printf("Welcome to this game");
	setcolor(10);
	gotoxy(4, 6);
	printf("I hope you enjoy that");
	Sleep(4000);
	system("cls");
	setcolor(15);
	//end of greeting

lable:                 ///use for goto                    /////////////////////////////////////////////
	   /////////////////////////////////////////////////       make menu       //////////////////////////////////////////////////////////
	perifery(10, 30);
	setcolor(4);
	gotoxy(4, 2);
	printf("chose one of the item:");
	setcolor(6);
	gotoxy(10, 4);
	printf("1.sign in");
	gotoxy(9, 5);
	printf("2.new player");
	setcolor(15);
	gotoxy(7, 7);
	printf("enter a number:");
	int number;
	scanf("%d", &number);
	system("cls");

	int level;    //for level hard.mediom,easy
	user u1;
	if (number == 2) {
		//get infoamation of new_player
		perifery(17, 25);
		gotoxy(2, 2);
		setcolor(6);
		printf("enter your name:");
		gotoxy(2, 3);
		setcolor(15);
		scanf("%s", u1.name);
		gotoxy(2, 4);
		setcolor(6);
		printf("enter your last name:");
		gotoxy(2, 5);
		setcolor(15);
		scanf("%s", u1.last_name);
		gotoxy(2, 6);
		setcolor(6);
		printf("enter your age:");
		gotoxy(2, 7);
		setcolor(15);
		scanf("%d", &u1.age);
		gotoxy(2, 8);
		setcolor(6);
		printf("enter your pasword:");
		gotoxy(1, 9);
		setcolor(4);
		printf("(safe pasword must have");
		gotoxy(1, 10);
		printf("digit and charackter):");
		gotoxy(2, 11);
		setcolor(15);
		scanf("%s", u1.pasword);
		//check safe or not
		int digiit = 0, charackter = 0;
		for (int i = 0; i < strlen(u1.pasword); ++i) {
			if (isalnum(u1.pasword[i]) == 4)
				++digiit;
			if (isalpha(u1.pasword[i]) == 2)
				++charackter;
		}
		if (digiit == 0 || charackter == 0) {
			gotoxy(2, 13);
			setcolor(124);
			printf("not safe");
			gotoxy(2, 14);
			setcolor(158);
			printf("try again");
			Sleep(2000);
			system("cls");
			goto lable;
		}
		//end of checking
		system("cls");
		// save information in file;
		FILE* ptr;
		ptr = fopen(u1.name, "w");
		if (ptr == NULL)
			printf("eror from line 108__ creat file");
		fprintf(ptr, "%s %s %d %s\n", u1.name, u1.last_name, u1.age, u1.pasword);
		fclose(ptr);
		//menu 2 for new player
		perifery(11, 20);
		setcolor(4);
		gotoxy(4, 2);
		printf("chose level");
		setcolor(6);
		gotoxy(6, 4);
		printf("1.easy");
		gotoxy(6, 5);
		printf("2.mediom");
		gotoxy(6, 6);
		printf("3.hard");
		setcolor(2);
		gotoxy(6, 8);
		printf("level:");
		setcolor(15);
		scanf("%d", &level);
		system("cls");
	}

	char name[20];          //name
	if (number == 1) {
		perifery(10, 23);
		char str_name[20];
		setcolor(6);
		gotoxy(2, 2);
		printf("enter your name:");
		gotoxy(2, 3);
		setcolor(15);
		scanf("%s", str_name);
		char str_pas[20];
		setcolor(6);
		gotoxy(2, 4);
		printf("enter your pasword:");
		gotoxy(2, 5);
		setcolor(15);
		scanf("%s", str_pas);
		//find user own file
		FILE* ptr1;
		ptr1 = fopen(str_name, "r");
		if (ptr1 == NULL) {
			setcolor(4);
			gotoxy(2, 6);
			printf("user not find");
			Sleep(2000);
			system("cls");
			setcolor(15);
			goto lable;         //go to menu
		}
		//char name[20];          name
		char last_name[20];
		char pasword[20];
		int age;
		fscanf(ptr1, "%s%s%d%s", name, last_name, &age, pasword);
		if (strcmp(str_pas, pasword) != 0) {
			setcolor(4);
			gotoxy(2, 6);
			printf("incorect pasword");
			Sleep(2000);
			system("cls");
			goto lable;         //go to menu
		}
		else {
			setcolor(10);
			gotoxy(2, 6);
			printf("USER FIND");
			Sleep(2000);
			system("cls");
		}
		fclose(ptr1);
		//menu 2 
		///////////
	lable1:
		////////////
		perifery(9, 25);
		setcolor(6);
		gotoxy(2, 2);
		printf("chose one item");
		gotoxy(2, 4);
		printf("1.new game");
		gotoxy(2, 5);
		printf("2.recently game");
		setcolor(2);
		gotoxy(2, 7);
		printf("item:");
		setcolor(15);
		int value;
		scanf("%d", &value);
		system("cls");


		if (value == 1) {
			perifery(11, 20);
			setcolor(4);
			gotoxy(4, 2);
			printf("chose level");
			setcolor(6);
			gotoxy(6, 4);
			printf("1.easy");
			gotoxy(6, 5);
			printf("2.mediom");
			gotoxy(6, 6);
			printf("3.hard");
			setcolor(2);
			gotoxy(6, 8);
			printf("level:");
			setcolor(15);
			scanf("%d", &level);
			system("cls");
		}
		if (value == 2) {
			FILE* ptr5;
			ptr5 = fopen(name, "r+");
			if (ptr5 == NULL)
				printf("eror from line 365__open file");
			//skip from line 1
			char tmpp[40];
			fgets(tmpp, 30, ptr5);
			/////////////////////////////////
			int score_in;
			char level_in[8];
			char time_data_in[30];
			int tmp_score = -1;
			char tmp_level[8];
			////////////////
			perifery(10, 66);
			setcolor(4);
			////////////////
			gotoxy(23, 2);
			printf("chose one item");

			int flag_in = 0;
			int i = 0;
			for (i = 0; i < 3; ++i) {
				fscanf(ptr5, "%d%s", &score_in, level_in);         //check if work corect

				if (score_in < 0) {
					setcolor(15);
					gotoxy(20, 5);
					printf("no recently game exist");
					Sleep(4000);
					system("cls");
					break;
				}

				fgets(time_data_in, 30, ptr5);

				if (tmp_score == score_in && strcmp(tmp_level, level_in) == 0)
					break;
				setcolor(i + 5);
				gotoxy(3, i + 4);
				printf("%d.score:%d  level:%s  time_data:%s\n", i + 1, score_in, level_in, time_data_in);
				++flag_in;

				strcpy(tmp_level, level_in);
				tmp_score = score_in;
			}
			fclose(ptr5);
			/////////
			if (flag_in == 0)
				goto lable1;
			////////
			setcolor(i + 5);
			gotoxy(3, i + 4);
			printf("%d.back", i + 1);
			int item_in;
			if (flag_in != 0) {
				gotoxy(24, 8);
				setcolor(10);
				printf("item_in:");
				setcolor(15);
				scanf("%d", &item_in);
				system("cls");
			}
			//chose back
			if (item_in == i + 1)
				goto lable1;

			FILE * ptr6;
			ptr6 = fopen(name, "r+");
			if (ptr6 == NULL)
				printf("eror from line 423__open file");
			//skip from line 1
			//char tmpp[40];
			fgets(tmpp, 30, ptr5);
			/////////////////////////////////
			//int score_in;
			//char level_in[8];
			//char time_data_in[30];
			for (int i = 0; i < item_in; ++i) {
				fscanf(ptr5, "%d%s", &score_in, level_in);         //check if work corect

				fgets(time_data_in, 30, ptr5);
			}
			score = score_in;
			if (strcmp("easy", level_in) == 0)
				level = 1;
			else if (strcmp("mediom", level_in) == 0)
				level = 2;
			else if (strcmp("hard", level_in) == 0)
				level = 3;
		}

	}

	srand(time(NULL));

	//////////////////////////////////////////// creat our file /////////////////////////////////////////////////////////////

	//easy word contain 3 character from lowercase later  97__122 
	FILE * ptr2;
	ptr2 = fopen("easy_word.txt", "w");
	if (ptr2 == NULL)
		printf("eror from line 172__creat file");
	char word[3];
	for (int i = 0; i < 200; ++i) {
		for (int i = 0; i < 3; ++i) {
			word[i] = rand() % 26 + 97;
		}
		fprintf(ptr2, "%c%c%c\n", word[0], word[1], word[2]);
	}
	fclose(ptr2);
	//end of creat

	//hard word contain 5 character from lowercase later  97__122 
	FILE* ptr3;
	ptr3 = fopen("hard_word.txt", "w");
	if (ptr3 == NULL)
		printf("eror from line 188__creat file");
	char word1[5];
	for (int i = 0; i < 200; ++i) {
		for (int i = 0; i < 5; ++i) {
			word1[i] = rand() % 26 + 97;
		}
		fprintf(ptr3, "%c%c%c%c%c\n", word1[0], word1[1], word1[2], word1[3], word1[4]);
	}
	fclose(ptr3);
	//end of creat

	//strong word contain 5 character from 35__47,58__64,114__117
	FILE* ptr4;
	ptr4 = fopen("strong_word", "w");
	if (ptr4 == NULL)
		printf("eror from line 202__creat file");
	char word2[5];
	for (int i = 0; i < 200; ++i) {
		for (int i = 0; i < 2; ++i) {
			word2[i] = rand() % 13 + 35;
		}
		word2[2] = rand() % 4 + 114;
		for (int i = 3; i < 5; ++i) {
			word2[i] = rand() % 7 + 58;
		}
		fprintf(ptr4, "%c%c%c%c%c\n", word2[0], word2[1], word2[2], word2[3], word2[4]);
	}
	fclose(ptr4);
	//end of creat strong word 
	  /////////////////////////////////       after all of this code we now about:
	 /////////////////////////////////        1. level (hard,mediom,easy)
	/////////////////////////////////         2. name,   number==1-->name   , number==2-->u1.name
   /////////////////////////////////	      3. score ==0 || score!=0       
	// print 1 2 3


	setcolor(6);
	gotoxy(9, 3);
	printf("@@@@@\n");
	gotoxy(9, 4);
	printf("    @\n");
	gotoxy(9, 5);
	printf("@@@@@\n");
	gotoxy(9, 6);
	printf("    @\n");
	gotoxy(9, 7);
	printf("@@@@@\n");
	Sleep(1000);
	system("cls");
	setcolor(5);
	gotoxy(9, 3);
	printf("@@@@@\n");
	gotoxy(9, 4);
	printf("    @\n");
	gotoxy(9, 5);
	printf("@@@@@\n");
	gotoxy(9, 6);
	printf("@    \n");
	gotoxy(9, 7);
	printf("@@@@@\n");
	Sleep(1000);
	system("cls");
	setcolor(3);
	gotoxy(9, 3);
	printf("    @\n");
	gotoxy(9, 4);
	printf("    @\n");
	gotoxy(9, 5);
	printf("    @\n");
	gotoxy(9, 6);
	printf("    @\n");
	gotoxy(9, 7);
	printf("    @\n");
	Sleep(1000);
	system("cls");
	setcolor(15);
	/////////////////////////////////////////
   /////////////////////////////////////////
  /////////////////////////////////////////

		  ////////////////////////////////////////////    LETS START GAME      ////////////////////////////////////////////////////


	HANDLE thread_id = start_listening(my_callback_on_key_arrival);

	int timeee = 1000;

	if (level == 1)   //easy
		timeee = 1000;
	else if (level == 2)   //mediom
		timeee = 800;
	else if (level == 3)   //hard
		timeee = 500;

	char str[6];
	int dor = 1;

	FILE * ptr7, *ptr8, *ptr9;
	ptr7 = fopen("easy_word.txt", "r");
	ptr8 = fopen("hard_word.txt", "r");
	ptr9 = fopen("strong_word", "r");
	if (ptr7 == NULL || ptr8 == NULL || ptr9 == NULL)
		printf("eroooor from line 547_____open file\n");


	while (1) {
		if (dor == 1) {
			fscanf(ptr7, "%s", str);
			if (pa == 0)
				head = addnode(str);
			else
				addend(head, addnode(str));
		}
		if (dor == 2) {
			int tmp = rand() % 2;
			if (tmp == 0) {
				fscanf(ptr7, "%s", str);
				addend(head, addnode(str));
			}
			if (tmp == 1) {
				fscanf(ptr8, "%s", str);
				addend(head, addnode(str));
			}
		}
		if (dor >= 3) {
			int tmp = rand() % 4;
			if (tmp == 0) {
				fscanf(ptr7, "%s", str);
				addend(head, addnode(str));
			}
			if (tmp == 1) {
				fscanf(ptr8, "%s", str);
				addend(head, addnode(str));
			}
			if (tmp == 2) {
				fscanf(ptr9, "%s", str);
				addend(head, addnode(str));
			}
			if (tmp == 3) {
				char tmp_str[] = "######";
				addend(head, addnode(tmp_str));
			}
		}

		perifery_game(25, 13);
		if (strcmp(head->word, "######") == 0) {
			int tmppp = rand() % 3;
			if (tmp == 0) {
				fscanf(ptr7, "%s", str);
				addend(head, addnode(str));
			}
			if (tmppp == 1) {
				fscanf(ptr8, "%s", str);
				addend(head, addnode(str));
			}
			if (tmppp == 2) {
				fscanf(ptr9, "%s", str);
				addend(head, addnode(str));
			}
			strcpy(head->word, str);
		}
		print(&head, flag, strlen(head->word), tmp_add);
		gotoxy(2, 22);
		setcolor(5);
		printf("score:%d", score);
		setcolor(15);
		Sleep(timeee);
		system("cls");



		if (pa % 11 == 9) {
			++dor;
			if (level == 1) {
				timeee *= 0.8;
			}
			if (level == 2) {
				timeee *= 0.7;
			}
			if (level == 3) {
				timeee *= 0.6;
			}
		}

		if (timeee < 100)
			break;

		if (flag > 17)
			break;
		++pa;
		++flag;
	}
	_fcloseall();

	struct time_and_data pl;
	pl.score = score;

	if (level == 1)   //easy
		strcpy(pl.level, "easy");
	else if (level == 2)   //mediom
		strcpy(pl.level, "mediom");
	else if (level == 3)   //hard
		strcpy(pl.level, "hard");



	time_t t1 = time(NULL);
	strcpy(pl.time_data, ctime(&t1));

	if (number == 1) {
		FILE* ptr10;
		ptr10 = fopen(name, "a+");
		if (ptr10 == NULL)
			printf("eroooor from line 640_____open file\n");
		fprintf(ptr10, "%d %s %s", pl.score, pl.level, pl.time_data);
		fclose(ptr10);
	}

	if (number == 2) {
		FILE* ptr11;
		ptr11 = fopen(u1.name, "a+");
		if (ptr11 == NULL)
			printf("eroooor from line 645_____open file\n");
		fprintf(ptr11, "%d %s %s", pl.score, pl.level, pl.time_data);
		fclose(ptr11);
	}


	perifery(10, 23);
	gotoxy(6, 2);
	setcolor(6);
	printf("try again");
	gotoxy(3, 4);
	setcolor(15);
	printf("1.your score:%d", score);
	gotoxy(3, 5);
	setcolor(15);
	printf("2.your level:%s", pl.level);
	gotoxy(6, 7);
	if (2) {
		char end[] = "good luck";
		for (int i = 0; end[i] != '\0'; ++i) {
			setcolor(i + 1);
			printf("%c", end[i]);
		}
	}



	setcolor(15);
	WaitForSingleObject(thread_id, 5000);//INFINITE);
	system("cls");
	exit(0);
	return 0;
}
void my_callback_on_key_arrival(char c)
{
	int len = strlen(head->word);
	static int p = 0;               //behave like corsor
	if (c == '5') {  //p==len-1    c== '5'
		--flag;
		delet_head(&head);
		for (; p > 0; --p) {
			//--p;
			tmp_add[p] = 0;
		}
		//--p;   ///////
		tmp_add[p] = 0;
	}
	else {
		if (c == 8) {
			--p;
			tmp_add[p] = 0;

		}
		else {
			if (head->word[p] == c) {
				tmp_add[p] = 1;
				++score;
			}
			else {
				tmp_add[p] = -1;
				--score;
				if (score < 0)
					score = 0;
			}
			++p;
		}
	}
}
