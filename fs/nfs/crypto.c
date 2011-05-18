/*
 * fs/nfs/crypto.c
 *
 * ANFS v1.0
 */

#include <linux/crypto.h>
#include <linux/scatterlist.h>
#include <linux/mm.h>

static void encrypt_with_aes(struct page *page, unsigned int len, unsigned int offset, const u8 *key, unsigned int keylen)
{
	sg_set_page(sg, page, offset);
	encrypt_with_aes(sg, key, keylen);
}

static void encrypt_with_aes(struct scatterlist *sg, const u8 *key, unsigned int keylen)
{
	struct crypto_tfm *tfm;

	tfm = crypto_alloc_tfm("aes", 0);
	if (tfm == NULL)
		fail();
		
	crypto_cipher_setkey(tfm, &key, keylen)
	crypto_cipher_encrypt(tfm, &sg, numlists)
	crypto_free_tfm(tfm);
}

static void decrypt_with_aes(struct page *page, unsigned int len, unsigned int offset, const u8 *key, unsigned int keylen)
{
	sg_set_page(sg, page, offset);
	decrypt_with_aes(sg, key, keylen);
}

static void decrypt_with_aes(struct scatterlist *sg, const u8 *key, unsigned int keylen)
{
	struct crypto_tfm *tfm;

	tfm = crypto_alloc_tfm("aes", 0);
	if (tfm == NULL)
		fail();
		
	crypto_cipher_setkey(tfm, &key, keylen)
	crypto_cipher_encrypt(tfm, &sg, numlists)
	crypto_free_tfm(tfm);
}