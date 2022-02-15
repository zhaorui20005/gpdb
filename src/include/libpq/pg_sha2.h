#define SHA256_PREFIX "sha256"

#define SHA256_PASSWD_LEN strlen(SHA256_PREFIX) + 64
#define SHA256_PASSWD_CHARSET "0123456789abcdef"

#define isSHA256(passwd) \
	((strncmp(passwd, SHA256_PREFIX, strlen(SHA256_PREFIX)) == 0) && \
	strlen(passwd) == (SHA256_PASSWD_LEN) && \
	strspn(passwd + strlen(SHA256_PREFIX), SHA256_PASSWD_CHARSET) == 64)

extern bool pg_sha256_encrypt(const char *pass, char *salt, size_t salt_len,
							  char *cryptpass);
