/* This is free and unencumbered software released into the public domain. */

#pragma once

#define _POSIX_C_SOURCE 200809L
#include <stddef.h> // for NULL, size_t
#include <stdint.h> // for uint64_t
#include <stdlib.h> // for calloc(), free(), realloc()
#include <string.h> // for strdup()
#include <time.h>   // for time_t

#include "_prelude.h"

typedef struct know_link know_link_t;
inline void know_link_free(know_link_t*);
inline void know_links_free(know_link_t**);
inline know_link_t* know_link_clone(const know_link_t*);
inline know_link_t** know_links_clone(const know_link_t**);

typedef struct know_thing {
  char* glyph;
  char** ids;
  struct know_link** links;
  char** names;
  char** notes;
  char** photos;
} know_thing_t;

inline know_thing_t* know_thing_alloc() {
  return calloc(1, sizeof(know_thing_t));
}

inline know_thing_t** know_things_alloc(const size_t count) {
  return calloc(count, sizeof(know_thing_t*));
}

inline know_thing_t* know_thing_clone(const know_thing_t* thing) {
  know_thing_t* clone = know_thing_alloc();
  clone->glyph = strdup(thing->glyph);
  clone->ids = NULL; // TODO
  clone->links = NULL; // TODO
  clone->names = NULL; // TODO
  clone->notes = NULL; // TODO
  clone->photos = NULL; // TODO
  return clone;
}

inline know_thing_t** know_things_clone(const know_thing_t** things) {
  return NULL; // TODO
}

inline void know_thing_free(know_thing_t* thing) {
  if (!thing) return;
  if (thing->glyph) {
    free(thing->glyph);
    thing->glyph = NULL;
  }
  if (thing->ids) {
    // TODO: free any array elements with know_strings_free()
    free(thing->ids);
    thing->ids = NULL;
  }
  if (thing->links) {
    // TODO: free any array elements with know_link_free()
    free(thing->links);
    thing->links = NULL;
  }
  if (thing->names) {
    // TODO: free any array elements with know_strings_free()
    free(thing->names);
    thing->names = NULL;
  }
  if (thing->notes) {
    // TODO: free any array elements with know_strings_free()
    free(thing->notes);
    thing->notes = NULL;
  }
  if (thing->photos) {
    // TODO: free any array elements with know_strings_free()
    free(thing->photos);
    thing->photos = NULL;
  }
  free(thing);
}

inline void know_things_free(know_thing_t** things) {
  // TODO
}

inline know_thing_t* know_thing_glyph_clone(const know_thing_t* thing) {
  return NULL; // TODO
}

inline void know_thing_glyph_set(know_thing_t* thing, const char* value) {
  free(thing->glyph);
  thing->glyph = strdup(value);
}

inline char** know_thing_ids_clone(const know_thing_t* thing) {
  return know_strings_clone((const char**)thing->ids);
}

inline struct know_link** know_thing_links_clone(const know_thing_t* thing) {
  return know_links_clone((const struct know_link**)thing->links);
}

inline char** know_thing_names_clone(const know_thing_t* thing) {
  return know_strings_clone((const char**)thing->names);
}

inline char** know_thing_notes_clone(const know_thing_t* thing) {
  return know_strings_clone((const char**)thing->notes);
}

inline char** know_thing_photos_clone(const know_thing_t* thing) {
  return know_strings_clone((const char**)thing->photos);
}
