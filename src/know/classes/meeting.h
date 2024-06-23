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

typedef struct know_meeting {
} know_meeting_t;

inline know_meeting_t* know_meeting_alloc() {
  return calloc(1, sizeof(know_meeting_t));
}

inline know_meeting_t** know_meetings_alloc(const size_t count) {
  return calloc(count, sizeof(know_meeting_t*));
}

inline know_meeting_t* know_meeting_clone(const know_meeting_t* thing) {
  know_meeting_t* clone = know_meeting_alloc();
  return clone;
}

inline know_meeting_t** know_meetings_clone(const know_meeting_t** things) {
  return NULL; // TODO
}

inline void know_meeting_free(know_meeting_t* thing) {
  if (!thing) return;
  free(thing);
}

inline void know_meetings_free(know_meeting_t** things) {
  // TODO
}
