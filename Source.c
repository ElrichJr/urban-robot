
#define _CRT_SECURE_NO_WARNINGS
#define __STDC_WANT_LIB_EXT1__ 1

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>



struct Project
{
	struct Task* task;
	int personnel;
};

struct Task
{
	time_t start;
	time_t finish;
	int id;
	int depth;
	char name[80];
	struct Task* parallel;
	struct Task* next;
	struct Task* previous;
};

void LoadTree(struct Project *a, FILE *stream);
void SaveTree(struct Task *node, FILE *stream);
void AddTask(struct Project *a, struct Task *addition);

void CreateTask(struct Project *a);
void ShowTasks(struct Task *node);
void DeleteTask(struct Project *a);

void main()
{
	FILE *database = NULL;
	char filename[80];
	for (int correct = 0; !correct; )
	{
		puts("File name: ");
		strcpy(filename, "Database.txt");
//		scanf_s("%s", filename, sizeof(filename));
		if (fopen_s(&database, filename, "r+") != 0)
		{
			printf("Error while opening the file\n");
			correct = 0;
		}
		else
		{
			correct = 1;
		}
	}
	struct Project a;
	struct Task *pointer;
	a.personnel = 5;
	a.task = NULL;
	LoadTree(&a, database);
	for (int correct = 0; !correct; )
	{
		if (fclose(database) != 0)
		{
			printf("Error while closing the file for loading\n");
			correct = 0;
		}
		else
		{
			correct = 1;
		}
	}

	for (int exit = 0; !exit; )
	{
		puts("------MENU------");
		puts("1.Show tasks    ");
		puts("2.Add a new task");
		puts("3.Delete a task ");
		puts("4.Exit          ");
		int choice = 0;
		scanf_s("%i", &choice);
		switch (choice)
		{
			case 1: ShowTasks(a.task); break;
			case 2: CreateTask(&a); break;
			case 3: DeleteTask(&a); break;
			case 4: exit = 1; break;
			default: puts("Wrong choice");
		}
	}

	for (int correct = 0; !correct; )
	{
		if (fopen_s(&database, filename, "w+") != 0)
		{
			printf("Error while opening the file for saving\n");
			correct = 0;
		}
		else
		{
			correct = 1;
		}
	}
	SaveTree(a.task, database);
	for (int correct = 0; !correct; )
	{
		if (fclose(database) != 0)
		{
			printf("Error while closing the file\n");
			correct = 0;
		}
		else
		{
			correct = 1;
		}
	}
}

//-------------------------------------------------------------

void ShowTasks(struct Task *node)
{
	if (node == NULL)
	{
		puts("No tasks found");
		return;
	}
	char idpart[80] = "";
	struct Task *idchecker = node;
	while (idchecker->previous != NULL)
	{
		idchecker = idchecker->previous;
		char id[10] = "";
		_itoa(idchecker->id, id, 10);
		strcat(id, ".");
		strcat(idpart, id);
	}
	char id[10] = "";
	_itoa(node->id, id, 10);
	strcat(idpart, id);
	printf_s("%s: %s\n", idpart, node->name);
	if (node->next != NULL)
	{
		ShowTasks(node->next);
	}
	if (node->parallel->id != 1)
	{
		ShowTasks(node->parallel);
	}
}

void CreateTask(struct Project *a)
{
	struct Task *newTask = malloc(sizeof(struct Task));
	for (int correct = 0; !correct; )
	{
		printf_s("Please enter task name: ");
		if (scanf_s("%s", newTask->name, sizeof(newTask->name)) != 1)
		{
			printf("Something is wrong with the name\n");
			correct = 0;
		}
		else
		{
			correct = 1;
		}
	}
	srand((unsigned int)time(0));
	newTask->start = rand() % 1000;
	printf_s("Start time generated for your convenience: %lf\n", (double)newTask->start);
	newTask->finish = newTask->start + (rand() % 1000);
	printf_s("End time generated for your convenience: %lf\n", (double)newTask->finish);
	newTask->previous = NULL;
	newTask->parallel = NULL;
	newTask->next = NULL;
	AddTask(a, newTask);
}

void AddTask(struct Project *a, struct Task *addition)
{
	if (a->task == NULL)
	{
		a->task = addition;
		a->task->id = 1;
		a->task->depth = 1;
		a->task->parallel = a->task;
	}
	else
	{
		if (a->task->next == NULL)
		{
			a->task->next = addition;
			a->task->next->previous = a->task;
			a->task->next->parallel = a->task->next;
			a->task->next->id = 1;
			a->task->next->depth = a->task->depth + 1;
		}
		else
		{
			a->task = a->task->next;
			while (a->task->parallel->id != 1)
			{
				a->task = a->task->parallel;
			}
			struct Task *temp = a->task->parallel;
			a->task->parallel = addition;
			a->task->parallel->parallel = temp;
			a->task->parallel->previous = a->task->previous;
			a->task->parallel->id = a->task->id + 1;
			a->task->parallel->depth = a->task->depth;
			a->task = a->task->previous;
		}
	}
}

void DeleteTask(struct Project *a)
{

}

void SaveTree(struct Task *node, FILE *stream)
{
	if (node == NULL)
	{
		return;
	}
	fwrite(node, sizeof(struct Task), 1, stream);
	if (node->next != NULL)
	{
		SaveTree(node->next, stream);
	}
	if (node->parallel->id != 1)
	{
		SaveTree(node->parallel, stream);
	}
}

void LoadTree(struct Project *a, FILE *stream)
{
	puts("Loading the tree");
	struct Task *temp = malloc(sizeof(struct Task));
	fread(temp, sizeof(struct Task), 1, stream);
	if (feof(stream)) return;
	a->task = temp;
	a->task->parallel = a->task;
	puts(a->task->name);
	while (!feof(stream))
	{
		puts("Next node");
		struct Task *temp2 = malloc(sizeof(struct Task));
		fread(temp2, sizeof(struct Task), 1, stream);
		if (feof(stream)) break;
		if (a->task->depth >= temp2->depth)
		{
			puts("Wrong depth");
			while (a->task->depth != temp2->depth)
			{
				puts("Moving up the ladder");
				a->task = a->task->previous;
			}
			puts("Moving sideways");
			struct Task *temporary = a->task->parallel;
			a->task->parallel = temp2;
			a->task->parallel->parallel = temporary;
			a->task->parallel->previous = a->task->previous;
			a->task = a->task->parallel;
		}
		else
		{
			a->task->next = temp2;
			a->task->next->previous = a->task;
			a->task->next->parallel = a->task->next;
			a->task = a->task->next;
			puts("Switching to next");
		}
	}
	while (a->task->previous != NULL)
	{
		puts("Returning");
		a->task = a->task->previous;
	}
}