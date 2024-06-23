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

typedef struct know_buddhist_temple {
} know_buddhist_temple_t;

inline know_buddhist_temple_t* know_buddhist_temple_alloc() {
  return calloc(1, sizeof(know_buddhist_temple_t));
}

inline know_buddhist_temple_t** know_buddhist_temples_alloc(const size_t count) {
  return calloc(count, sizeof(know_buddhist_temple_t*));
}

inline know_buddhist_temple_t* know_buddhist_temple_clone(const know_buddhist_temple_t* thing) {
  know_buddhist_temple_t* clone = know_buddhist_temple_alloc();
  return clone;
}

inline know_buddhist_temple_t** know_buddhist_temples_clone(const know_buddhist_temple_t** things) {
  return NULL; // TODO
}

inline void know_buddhist_temple_free(know_buddhist_temple_t* thing) {
  if (!thing) return;
  free(thing);
}

inline void know_buddhist_temples_free(know_buddhist_temple_t** things) {
  // TODO
}
