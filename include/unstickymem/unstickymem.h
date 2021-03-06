#ifndef UNSTICKYMEM_H_
#define UNSTICKYMEM_H_

#include <stdio.h>

#ifdef __cplusplus
// check whether a monitoring core has been passed
extern bool MONITORING_CORE;
extern "C" {
#endif
// the PMC to use
extern int PMC_VALUE;
// the number of worker nodes
extern int OPT_NUM_WORKERS_VALUE;
// the monitoring core
extern int MONITORING_CORE_VALUE;
// Maximum number of nodes in the system
#define MAX_NODES 2
// A structure to hold the nodes information
typedef struct rec {
  int id;
  float weight;
  int count;
} RECORD;

// hold the nodes information ids and weights
extern RECORD nodes_info[MAX_NODES];
// sum of worker nodes weights
extern double sum_ww;
// sum of non-worker nodes weights
extern double sum_nww;
// The adaptation step
// TODO: Make this a command line parameter!
#define ADAPTATION_STEP 10  // E.g. Move 10% of shared pages to the worker nodes

extern int MEM_INIT;

int check_sum(RECORD nodes_info[MAX_NODES]);
void unstickymem_nop(void);
void unstickymem_start(void);
void unstickymem_initialize(void);
void unstickymem_print_memory(void);
void read_weights(char filename[]);
void get_sum_nww_ww(int num_workers);

#ifdef __cplusplus
}  // extern "C"
#endif

#endif  // UNSTICKYMEM_H_
