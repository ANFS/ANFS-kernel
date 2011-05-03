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

#include <linux/slab.h>
#include <linux/stddef.h>
#include <linux/list.h>
#include <linux/nfs_redundancy.h>

// list of redundant servers we know about
static struct nfs4_redundancy* redun_head;

static struct nfs4_redundancy* malloc_nfs4_redundancy(void)
{
	struct nfs4_redundancy* list = NULL;
	list = kmalloc(sizeof(struct nfs4_redundancy), GFP_KERNEL);

	if(list == NULL)
		return NULL;

	list->srv 	= NULL;
	list->latency 	= 0;
	list->verified	= NOT_VERIFIED;
	INIT_LIST_HEAD(&list->list);

	return list;
}

static void free_nfs4_redundancy(struct nfs4_redundancy* redun)
{
	list_del(&redun->list);
	kfree(redun);
}

int nfsd_redundancy_init(void)
{
	printk(KERN_INFO "Initilizing experimental NFS redundancy code...\n");

	redun_head = malloc_nfs4_redundancy();

	if(!redun_head)
	{
		printk(KERN_ERR "NFS Redundancy out of memory!\n");
		return -1;
	}

	return 0;
}

/*
 * The redundancy module needs to work in a P2P fashion. As each node
 * finds out about another redundant node data must 
 */
int nfsd_redundancy_srv(int port)
{
}

void nfsd_redundancy_shutdown(void)
{
	struct list_head* pos;
	struct nfs4_redundancy* tmp;

	list_for_each(pos, &redun_head->list)
	{
		tmp = list_entry(pos, struct nfs4_redundancy, list);

		free_nfs4_redundancy(tmp);
	}
}

