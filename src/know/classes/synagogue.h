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

typedef struct know_synagogue {
} know_synagogue_t;

inline know_synagogue_t* know_synagogue_alloc() {
  return calloc(1, sizeof(know_synagogue_t));
}

inline know_synagogue_t** know_synagogues_alloc(const size_t count) {
  return calloc(count, sizeof(know_synagogue_t*));
}

inline know_synagogue_t* know_synagogue_clone(const know_synagogue_t* thing) {
  know_synagogue_t* clone = know_synagogue_alloc();
  return clone;
}

inline know_synagogue_t** know_synagogues_clone(const know_synagogue_t** things) {
  return NULL; // TODO
}

inline void know_synagogue_free(know_synagogue_t* thing) {
  if (!thing) return;
  free(thing);
}

inline void know_synagogues_free(know_synagogue_t** things) {
  // TODO
}
