#include <stdio.h>
#include <string.h>
#include <stdlib.h>


// student structure
//struct Student...
struct Student{
    char first[50];
    char last[50];
    int age;
    int studentid;
};
void printStudent(struct Student student)
{
  printf("First name: %s\nLast name: %s\nAge: %d\nID: %d\n\n", student.first, student.last, student.age, student.studentid);
}


void printAllStudents(struct Student students[], int num)
{
  // call printStudent for each student in students
  for(int i = 0; i < num; i++){
    printStudent(students[i]);
  }
}


int main()
{

  char input[50];
  // an array of students
  //xxx students;
  struct Student students[50];
  int numStudents = 0;
  while (1)
  {
    char c;
    printf("\nEnter a to add, p to print, q to quit:");
    fgets(input, 256, stdin);
    c = input[0];
    if (sscanf(input, "%c", &c) != 1) continue;
    if (c == 'q')
    {
      break;
    }
    else if (c == 'p')
    {
      // print all students
      printAllStudents(students, numStudents);
    }
    else if (c == 'a')
    {
      // enter a new student
      struct Student newStudent;
      printf("Enter first name: ");
      fgets(input, 256, stdin);
      strcpy(newStudent.first, input);
      printf("Enter last name: ");
      fgets(input, 256, stdin);
      strcpy(newStudent.last, input);
      printf("Enter student age: ");
      fgets(input, 265, stdin);
      newStudent.age = atoi(input);
      printf("Enter student ID: ");
      fgets(input, 256, stdin);
      newStudent.studentid = atoi(input);
      students[numStudents] = newStudent;
      numStudents++;
    }
  }
  
  printf("\nGoodbye!\n");
}
