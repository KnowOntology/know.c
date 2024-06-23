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

typedef struct know_link {
  char* url;
} know_link_t;

inline know_link_t* know_link_alloc() {
  return calloc(1, sizeof(know_link_t));
}

inline know_link_t** know_links_alloc(const size_t count) {
  return calloc(count, sizeof(know_link_t*));
}

inline know_link_t* know_link_clone(const know_link_t* thing) {
  know_link_t* clone = know_link_alloc();
  clone->url = strdup(thing->url);
  return clone;
}

inline know_link_t** know_links_clone(const know_link_t** things) {
  return NULL; // TODO
}

inline void know_link_free(know_link_t* thing) {
  if (!thing) return;
  if (thing->url) {
    free(thing->url);
    thing->url = NULL;
  }
  free(thing);
}

inline void know_links_free(know_link_t** things) {
  // TODO
}

inline know_link_t* know_link_url_clone(const know_link_t* thing) {
  return NULL; // TODO
}

inline void know_link_url_set(know_link_t* thing, const char* value) {
  free(thing->url);
  thing->url = strdup(value);
}
