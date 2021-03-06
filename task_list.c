#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <time.h>

int task_number;

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
  printf("File has %i lines\nOutput:\n", lines);

  for (x = 1; x <= lines; x++)
    {
    fgets(buff, 255, (FILE*)fp);
    printf("%s", buff);
    }
}

/*Function for inserting text into file*/
void insert_into_file()
{
  char task[30];
  char temp;

  /*Gets local time*/
  time_t rawtime;
  struct tm * timeinfo;

  time (&rawtime);
  timeinfo = localtime (&rawtime);

  /*Opening file for write, creates file if file does not exist*/
  FILE *fp;
  fp = fopen("tasks.txt", "a+");

  /*Scans and imports input from user*/
  printf("Enter name of the task: ");
  scanf("%c",&temp);
  scanf("%[^\n]",task);

  /*Prints into file*/
  fprintf(fp, "%i - %s: %s", task_number, task, asctime(timeinfo));
  printf("Task %i - %s: %s",task_number, task, asctime(timeinfo));

  task_number++;

  fclose(fp);
}

/*Function for deleting line from file*/
void delete_line()
{
  char buff[255];
  char task_name[100];
  int lines, x, str_compare, ret;

  /*Opens two files for writing*/
  FILE *fp;
  FILE *fp2;

  fp = fopen("tasks.txt", "a+");
  fp2 = fopen("buffer.txt", "a+");

  /*sets position of files pointers to zero*/
  fseek(fp, 0, SEEK_SET);
  fseek(fp2, 0, SEEK_SET);

  printf("Enter name of the task: ");
  scanf("%s", task_name);

  lines = file_length();

  /*Inserts lines into new file without deleted task*/
  for (x = 0; x < lines; x++)
  {
    fgets(buff, 255, fp);

    if (buff[0] == task_name[0])
    {
      ;
    }
    else
    {
      fprintf(fp2, "%s", buff);
    }
  }

  /*Removes tasks.txt*/
  remove("tasks.txt");
  fclose(fp);

  /*Renames buffer.txt to tasklist*/
  ret = rename("buffer.txt", "tasks.txt");
  if(ret == 0)
  {
    printf("Task deleted\n");
  }
  fclose(fp2);
}

/*Main function*/
int main()
{

  char action;
  task_number = 1;

  printf("Type 1 for adding a tasks\nType 2 for displaying tasks\nType 3 to delete task\nType 4 to end this program\n");

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

    /*deleting task*/
    else if (action == '3')
    {
      delete_line();
    }

    /*Ending while loop*/
    else if (action == '4')
    {
      break;
    }
  }
  return 0;
}
