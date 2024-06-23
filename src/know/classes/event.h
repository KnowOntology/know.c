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

typedef struct know_thing know_thing_t;
inline void know_thing_free(know_thing_t*);
inline void know_things_free(know_thing_t**);
inline know_thing_t* know_thing_clone(const know_thing_t*);
inline know_thing_t** know_things_clone(const know_thing_t**);

typedef struct know_event {
  time_t end;
  struct know_place* place;
  time_t start;
} know_event_t;

inline know_event_t* know_event_alloc() {
  return calloc(1, sizeof(know_event_t));
}

inline know_event_t** know_events_alloc(const size_t count) {
  return calloc(count, sizeof(know_event_t*));
}

inline know_event_t* know_event_clone(const know_event_t* thing) {
  know_event_t* clone = know_event_alloc();
  clone->end = thing->end;
  clone->place = know_place_clone(thing->place);
  clone->start = thing->start;
  return clone;
}

inline know_event_t** know_events_clone(const know_event_t** things) {
  return NULL; // TODO
}

inline void know_event_free(know_event_t* thing) {
  if (!thing) return;
  if (thing->place) {
    know_place_free(thing->place);
    thing->place = NULL;
  }
  free(thing);
}

inline void know_events_free(know_event_t** things) {
  // TODO
}

inline know_event_t* know_event_end_clone(const know_event_t* thing) {
  return NULL; // TODO
}

inline void know_event_end_set(know_event_t* thing, const time_t value) {
  thing->end = value;
}

inline know_event_t* know_event_place_clone(const know_event_t* thing) {
  return NULL; // TODO
}

inline void know_event_place_set(know_event_t* thing, const struct know_place* value) {
  know_place_free(thing->place);
  thing->place = know_place_clone(value);
}

inline know_event_t* know_event_start_clone(const know_event_t* thing) {
  return NULL; // TODO
}

inline void know_event_start_set(know_event_t* thing, const time_t value) {
  thing->start = value;
}
