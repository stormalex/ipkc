#ifndef __VBLOCK_H__
#define __VBLOCK_H__

#include <linux/fs.h>
#include <linux/init.h>
#include <linux/mm.h>
#include <linux/module.h>
#include <linux/cdev.h>
#include <linux/device.h>
#include <linux/mutex.h>

struct slot {
    struct slot* next;
    unsigned int size;
};

struct vblock {
    unsigned long addr;
    unsigned long addr_end;
    unsigned int total_size;
    unsigned int size;
    struct mutex mutex;
    struct wtsk* wtsk_list;
    struct slot *next;
};

int ipc_vblock_init(struct vblock* vblock, unsigned long addr, unsigned int size);
void ipc_vblock_finalize(struct vblock* vblock);
int ipc_vblock_dump(struct vblock* pool, char *buf, int limit);
void* alloc_vpool(struct vblock* vpool, int size, int wait);
void free_vpool(struct vblock* vpool, void* addr, int size);
#endif //__VBLOCK_H__