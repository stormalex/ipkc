#ifndef __DEF_IPC_COMMON_H__
#define __DEF_IPC_COMMON_H__

//alloc memory size
#define IPC_MEM_SIZE            1024*100
#define IPC_FBLOCK_MEM_SIZE     1024*30

#define IPC_ALIGN_ADDR(x)       ((x+0x03)&(~0x03))

#define IPC_PROC_DIR            "ipc"
#define IPC_PROC_MEM_ENTRY      "meminfo"


struct ipc {
    int major;
    struct class* class;
    struct device* dev;
    struct proc_dir_entry* proc_dir;
    struct proc_dir_entry* mem_entry;
    unsigned long mem_base;
    unsigned int mem_size;
    void* vblock;
    void* fblock;
};




#endif //__DEF_IPC_COMMON_H__