#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

typedef struct NODE {
	char SecondName[255];
	unsigned int AccountCode;
	long Summary;
	time_t LastChange;
	struct NODE *next;

} UserList;

UserList *AddUser()
{

	UserList *NewUser = (UserList *) malloc(sizeof(UserList));
	puts("Entering UserInfo:");
	printf("SecondName:  ");
	scanf("%s", NewUser->SecondName);
	printf("AccountCode: ");
	scanf("%u", &NewUser->AccountCode);
	printf("Summary:     ");
	scanf("%ld", &NewUser->Summary);
	NewUser->LastChange = time(NULL);
	NewUser->next = 0;

	return NewUser;
}

void EditUser(UserList *curr)
{

	puts("Entering new UserInfo:");
	printf("SecondName:  ");
	scanf("%s", curr->SecondName);
	printf("AccountCode: ");
	scanf("%u", &curr->AccountCode);
	printf("Summary:     ");
	scanf("%ld", &curr->Summary);
	curr->LastChange = time(NULL);

}


void PrintNode(UserList * node)
{
	puts("");
	printf("SecondName:  %s\n", node->SecondName);
	printf("AccountCode: %u\n", node->AccountCode);
	printf("Summary:     %ld\n", node->Summary);

	struct tm *aTm = localtime(&(node->LastChange));
	printf("LastChange: %02d.%02d.%04d %02d:%02d:%02d\n", aTm->tm_mday,
	       aTm->tm_mon + 1, aTm->tm_year + 1900, aTm->tm_hour, aTm->tm_min,
	       aTm->tm_sec);
	puts("");
}

void ViewTable(UserList * start)
{
	while (start != NULL) {
		PrintNode(start);
		start = start->next;
	}

}

void OutTable(UserList * start)
{
	char filename[255];
	printf("Enter filename for output: ");
	scanf("%s", filename);
	FILE *file = fopen(filename, "w+");
	UserList *curr = start;
	while (curr != 0) {
		fprintf(file, "%s ", curr->SecondName);
		fprintf(file, "%u ", curr->AccountCode);
		fprintf(file, "%ld ", curr->Summary);
		fprintf(file, "%ld\n", curr->LastChange);
		curr = curr->next;
	}
	fclose(file);
}

UserList *InputTable(UserList * start)
{
	char filename[255];
	printf("Enter filename for input: ");
	scanf("%s", filename);
	FILE *file = fopen(filename, "r+");
	if (file == NULL) {
		printf("Cannot find file\n");
		exit(0);
	}

	UserList *curr = NULL;	//Просто хранит текущий 
	UserList *first = NULL;	//Возврат для закрепления списка
	UserList *prev = NULL;	//Для привязки next к след созд
	unsigned int AccountCode;
	long Summary;
	time_t LastChange;

	fscanf(file, "%s %u %ld %ld \n", filename, &AccountCode, &Summary,
	       &LastChange);
	printf("%s\n", filename);
	curr = (UserList *) malloc(sizeof(UserList));
	strcpy(curr->SecondName, filename);
	curr->AccountCode = AccountCode;
	curr->Summary = Summary;
	curr->LastChange = LastChange;
	first = curr;
	curr = curr->next;
	prev = first;

	while (!feof(file)) {

		fscanf(file, "%s %u %ld %ld \n", filename, &AccountCode,
		       &Summary, &LastChange);
		printf("%s\n", filename);

		curr = (UserList *) malloc(sizeof(UserList));
		strcpy(curr->SecondName, filename);
		curr->AccountCode = AccountCode;
		curr->Summary = Summary;
		curr->LastChange = LastChange;

		prev->next = curr;
		prev = curr;
		curr = curr->next;
	}

/*

		curr = (UserList *) malloc(sizeof(UserList));
		if (first == NULL)
			first = curr;

		
		sscanf(filename, "%s:%u:%ld:ld\n", curr->SecondName,
		       &(curr->AccountCode), &(curr->Summary),
		       &(curr->LastChange));
		printf("%s:", curr->SecondName);
		printf("%u:", curr->AccountCode);
		printf("%ld:", curr->Summary);
		printf("%ld\n", curr->LastChange);
		curr = curr->next;
	}*/
	fclose(file);
	return first;
}



void Clear(UserList * start)
{
	UserList *curr = NULL;
	while (start != NULL) {
		curr = start->next;
		free(start);
		start = curr;
	}

}

UserList *DeleteNode(UserList * node, UserList * prev)
{
	if (prev == NULL) {
		prev = node->next;
		free(node);
		return prev;
	}
	else{
	UserList* tmp = node->next;
	free(node);
	prev->next=tmp;
	return 0;
	}

}

UserList* FindElem(UserList *start){

printf("");


}	


void Sort()
{
//Сортировать созданием нового списка и обновлением start

}

void SwapNodes(UserList * curr, UserList * prev)
{				//Меняет текущий и следующий
	UserList *tmp;		// Все ещё не увере в том как мне перезаписывать start в случае если мы меняем 1ый элем и 2ой.
	tmp = curr->next;
	curr = (curr->next)->next;

}
