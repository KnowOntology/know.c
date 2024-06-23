/* This is free and unencumbered software released into the public domain. */

#pragma once

#define _POSIX_C_SOURCE 200809L
#include <stddef.h> // for NULL, size_t
#include <stdint.h> // for uint64_t
#include <stdlib.h> // for calloc(), free(), realloc()
#include <string.h> // for strdup()
#include <time.h>   // for time_t

#include "_prelude.h"

typedef struct know_temple know_temple_t;
inline void know_temple_free(know_temple_t*);
inline void know_temples_free(know_temple_t**);
inline know_temple_t* know_temple_clone(const know_temple_t*);
inline know_temple_t** know_temples_clone(const know_temple_t**);

typedef struct know_mosque {
} know_mosque_t;

inline know_mosque_t* know_mosque_alloc() {
  return calloc(1, sizeof(know_mosque_t));
}

inline know_mosque_t** know_mosques_alloc(const size_t count) {
  return calloc(count, sizeof(know_mosque_t*));
}

inline know_mosque_t* know_mosque_clone(const know_mosque_t* thing) {
  know_mosque_t* clone = know_mosque_alloc();
  return clone;
}

inline know_mosque_t** know_mosques_clone(const know_mosque_t** things) {
  return NULL; // TODO
}

inline void know_mosque_free(know_mosque_t* thing) {
  if (!thing) return;
  free(thing);
}

inline void know_mosques_free(know_mosque_t** things) {
  // TODO
}
