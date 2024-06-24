/* This is free and unencumbered software released into the public domain. */

#include <know.h>   // for know_*

#include <stdio.h>  // for printf()
#include <stdlib.h> // for EXIT_SUCCESS, calloc()
#include <string.h> // for strdup()

int main(void) {
  know_thing_t jhacker;
  jhacker.names = calloc(1+1, sizeof(char*));
  jhacker.names[0] = strdup("J. Random Hacker");

  printf("Hello, %s!\n", jhacker.names[0]);

  return EXIT_SUCCESS;
}
