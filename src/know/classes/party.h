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

typedef struct know_party {
} know_party_t;

inline know_party_t* know_party_alloc() {
  return calloc(1, sizeof(know_party_t));
}

inline know_party_t** know_parties_alloc(const size_t count) {
  return calloc(count, sizeof(know_party_t*));
}

inline know_party_t* know_party_clone(const know_party_t* thing) {
  know_party_t* clone = know_party_alloc();
  return clone;
}

inline know_party_t** know_parties_clone(const know_party_t** things) {
  return NULL; // TODO
}

inline void know_party_free(know_party_t* thing) {
  if (!thing) return;
  free(thing);
}

inline void know_parties_free(know_party_t** things) {
  // TODO
}
