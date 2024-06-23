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

typedef struct know_landmark {
} know_landmark_t;

inline know_landmark_t* know_landmark_alloc() {
  return calloc(1, sizeof(know_landmark_t));
}

inline know_landmark_t** know_landmarks_alloc(const size_t count) {
  return calloc(count, sizeof(know_landmark_t*));
}

inline know_landmark_t* know_landmark_clone(const know_landmark_t* thing) {
  know_landmark_t* clone = know_landmark_alloc();
  return clone;
}

inline know_landmark_t** know_landmarks_clone(const know_landmark_t** things) {
  return NULL; // TODO
}

inline void know_landmark_free(know_landmark_t* thing) {
  if (!thing) return;
  free(thing);
}

inline void know_landmarks_free(know_landmark_t** things) {
  // TODO
}
