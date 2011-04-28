/*
 * include/linux/nfs_redundancy.h
 *
 * NFS redundancy definitions
 *
 * Copyright (c) 2011 Lee Trager
 * 
 * Lee Trager <lt73@cs.drexel.edu>
 *
 */

#ifndef _LINUX_NFS_REDUNDANCY_H
#define _LINUX_NFS_REDUNDANCY_H

enum REDUN_VERIFIED { VERIFIED, NOT_VERIFIED };

struct nfs4_redundancy
{
	struct nfs_server* srv;
	int latency;
	enum REDUN_VERIFIED verified;
	int files;
	struct nfs_redundancy_list* next;
};

#endif

