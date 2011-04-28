/*
 * /fs/nfsd/redundancy.h
 *
 * NFS redundancy
 *
 * Copyright (c) 2011 Lee Trager
 *
 * Lee Trager <lt73@cs.drexel.edu>
 *
 */

#ifndef _LINUX_NFSD_REDUNDANCY_H
#define _LINUX_NFSD_REDUNDANCY_H

#include <linux/nfs_redundancy.h>

int nfsd_redundancy_init(void);

void nfsd_redundancy_shutdown(void);


#endif
