//
// encrypt.c
//

#include <string.h>

#include "encrypt.h"

#include <ctype.h>

#include <stdio.h>


char CHARS[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
int CHARS_LEN = 62;


char shiftChar(char c, int shift, int direction)
{
  // implement the character shift here:
  //  given a char c shift it either forwards (direction == 1) or backwards (direction == 0)
  //  use the CHARS array above
  //  return the newly shifted char
  //
  // eg.
  //   shiftChar('c', 3, 1) : 'f'
  //   shiftChar('S', 2, 0) : 'P'
  //   shiftChar('b', 3, 0) : '8'
  if (isspace(c))
  {
    return c;
  }
  int index;
  if (islower(c))
  {
    index = c - 'a';
  }
  else if (isupper(c))
  {
    index = c - 'A' + 26;
  }
  else if (isdigit(c))
  {
    index = c - '0' + 52;
  }
  else
  {
    printf("not a valid response");
    return c;
  }
  if (direction)
  {
    return CHARS[(index + shift) %CHARS_LEN];
  }
  else
  {
    return CHARS[(index - shift) %CHARS_LEN];
  }
}


void encrypt(char str[], int shifts[], int shiftslen)
{
  for (int i = 0; i < strlen(str); i++) 
  {
    char c = str[i];

    str[i] = shiftChar(c, shifts[i%shiftslen], 1);
  }
}


void decrypt(char str[], int shifts[], int shiftslen)
{
  for (int i = 0; i < strlen(str); i++) 
  {
    char c = str[i];

    str[i] = shiftChar(c, shifts[i%shiftslen], 0);
  }
}


void caesarEncrypt(char str[], int shift)
{
  int shifts[] = { shift };
  encrypt(str, shifts, 1);
}


void caesarDecrypt(char str[], int shift)
{
  int shifts[] = { shift };
  decrypt(str, shifts, 1);
}


