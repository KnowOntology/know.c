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

typedef struct know_hotel {
} know_hotel_t;

inline know_hotel_t* know_hotel_alloc() {
  return calloc(1, sizeof(know_hotel_t));
}

inline know_hotel_t** know_hotels_alloc(const size_t count) {
  return calloc(count, sizeof(know_hotel_t*));
}

inline know_hotel_t* know_hotel_clone(const know_hotel_t* thing) {
  know_hotel_t* clone = know_hotel_alloc();
  return clone;
}

inline know_hotel_t** know_hotels_clone(const know_hotel_t** things) {
  return NULL; // TODO
}

inline void know_hotel_free(know_hotel_t* thing) {
  if (!thing) return;
  free(thing);
}

inline void know_hotels_free(know_hotel_t** things) {
  // TODO
}
