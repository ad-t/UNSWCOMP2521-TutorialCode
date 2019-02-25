#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TRUE 1
#define FALSE 0

int main (int argc, char * argv[]) {
  char *possiblePalindrome = argv[1];
  size_t length = strlen(possiblePalindrome);
  unsigned int i = 0;
  unsigned int j = length - 1;
  unsigned int success = TRUE;
  while (i < length / 2) {
    if (possiblePalindrome[i] != possiblePalindrome[j]) {
      success = FALSE;
      break;
    }
    i++;
    j--;
  }

  if (success == TRUE) {
    printf("Palindrome!\n");
  } else {
    printf("Not a palindrome.\n");
  }
  return EXIT_SUCCESS;
}
