//
// student.c
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "student.h"
#include "encrypt/encrypt.h"


const char* STUFILE = "studentdata.txt";

// keeps track of the number of students in the students array
int numStudents = 0;

// holds the student pointer array
Student* students[100] = {0};


void createStudent(char* fname, char* lname, int age, int id)
{
  // createStudent dynamically creates a Student on the heap and adds that
  // student to the student array
  //  - the firstName and lastName strings should be dynamically created
  //    based on the size of the fname and lname args
  Student* stu = (Student*) malloc(sizeof(Student));
  stu->firstName = (char*) malloc((strlen(fname) + 1) * sizeof(char));
  stu->lastName = (char*) malloc((strlen(lname) + 1) * sizeof(char));
  strcpy(stu->firstName, fname);
  strcpy(stu->lastName, lname);
  stu->age = age;
  stu->id = id;
  students[numStudents] = stu;
  numStudents++;
}


void deleteStudent(Student* student)
{
  // free the memory associated with a student including the strings
  free(student->firstName);
  free(student->lastName);
  free(student);
}


void deleteStudents()
{
  // iterate over the students array deleting every student and setting te pointer
  // values to 0 and adjusting the numStudents to 0
  for (int i = 0; i < numStudents; i++)
  {
    deleteStudent(students[i]);
    students[i] = 0;
  }
  numStudents = 0;
}


void saveStudents(int key)
{
  // save all students in the student array to a file 'studentdata.txt' overwriting
  // any existing file
  //   - the format of the file is one line per student as follows fname lname age id:
  //       tom thumb 15 1234 
  //       james dean 21 2345 
  //       katy jones 18 4532 
  FILE* fp;
  char line[256];
  fp = fopen(STUFILE, "w");
  if (fp)
  {
    for (int i = 0; i < numStudents; i++)
    {
      sprintf(line, "%s %s %d %ld", students[i]->firstName, students[i]->lastName, students[i]->age, students[i]->id);
      if (key != 0)
      {
        caesarEncrypt(line, key);
      }
      fprintf(fp, "%s\n", line);
      printf("saving: %s\n", line);
    }
  printf("saved %d students", numStudents);
  }
  fclose(fp);
}


void loadStudents(int key)
{
  // load the students from the data file overwriting all exisiting students in memory
  if (numStudents > 0)
  {
    deleteStudents();
  }
  FILE* fp;
  char line[256];
  fp = fopen(STUFILE, "r");
  if (fp)
  {
    while (fgets(line, sizeof(line), fp))
    {
      if (key != 0)
      {
        caesarDecrypt(line, key);
      }
      char* fname = strtok(line, " ");
      char* lname = strtok(NULL, " ");
      int age = atoi(strtok(NULL, " "));
      int id = atoi(strtok(NULL, " "));
      createStudent(fname, lname, age, id);
    }
  }
  fclose(fp);
  printf("loaded %d students", numStudents);
}


void printStudent(Student* student)
{
  printf("  Student: %s %s\n", student->firstName, student->lastName);
  printf("    age: %d\n", student->age);
  printf("    id: %ld\n", student->id); 
}


void printStudents()
{
  for (int i = 0; i < numStudents; i++) {
    printf("\n----- student %d ------\n", i);
    printStudent(students[i]);
  }
}




