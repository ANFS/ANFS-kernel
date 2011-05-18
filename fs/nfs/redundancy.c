/*
 * NFS redundancy
 *
 * NFS redundancy is an experimental feature implemented as a Drexel senior
 * design project. NFS redundancy is not an offical part of the NFS spec
 * NFS redundancy adds the ability for NFS clients to connect to multiple NFS
 * servers and preform all normal NFS operations. Each NFS server has an
 * identical data set to the other. When a client preforms any write operation
 * it will be pushed to all NFS servers. In the case of a server failure the
 * client will just stop interacting with the failed server. Thus to the user
 * there is no data loss. This idea is similar to how a hard drive in RAID 1
 * operates.
 *
 * Lee Trager <lt73@cs.drexel.edu>
 *
 */

#include <linux/nfs_fs.h>

/* Make an RPC call to the remote server and ask if they know about any
 * other servers with the same data
 */
int nfs_redundancy_list(struct nfs_server* srv)
{
	//char** list = NULL;
	struct nfs_client* clp = srv->nfs_client;
	int ret = 0;

	if(clp->rpc_ops->get_list != NULL)
	{
		//ret = clp->rpc_ops->get_list(list);
	}

	return ret;
}

int nfs_redundancy_init(struct nfs_server* server)
{
	//struct nfs_client* client = server->nfs_client;
	/* Now that we're connected to the NFS server make an RPC call so see
	 * what other NFS server they know about.
	 */

	/* If we're using redundancy go through the list of server we know of
	 * that have the same data and connect to them. store it in
	 * client->clone. So clone = orig->clone;
	 */

	return 1;
}

