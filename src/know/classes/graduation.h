/* This is free and unencumbered software released into the public domain. */

#pragma once

#define _POSIX_C_SOURCE 200809L
#include <stddef.h> // for NULL, size_t
#include <stdint.h> // for uint64_t
#include <stdlib.h> // for calloc(), free(), realloc()
#include <string.h> // for strdup()
#include <time.h>   // for time_t

#include "_prelude.h"

typedef struct know_event know_event_t;
inline void know_event_free(know_event_t*);
inline void know_events_free(know_event_t**);
inline know_event_t* know_event_clone(const know_event_t*);
inline know_event_t** know_events_clone(const know_event_t**);

typedef struct know_graduation {
} know_graduation_t;

inline know_graduation_t* know_graduation_alloc() {
  return calloc(1, sizeof(know_graduation_t));
}

inline know_graduation_t** know_graduations_alloc(const size_t count) {
  return calloc(count, sizeof(know_graduation_t*));
}

inline know_graduation_t* know_graduation_clone(const know_graduation_t* thing) {
  know_graduation_t* clone = know_graduation_alloc();
  return clone;
}

inline know_graduation_t** know_graduations_clone(const know_graduation_t** things) {
  return NULL; // TODO
}

inline void know_graduation_free(know_graduation_t* thing) {
  if (!thing) return;
  free(thing);
}

inline void know_graduations_free(know_graduation_t** things) {
  // TODO
}
