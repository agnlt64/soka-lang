#pragma once

#include <stddef.h>

typedef struct LIST_STRUCT
{
  void** items;
  size_t size;
  size_t item_size;
} List_T;

List_T* init_list(size_t items_size);

void list_push(List_T* list, void* item);
