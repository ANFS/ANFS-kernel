/*
 * linux/fs/nfs/redundancy.h
 *
 * Copyright (c) 2011 Lee Trager <lt73@cs.drexel.edu>
 *
 * NFS redundancy is a non-standard NFS(i.e not in the IETF spec) feature
 * being implemented as a senior design project at Drexel University.
 * NFS redundancy allows an NFS client to connect to more than one NFS server
 * which has an identical data set. The purpose of this is to give NFS a
 * RAID 1 like feature where if one server goes down the client will still
 * have full access to the data
 */

#ifndef __LINUX_FS_NFS_REDUNDANCY_H
#define __LINUX_FS_NFS_REDUNDANCY_H

int nfs_redundancy_init(struct nfs_server* server);

#endif
