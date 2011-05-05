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

// This is the port servers connect to eachother on to discuss redundancy
// new servers etc its also my birthday
#define NFS_REDUNDANCY_PORT	2588

enum REDUN_VERIFIED { VERIFIED, NOT_VERIFIED };

struct nfs4_redundancy
{
	struct addrinfo* srv;		// Socket to server
	int latency;			// Current known latency
	enum REDUN_VERIFIED verified;	// Whether or not the server data is
					// valid
	
	struct list_head list;
};

extern int nfs_redundancy_init(void);

extern void nfs_redundancy_shutdown(void);

#endif

