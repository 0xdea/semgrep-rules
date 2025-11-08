// Marco Ivaldi <raptor@0xdeadbeef.info>

#include <stdio.h>
#include <string.h>
#include <unistd.h>

#define BUFSIZE 256

void drop_priv_perm()
{
	// ruleid: raptor-interesting-api-calls
	setuid(getuid());
}

void drop_priv_temp()
{
	// ruleid: raptor-interesting-api-calls
	seteuid(getuid());
}

void copy_append_string(char *string1, char *string2)
{
	char buf[BUFSIZE];

	// ruleid: raptor-interesting-api-calls
	strcpy(buf, string1);

	// ruleid: raptor-interesting-api-calls
	strcat(buf, string2);
}

void copy_string(char *string)
{
	char buf[BUFSIZE];

	// ruleid: raptor-interesting-api-calls
	stpcpy(buf, string);
}

void copy_string1(char *string)
{
	char buf[BUFSIZE];

	// ruleid: raptor-interesting-api-calls
	strncpy(buf, string, BUFSIZE);
}

void copy_string2(char *string)
{
	char buf[BUFSIZE];

	// ruleid: raptor-interesting-api-calls
	stpncpy(buf, string, BUFSIZE);
}

void get_string()
{
	char buf[BUFSIZE];

	// ruleid: raptor-interesting-api-calls
	gets(buf);
}

void memory_copy()
{

	// ...

	// ruleid: raptor-interesting-api-calls
	memcpy(&(((char *)p_buf)[serialization_buffer_offset]),
		   serialized_context_buffer,
		   serialized_context_size);

	// ...

	// ruleid: raptor-interesting-api-calls
	memcpy(&(((char *)p_buf)[serialization_buffer_offset]),
		   serialized_profiles_context_buffer,
		   cfl_sds_len(serialized_profiles_context_buffer));

	// ...

	// ruleid: raptor-interesting-api-calls
	memcpy((void *)str->wrapped.buf, src, 3 * length + 1);

	// ...

	if (net_setup == NULL)
	{
		flb_net_setup_init(&stream->net);
	}
	else
	{
		// ok: raptor-interesting-api-calls
		memcpy(&stream->net, net_setup, sizeof(struct flb_net_setup));
	}

	// ...

	crc = __bswap_32(crc32(0, (const Bytef *)data, len));
	// ok: raptor-interesting-api-calls
	memcpy((char *)c->block_data + outlen, &crc, 4);
	c->used_size = outlen + 4;

	// ...

	// ok: raptor-interesting-api-calls
	memcpy(&load_command, pcmd, sizeof load_command);

	// ...

	// chose not to use pattern-not: $FUN($_, $_, <... sizeof(...) ...>, ...)
	// ruleid: raptor-interesting-api-calls
	memcpy(temp, sysconfig->sortlist,
		   sizeof(*channel->sortlist) * sysconfig->nsortlist);
}

// https://cc-sw.com/semgrep-guide-for-a-security-engineer-part-6-of-6/
static int service_attr_req(sdp_req_t *req, sdp_buf_t *buf) {
  sdp_cont_state_t *cstate = NULL;
  // ...
  if (cstate) {
  sdp_buf_t *pCache = sdp_get_cached_rsp(cstate);
 
  SDPDBG("Obtained cached rsp : %p", pCache);
 
  if (pCache) {
    short sent = MIN(max_rsp_size, pCache->data_size - cstate->cStateValue.maxBytesSent);
    pResponse = pCache->data;
	// ruleid: raptor-interesting-api-calls
    memcpy(buf->data, pResponse + cstate->cStateValue.maxBytesSent, sent);  //Out-of-bound read here
    buf->data_size += sent;
    cstate->cStateValue.maxBytesSent += sent;
    // ...
  }
  // ...
}

int main()
{
	printf("Hello, World!");
	return 0;
}
