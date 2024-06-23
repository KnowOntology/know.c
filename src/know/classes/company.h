/* This is free and unencumbered software released into the public domain. */

#pragma once

#define _POSIX_C_SOURCE 200809L
#include <stddef.h> // for NULL, size_t
#include <stdint.h> // for uint64_t
#include <stdlib.h> // for calloc(), free(), realloc()
#include <string.h> // for strdup()
#include <time.h>   // for time_t

#include "_prelude.h"

typedef struct know_organization know_organization_t;
inline void know_organization_free(know_organization_t*);
inline void know_organizations_free(know_organization_t**);
inline know_organization_t* know_organization_clone(const know_organization_t*);
inline know_organization_t** know_organizations_clone(const know_organization_t**);

typedef struct know_company {
} know_company_t;

inline know_company_t* know_company_alloc() {
  return calloc(1, sizeof(know_company_t));
}

inline know_company_t** know_companies_alloc(const size_t count) {
  return calloc(count, sizeof(know_company_t*));
}

inline know_company_t* know_company_clone(const know_company_t* thing) {
  know_company_t* clone = know_company_alloc();
  return clone;
}

inline know_company_t** know_companies_clone(const know_company_t** things) {
  return NULL; // TODO
}

inline void know_company_free(know_company_t* thing) {
  if (!thing) return;
  free(thing);
}

inline void know_companies_free(know_company_t** things) {
  // TODO
}
