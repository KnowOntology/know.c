/* This is free and unencumbered software released into the public domain. */

#pragma once

#define _POSIX_C_SOURCE 200809L
#include <stddef.h> // for NULL, size_t
#include <stdint.h> // for uint64_t
#include <stdlib.h> // for calloc(), free(), realloc()
#include <string.h> // for strdup()
#include <time.h>   // for time_t

#include "_prelude.h"

typedef struct know_thing know_thing_t;
inline void know_thing_free(know_thing_t*);
inline void know_things_free(know_thing_t**);
inline know_thing_t* know_thing_clone(const know_thing_t*);
inline know_thing_t** know_things_clone(const know_thing_t**);

typedef struct know_file {
  uint64_t size_in_bytes;
} know_file_t;

inline know_file_t* know_file_alloc() {
  return calloc(1, sizeof(know_file_t));
}

inline know_file_t** know_files_alloc(const size_t count) {
  return calloc(count, sizeof(know_file_t*));
}

inline know_file_t* know_file_clone(const know_file_t* thing) {
  know_file_t* clone = know_file_alloc();
  clone->size_in_bytes = thing->size_in_bytes;
  return clone;
}

inline know_file_t** know_files_clone(const know_file_t** things) {
  return NULL; // TODO
}

inline void know_file_free(know_file_t* thing) {
  if (!thing) return;
  free(thing);
}

inline void know_files_free(know_file_t** things) {
  // TODO
}

inline know_file_t* know_file_size_in_bytes_clone(const know_file_t* thing) {
  return NULL; // TODO
}

inline void know_file_size_in_bytes_set(know_file_t* thing, const uint64_t value) {
  thing->size_in_bytes = value;
}
