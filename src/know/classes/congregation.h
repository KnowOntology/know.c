/* This is free and unencumbered software released into the public domain. */

#pragma once

#define _POSIX_C_SOURCE 200809L
#include <stddef.h> // for NULL, size_t
#include <stdint.h> // for uint64_t
#include <stdlib.h> // for calloc(), free(), realloc()
#include <string.h> // for strdup()
#include <time.h>   // for time_t

#include "_prelude.h"

typedef struct know_group know_group_t;
inline void know_group_free(know_group_t*);
inline void know_groups_free(know_group_t**);
inline know_group_t* know_group_clone(const know_group_t*);
inline know_group_t** know_groups_clone(const know_group_t**);

typedef struct know_congregation {
} know_congregation_t;

inline know_congregation_t* know_congregation_alloc() {
  return calloc(1, sizeof(know_congregation_t));
}

inline know_congregation_t** know_congregations_alloc(const size_t count) {
  return calloc(count, sizeof(know_congregation_t*));
}

inline know_congregation_t* know_congregation_clone(const know_congregation_t* thing) {
  know_congregation_t* clone = know_congregation_alloc();
  return clone;
}

inline know_congregation_t** know_congregations_clone(const know_congregation_t** things) {
  return NULL; // TODO
}

inline void know_congregation_free(know_congregation_t* thing) {
  if (!thing) return;
  free(thing);
}

inline void know_congregations_free(know_congregation_t** things) {
  // TODO
}
