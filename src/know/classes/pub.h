/* This is free and unencumbered software released into the public domain. */

#pragma once

#define _POSIX_C_SOURCE 200809L
#include <stddef.h> // for NULL, size_t
#include <stdint.h> // for uint64_t
#include <stdlib.h> // for calloc(), free(), realloc()
#include <string.h> // for strdup()
#include <time.h>   // for time_t

#include "_prelude.h"

typedef struct know_place know_place_t;
inline void know_place_free(know_place_t*);
inline void know_places_free(know_place_t**);
inline know_place_t* know_place_clone(const know_place_t*);
inline know_place_t** know_places_clone(const know_place_t**);

typedef struct know_pub {
} know_pub_t;

inline know_pub_t* know_pub_alloc() {
  return calloc(1, sizeof(know_pub_t));
}

inline know_pub_t** know_pubs_alloc(const size_t count) {
  return calloc(count, sizeof(know_pub_t*));
}

inline know_pub_t* know_pub_clone(const know_pub_t* thing) {
  know_pub_t* clone = know_pub_alloc();
  return clone;
}

inline know_pub_t** know_pubs_clone(const know_pub_t** things) {
  return NULL; // TODO
}

inline void know_pub_free(know_pub_t* thing) {
  if (!thing) return;
  free(thing);
}

inline void know_pubs_free(know_pub_t** things) {
  // TODO
}
