/* This is free and unencumbered software released into the public domain. */

#pragma once

#define _POSIX_C_SOURCE 200809L
#include <stddef.h> // for NULL, size_t
#include <stdint.h> // for uint64_t
#include <stdlib.h> // for calloc(), free(), realloc()
#include <string.h> // for strdup()
#include <time.h>   // for time_t

#include "_prelude.h"

typedef struct know_meeting know_meeting_t;
inline void know_meeting_free(know_meeting_t*);
inline void know_meetings_free(know_meeting_t**);
inline know_meeting_t* know_meeting_clone(const know_meeting_t*);
inline know_meeting_t** know_meetings_clone(const know_meeting_t**);

typedef struct know_conference {
} know_conference_t;

inline know_conference_t* know_conference_alloc() {
  return calloc(1, sizeof(know_conference_t));
}

inline know_conference_t** know_conferences_alloc(const size_t count) {
  return calloc(count, sizeof(know_conference_t*));
}

inline know_conference_t* know_conference_clone(const know_conference_t* thing) {
  know_conference_t* clone = know_conference_alloc();
  return clone;
}

inline know_conference_t** know_conferences_clone(const know_conference_t** things) {
  return NULL; // TODO
}

inline void know_conference_free(know_conference_t* thing) {
  if (!thing) return;
  free(thing);
}

inline void know_conferences_free(know_conference_t** things) {
  // TODO
}
