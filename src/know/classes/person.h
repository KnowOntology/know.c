/* This is free and unencumbered software released into the public domain. */

#pragma once

#define _POSIX_C_SOURCE 200809L
#include <stddef.h> // for NULL, size_t
#include <stdint.h> // for uint64_t
#include <stdlib.h> // for calloc(), free(), realloc()
#include <string.h> // for strdup()
#include <time.h>   // for time_t

#include "_prelude.h"

typedef struct know_birth know_birth_t;
inline void know_birth_free(know_birth_t*);
inline void know_births_free(know_birth_t**);
inline know_birth_t* know_birth_clone(const know_birth_t*);
inline know_birth_t** know_births_clone(const know_birth_t**);

typedef struct know_death know_death_t;
inline void know_death_free(know_death_t*);
inline void know_deaths_free(know_death_t**);
inline know_death_t* know_death_clone(const know_death_t*);
inline know_death_t** know_deaths_clone(const know_death_t**);

typedef struct know_group know_group_t;
inline void know_group_free(know_group_t*);
inline void know_groups_free(know_group_t**);
inline know_group_t* know_group_clone(const know_group_t*);
inline know_group_t** know_groups_clone(const know_group_t**);

typedef struct know_thing know_thing_t;
inline void know_thing_free(know_thing_t*);
inline void know_things_free(know_thing_t**);
inline know_thing_t* know_thing_clone(const know_thing_t*);
inline know_thing_t** know_things_clone(const know_thing_t**);

typedef struct know_person {
  char** accounts;
  uint64_t age;
  char** aliases;
  struct know_person** ancestors;
  struct know_person** aunts;
  struct know_birth* birth;
  struct know_person** brothers;
  struct know_person** children;
  struct know_person** colleagues;
  struct know_person** cousins;
  struct know_person** daughters;
  struct know_death* death;
  struct know_person** descendants;
  char** emails;
  struct know_person* father;
  struct know_person** grandchildren;
  struct know_person** granddaughters;
  struct know_person** grandfathers;
  struct know_person** grandmothers;
  struct know_person** grandparents;
  struct know_person** grandsons;
  char** honorifics;
  struct know_person** husbands;
  struct know_person** knows;
  struct know_group** member_ofs;
  struct know_person* mother;
  char** nationalities;
  struct know_person** nephews;
  struct know_person** niblings;
  struct know_person** nieces;
  struct know_person** parents;
  struct know_person** partners;
  char** phones;
  struct know_person** piblings;
  struct know_person** relatives;
  char* sex;
  struct know_person** siblings;
  struct know_person** sisters;
  struct know_person** sons;
  char** speaks;
  struct know_person** spouses;
  struct know_person** stepchildren;
  struct know_person** stepdaughters;
  struct know_person** stepfathers;
  struct know_person** stepmothers;
  struct know_person** stepparents;
  struct know_person** stepsons;
  struct know_person** uncles;
  struct know_person** wives;
} know_person_t;

inline know_person_t* know_person_alloc() {
  return calloc(1, sizeof(know_person_t));
}

inline know_person_t** know_people_alloc(const size_t count) {
  return calloc(count, sizeof(know_person_t*));
}

inline know_person_t* know_person_clone(const know_person_t* thing) {
  know_person_t* clone = know_person_alloc();
  clone->accounts = NULL; // TODO
  clone->age = thing->age;
  clone->aliases = NULL; // TODO
  clone->ancestors = NULL; // TODO
  clone->aunts = NULL; // TODO
  clone->birth = know_birth_clone(thing->birth);
  clone->brothers = NULL; // TODO
  clone->children = NULL; // TODO
  clone->colleagues = NULL; // TODO
  clone->cousins = NULL; // TODO
  clone->daughters = NULL; // TODO
  clone->death = know_death_clone(thing->death);
  clone->descendants = NULL; // TODO
  clone->emails = NULL; // TODO
  clone->father = know_person_clone(thing->father);
  clone->grandchildren = NULL; // TODO
  clone->granddaughters = NULL; // TODO
  clone->grandfathers = NULL; // TODO
  clone->grandmothers = NULL; // TODO
  clone->grandparents = NULL; // TODO
  clone->grandsons = NULL; // TODO
  clone->honorifics = NULL; // TODO
  clone->husbands = NULL; // TODO
  clone->knows = NULL; // TODO
  clone->member_ofs = NULL; // TODO
  clone->mother = know_person_clone(thing->mother);
  clone->nationalities = NULL; // TODO
  clone->nephews = NULL; // TODO
  clone->niblings = NULL; // TODO
  clone->nieces = NULL; // TODO
  clone->parents = NULL; // TODO
  clone->partners = NULL; // TODO
  clone->phones = NULL; // TODO
  clone->piblings = NULL; // TODO
  clone->relatives = NULL; // TODO
  clone->sex = strdup(thing->sex);
  clone->siblings = NULL; // TODO
  clone->sisters = NULL; // TODO
  clone->sons = NULL; // TODO
  clone->speaks = NULL; // TODO
  clone->spouses = NULL; // TODO
  clone->stepchildren = NULL; // TODO
  clone->stepdaughters = NULL; // TODO
  clone->stepfathers = NULL; // TODO
  clone->stepmothers = NULL; // TODO
  clone->stepparents = NULL; // TODO
  clone->stepsons = NULL; // TODO
  clone->uncles = NULL; // TODO
  clone->wives = NULL; // TODO
  return clone;
}

inline know_person_t** know_people_clone(const know_person_t** things) {
  return NULL; // TODO
}

inline void know_person_free(know_person_t* thing) {
  if (!thing) return;
  if (thing->accounts) {
    // TODO: free any array elements with know_strings_free()
    free(thing->accounts);
    thing->accounts = NULL;
  }
  if (thing->aliases) {
    // TODO: free any array elements with know_strings_free()
    free(thing->aliases);
    thing->aliases = NULL;
  }
  if (thing->ancestors) {
    // TODO: free any array elements with know_person_free()
    free(thing->ancestors);
    thing->ancestors = NULL;
  }
  if (thing->aunts) {
    // TODO: free any array elements with know_person_free()
    free(thing->aunts);
    thing->aunts = NULL;
  }
  if (thing->birth) {
    know_birth_free(thing->birth);
    thing->birth = NULL;
  }
  if (thing->brothers) {
    // TODO: free any array elements with know_person_free()
    free(thing->brothers);
    thing->brothers = NULL;
  }
  if (thing->children) {
    // TODO: free any array elements with know_person_free()
    free(thing->children);
    thing->children = NULL;
  }
  if (thing->colleagues) {
    // TODO: free any array elements with know_person_free()
    free(thing->colleagues);
    thing->colleagues = NULL;
  }
  if (thing->cousins) {
    // TODO: free any array elements with know_person_free()
    free(thing->cousins);
    thing->cousins = NULL;
  }
  if (thing->daughters) {
    // TODO: free any array elements with know_person_free()
    free(thing->daughters);
    thing->daughters = NULL;
  }
  if (thing->death) {
    know_death_free(thing->death);
    thing->death = NULL;
  }
  if (thing->descendants) {
    // TODO: free any array elements with know_person_free()
    free(thing->descendants);
    thing->descendants = NULL;
  }
  if (thing->emails) {
    // TODO: free any array elements with know_strings_free()
    free(thing->emails);
    thing->emails = NULL;
  }
  if (thing->father) {
    know_person_free(thing->father);
    thing->father = NULL;
  }
  if (thing->grandchildren) {
    // TODO: free any array elements with know_person_free()
    free(thing->grandchildren);
    thing->grandchildren = NULL;
  }
  if (thing->granddaughters) {
    // TODO: free any array elements with know_person_free()
    free(thing->granddaughters);
    thing->granddaughters = NULL;
  }
  if (thing->grandfathers) {
    // TODO: free any array elements with know_person_free()
    free(thing->grandfathers);
    thing->grandfathers = NULL;
  }
  if (thing->grandmothers) {
    // TODO: free any array elements with know_person_free()
    free(thing->grandmothers);
    thing->grandmothers = NULL;
  }
  if (thing->grandparents) {
    // TODO: free any array elements with know_person_free()
    free(thing->grandparents);
    thing->grandparents = NULL;
  }
  if (thing->grandsons) {
    // TODO: free any array elements with know_person_free()
    free(thing->grandsons);
    thing->grandsons = NULL;
  }
  if (thing->honorifics) {
    // TODO: free any array elements with know_strings_free()
    free(thing->honorifics);
    thing->honorifics = NULL;
  }
  if (thing->husbands) {
    // TODO: free any array elements with know_person_free()
    free(thing->husbands);
    thing->husbands = NULL;
  }
  if (thing->knows) {
    // TODO: free any array elements with know_person_free()
    free(thing->knows);
    thing->knows = NULL;
  }
  if (thing->member_ofs) {
    // TODO: free any array elements with know_group_free()
    free(thing->member_ofs);
    thing->member_ofs = NULL;
  }
  if (thing->mother) {
    know_person_free(thing->mother);
    thing->mother = NULL;
  }
  if (thing->nationalities) {
    // TODO: free any array elements with know_strings_free()
    free(thing->nationalities);
    thing->nationalities = NULL;
  }
  if (thing->nephews) {
    // TODO: free any array elements with know_person_free()
    free(thing->nephews);
    thing->nephews = NULL;
  }
  if (thing->niblings) {
    // TODO: free any array elements with know_person_free()
    free(thing->niblings);
    thing->niblings = NULL;
  }
  if (thing->nieces) {
    // TODO: free any array elements with know_person_free()
    free(thing->nieces);
    thing->nieces = NULL;
  }
  if (thing->parents) {
    // TODO: free any array elements with know_person_free()
    free(thing->parents);
    thing->parents = NULL;
  }
  if (thing->partners) {
    // TODO: free any array elements with know_person_free()
    free(thing->partners);
    thing->partners = NULL;
  }
  if (thing->phones) {
    // TODO: free any array elements with know_strings_free()
    free(thing->phones);
    thing->phones = NULL;
  }
  if (thing->piblings) {
    // TODO: free any array elements with know_person_free()
    free(thing->piblings);
    thing->piblings = NULL;
  }
  if (thing->relatives) {
    // TODO: free any array elements with know_person_free()
    free(thing->relatives);
    thing->relatives = NULL;
  }
  if (thing->sex) {
    free(thing->sex);
    thing->sex = NULL;
  }
  if (thing->siblings) {
    // TODO: free any array elements with know_person_free()
    free(thing->siblings);
    thing->siblings = NULL;
  }
  if (thing->sisters) {
    // TODO: free any array elements with know_person_free()
    free(thing->sisters);
    thing->sisters = NULL;
  }
  if (thing->sons) {
    // TODO: free any array elements with know_person_free()
    free(thing->sons);
    thing->sons = NULL;
  }
  if (thing->speaks) {
    // TODO: free any array elements with know_strings_free()
    free(thing->speaks);
    thing->speaks = NULL;
  }
  if (thing->spouses) {
    // TODO: free any array elements with know_person_free()
    free(thing->spouses);
    thing->spouses = NULL;
  }
  if (thing->stepchildren) {
    // TODO: free any array elements with know_person_free()
    free(thing->stepchildren);
    thing->stepchildren = NULL;
  }
  if (thing->stepdaughters) {
    // TODO: free any array elements with know_person_free()
    free(thing->stepdaughters);
    thing->stepdaughters = NULL;
  }
  if (thing->stepfathers) {
    // TODO: free any array elements with know_person_free()
    free(thing->stepfathers);
    thing->stepfathers = NULL;
  }
  if (thing->stepmothers) {
    // TODO: free any array elements with know_person_free()
    free(thing->stepmothers);
    thing->stepmothers = NULL;
  }
  if (thing->stepparents) {
    // TODO: free any array elements with know_person_free()
    free(thing->stepparents);
    thing->stepparents = NULL;
  }
  if (thing->stepsons) {
    // TODO: free any array elements with know_person_free()
    free(thing->stepsons);
    thing->stepsons = NULL;
  }
  if (thing->uncles) {
    // TODO: free any array elements with know_person_free()
    free(thing->uncles);
    thing->uncles = NULL;
  }
  if (thing->wives) {
    // TODO: free any array elements with know_person_free()
    free(thing->wives);
    thing->wives = NULL;
  }
  free(thing);
}

inline void know_people_free(know_person_t** things) {
  // TODO
}

inline char** know_person_accounts_clone(const know_person_t* thing) {
  return know_strings_clone((const char**)thing->accounts);
}

inline know_person_t* know_person_age_clone(const know_person_t* thing) {
  return NULL; // TODO
}

inline void know_person_age_set(know_person_t* thing, const uint64_t value) {
  thing->age = value;
}

inline char** know_person_aliases_clone(const know_person_t* thing) {
  return know_strings_clone((const char**)thing->aliases);
}

inline struct know_person** know_person_ancestors_clone(const know_person_t* thing) {
  return know_people_clone((const struct know_person**)thing->ancestors);
}

inline struct know_person** know_person_aunts_clone(const know_person_t* thing) {
  return know_people_clone((const struct know_person**)thing->aunts);
}

inline know_person_t* know_person_birth_clone(const know_person_t* thing) {
  return NULL; // TODO
}

inline void know_person_birth_set(know_person_t* thing, const struct know_birth* value) {
  know_birth_free(thing->birth);
  thing->birth = know_birth_clone(value);
}

inline struct know_person** know_person_brothers_clone(const know_person_t* thing) {
  return know_people_clone((const struct know_person**)thing->brothers);
}

inline struct know_person** know_person_children_clone(const know_person_t* thing) {
  return know_people_clone((const struct know_person**)thing->children);
}

inline struct know_person** know_person_colleagues_clone(const know_person_t* thing) {
  return know_people_clone((const struct know_person**)thing->colleagues);
}

inline struct know_person** know_person_cousins_clone(const know_person_t* thing) {
  return know_people_clone((const struct know_person**)thing->cousins);
}

inline struct know_person** know_person_daughters_clone(const know_person_t* thing) {
  return know_people_clone((const struct know_person**)thing->daughters);
}

inline know_person_t* know_person_death_clone(const know_person_t* thing) {
  return NULL; // TODO
}

inline void know_person_death_set(know_person_t* thing, const struct know_death* value) {
  know_death_free(thing->death);
  thing->death = know_death_clone(value);
}

inline struct know_person** know_person_descendants_clone(const know_person_t* thing) {
  return know_people_clone((const struct know_person**)thing->descendants);
}

inline char** know_person_emails_clone(const know_person_t* thing) {
  return know_strings_clone((const char**)thing->emails);
}

inline know_person_t* know_person_father_clone(const know_person_t* thing) {
  return NULL; // TODO
}

inline void know_person_father_set(know_person_t* thing, const struct know_person* value) {
  know_person_free(thing->father);
  thing->father = know_person_clone(value);
}

inline struct know_person** know_person_grandchildren_clone(const know_person_t* thing) {
  return know_people_clone((const struct know_person**)thing->grandchildren);
}

inline struct know_person** know_person_granddaughters_clone(const know_person_t* thing) {
  return know_people_clone((const struct know_person**)thing->granddaughters);
}

inline struct know_person** know_person_grandfathers_clone(const know_person_t* thing) {
  return know_people_clone((const struct know_person**)thing->grandfathers);
}

inline struct know_person** know_person_grandmothers_clone(const know_person_t* thing) {
  return know_people_clone((const struct know_person**)thing->grandmothers);
}

inline struct know_person** know_person_grandparents_clone(const know_person_t* thing) {
  return know_people_clone((const struct know_person**)thing->grandparents);
}

inline struct know_person** know_person_grandsons_clone(const know_person_t* thing) {
  return know_people_clone((const struct know_person**)thing->grandsons);
}

inline char** know_person_honorifics_clone(const know_person_t* thing) {
  return know_strings_clone((const char**)thing->honorifics);
}

inline struct know_person** know_person_husbands_clone(const know_person_t* thing) {
  return know_people_clone((const struct know_person**)thing->husbands);
}

inline struct know_person** know_person_knows_clone(const know_person_t* thing) {
  return know_people_clone((const struct know_person**)thing->knows);
}

inline struct know_group** know_person_member_ofs_clone(const know_person_t* thing) {
  return know_groups_clone((const struct know_group**)thing->member_ofs);
}

inline know_person_t* know_person_mother_clone(const know_person_t* thing) {
  return NULL; // TODO
}

inline void know_person_mother_set(know_person_t* thing, const struct know_person* value) {
  know_person_free(thing->mother);
  thing->mother = know_person_clone(value);
}

inline char** know_person_nationalities_clone(const know_person_t* thing) {
  return know_strings_clone((const char**)thing->nationalities);
}

inline struct know_person** know_person_nephews_clone(const know_person_t* thing) {
  return know_people_clone((const struct know_person**)thing->nephews);
}

inline struct know_person** know_person_niblings_clone(const know_person_t* thing) {
  return know_people_clone((const struct know_person**)thing->niblings);
}

inline struct know_person** know_person_nieces_clone(const know_person_t* thing) {
  return know_people_clone((const struct know_person**)thing->nieces);
}

inline struct know_person** know_person_parents_clone(const know_person_t* thing) {
  return know_people_clone((const struct know_person**)thing->parents);
}

inline struct know_person** know_person_partners_clone(const know_person_t* thing) {
  return know_people_clone((const struct know_person**)thing->partners);
}

inline char** know_person_phones_clone(const know_person_t* thing) {
  return know_strings_clone((const char**)thing->phones);
}

inline struct know_person** know_person_piblings_clone(const know_person_t* thing) {
  return know_people_clone((const struct know_person**)thing->piblings);
}

inline struct know_person** know_person_relatives_clone(const know_person_t* thing) {
  return know_people_clone((const struct know_person**)thing->relatives);
}

inline know_person_t* know_person_sex_clone(const know_person_t* thing) {
  return NULL; // TODO
}

inline void know_person_sex_set(know_person_t* thing, const char* value) {
  free(thing->sex);
  thing->sex = strdup(value);
}

inline struct know_person** know_person_siblings_clone(const know_person_t* thing) {
  return know_people_clone((const struct know_person**)thing->siblings);
}

inline struct know_person** know_person_sisters_clone(const know_person_t* thing) {
  return know_people_clone((const struct know_person**)thing->sisters);
}

inline struct know_person** know_person_sons_clone(const know_person_t* thing) {
  return know_people_clone((const struct know_person**)thing->sons);
}

inline char** know_person_speaks_clone(const know_person_t* thing) {
  return know_strings_clone((const char**)thing->speaks);
}

inline struct know_person** know_person_spouses_clone(const know_person_t* thing) {
  return know_people_clone((const struct know_person**)thing->spouses);
}

inline struct know_person** know_person_stepchildren_clone(const know_person_t* thing) {
  return know_people_clone((const struct know_person**)thing->stepchildren);
}

inline struct know_person** know_person_stepdaughters_clone(const know_person_t* thing) {
  return know_people_clone((const struct know_person**)thing->stepdaughters);
}

inline struct know_person** know_person_stepfathers_clone(const know_person_t* thing) {
  return know_people_clone((const struct know_person**)thing->stepfathers);
}

inline struct know_person** know_person_stepmothers_clone(const know_person_t* thing) {
  return know_people_clone((const struct know_person**)thing->stepmothers);
}

inline struct know_person** know_person_stepparents_clone(const know_person_t* thing) {
  return know_people_clone((const struct know_person**)thing->stepparents);
}

inline struct know_person** know_person_stepsons_clone(const know_person_t* thing) {
  return know_people_clone((const struct know_person**)thing->stepsons);
}

inline struct know_person** know_person_uncles_clone(const know_person_t* thing) {
  return know_people_clone((const struct know_person**)thing->uncles);
}

inline struct know_person** know_person_wives_clone(const know_person_t* thing) {
  return know_people_clone((const struct know_person**)thing->wives);
}
