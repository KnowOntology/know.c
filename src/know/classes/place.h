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

typedef struct know_place {
} know_place_t;

inline know_place_t* know_place_alloc() {
  return calloc(1, sizeof(know_place_t));
}

inline know_place_t** know_places_alloc(const size_t count) {
  return calloc(count, sizeof(know_place_t*));
}

inline know_place_t* know_place_clone(const know_place_t* thing) {
  know_place_t* clone = know_place_alloc();
  return clone;
}

inline know_place_t** know_places_clone(const know_place_t** things) {
  return NULL; // TODO
}

inline void know_place_free(know_place_t* thing) {
  if (!thing) return;
  free(thing);
}

inline void know_places_free(know_place_t** things) {
  // TODO
}
