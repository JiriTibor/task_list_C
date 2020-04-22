#include <stdio.h>
#include <string.h>

/*Function for inserting text into file*/
void insert_into_file()
{
  char task[100];

  FILE *fp;
  fp = fopen("tasks.txt", "a+");

  scanf("%s", task);
  fprintf(fp, "%s\n", task);

  fclose(fp);
}

/*Function for printing file*/
void print_file()
{
  char buff[255];
  int x;

  FILE *fp;

  fp = fopen("tasks.txt", "r");

  for (x = 0; x < 4; x++)
    {
    fgets(buff, 255, (FILE*)fp);
    printf("%s", buff);
    }
}

int main()
{

  int x, y;
  char action;

  y = 0;

  printf("Type 1 for adding a tasks\nType 2 for displaying tasks\nType 3 to end\n");


  while (1)
  {
    scanf("%c", &action);

    if (action == '1')
    {
      insert_into_file();
    }

    else if (action == '2')
    {
      print_file();
    }

    else if (action == '3')
    {
      break;
    }
  }
  return 0;
}
