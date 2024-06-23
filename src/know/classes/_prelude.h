/* This is free and unencumbered software released into the public domain. */

#pragma once

#include <stddef.h> // for NULL, size_t
#include <stdlib.h> // for free(), malloc()
#include <string.h> // for strdup()

void know_strings_free(char** input) {
  if (!input) {
    return;
  }

  for (size_t i = 0; input[i]; i++) {
    free(input[i]);
  }

  free(input);
}

char** know_strings_clone(const char** input) {
  if (!input) {
    return NULL;
  }

  size_t count = 0;
  while (input[count]) {
    count++;
  }

  char** output = malloc((count + 1) * sizeof(char*));
  if (!output) {
    return NULL; // ENOMEM
  }

  for (size_t i = 0; i < count; i++) {
    output[i] = strdup(input[i]);
    if (!output[i]) {
      for (size_t j = 0; j < i; j++) {
        free(output[j]);
      }
      free(output);
      return NULL; // ENOMEM
    }
  }

  output[count] = NULL; // sentinel
  return output;
}
