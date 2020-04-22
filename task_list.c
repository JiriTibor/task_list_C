#include <stdio.h>
#include <string.h>

/*Function for inserting text into file*/
void insert_into_file()
{
  char task[100];

  /*Opening file for write, creates file if file does not exist*/
  FILE *fp;
  fp = fopen("tasks.txt", "a+");

  /*Scans and imports input from user*/
  scanf("%s", task);
  fprintf(fp, "%s\n", task);

  fclose(fp);
}

/*Function for counting lines of file*/
int file_length()
{
  FILE *fp;
  fp = fopen("tasks.txt", "r");

  unsigned int number_of_lines = 0;
  int ch;

  /*Reads characters until EOF*/
  while (EOF != (ch=getc(fp)))
        if ('\n' == ch)
            ++number_of_lines;

  return number_of_lines;
}

/*Function for printing file*/
void print_file()
{
  char buff[255];
  int x, lines;

  /*Opening file for read*/
  FILE *fp;
  fp = fopen("tasks.txt", "r");

  /*Prints whole file, line by line*/
  lines = file_length();

  for (x = 1; x <= lines; x++)
    {
    fgets(buff, 255, (FILE*)fp);
    printf("%s", buff);
    }
}

/*Main function*/
int main()
{

  char action;

  printf("Type 1 for adding a tasks\nType 2 for displaying tasks\nType 3 to end\n");


  while (1)
  {
    scanf("%c", &action);

    /*Inserting into file*/
    if (action == '1')
    {
      insert_into_file();
    }

    /*Printing file*/
    else if (action == '2')
    {
      print_file();
    }

    /*Ending while loop*/
    else if (action == '3')
    {
      break;
    }
  }
  return 0;
}
