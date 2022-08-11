/* SPDX-License-Identifier: GPL-2.0-or-later */
#ifndef _MINPOOL_H_
#define _MINPOOL_H_

#include <stddef.h>
#include <stdint.h>
#include "list.h"

struct minpool_head {
    struct list_head block_list;
    struct list_head free_list;
    size_t avail;
};

extern void *minpool_alloc(struct minpool_head *head, size_t size);
extern void minpool_free(struct minpool_head *head, void *block);
extern void minpool_setup(struct minpool_head *head, void *array, size_t size);

#endif  /* _MINPOOL_H_ */
