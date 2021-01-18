//
// student.c
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "student.h"
#include "encrypt.h"


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
}


void deleteStudent(Student* student)
{
  // free the memory associated with a student including the strings
}


void deleteStudents()
{
  // iterate over the students array deleting every student and setting te pointer
  // values to 0 and adjusting the numStudents to 0
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

  fp = fopen(STUFILE, "rw");
  if (fp)
  {
    for (int i = 0; i < numStudents, i++)
    {
//strcpy parts of students into string
      char * line[256] = students[i]->firstName, students[i]->lastName, students[i]->age, students[i]->id;
      strcpy(line, students[i]->firstName);
      strcat(line, students[i]->lastName);
      strcat(line, students[i]->age);
      strcat(line, students[i]->id);
//opposite of load
      caesarDecrypt(line, key);
      fprint("%s", line);
    }
  }
  fclose(fp);
}


void loadStudents(int key)
{
  // load the students from the data file overwriting all exisiting students in memory
  FILE* fp;
  char line[256];
  fp = fopen(STUFILE, "rw");
  if (fp)
  {
    while (fgets(line, sizeof(line), fp))
    {
      //might be decrypt
      caesarEncrypt(line, key);
      char * fname = strtok(line, " ");
      char * lname = strtok(NULL, " ");
      int age = atoi(strtok(NULL, " "));
      int id = atoi(strtok(NULL, " "));
      createStudent(fname, lname, age, id);
    }
  }
  fclose(fp);
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




