// Marco Ivaldi <raptor@0xdeadbeef.info>

#include <stdio.h>

#define BUFSIZE 256
#define FMT "whatever"

void copy_string(char *string, int number)
{
	char buf[BUFSIZE];
	char fmt[] = "whatever";

	// ruleid: raptor-insecure-api-sprintf-vsprintf
	sprintf(buf, "string: %s\n", string);

	// ok: raptor-insecure-api-sprintf-vsprintf
	sprintf(buf, "number: %d\n", number);

	// ruleid: raptor-insecure-api-sprintf-vsprintf
	sprintf(buf, FMT, string);

	// ruleid: raptor-insecure-api-sprintf-vsprintf
	sprintf(buf, fmt, string);

	// ruleid: raptor-insecure-api-sprintf-vsprintf
	sprintf(buf, string);
}

static void
WriteToLog(jrun_request *r, const char *szFormat, ...)
{
	server_rec *s = (server_rec *)r->context;
	va_list list;
	char szBuf[2048];

	strcpy(szBuf, r->stringRep);
	va_start(list, szFormat);
	// ruleid: raptor-insecure-api-sprintf-vsprintf
	vsprintf(strchr(szBuf, '\0'), szFormat, list);
	va_end(list);

#if MODULE_MAGIC_NUMBER > 19980401
	ap_log_error(APLOG_MARK, APLOG_NOERRNO | APLOG_NOTICE, s, "%s", szBuf);
#else
	log_error(szBuf, s);
#endif

#ifdef WIN32
	strcat(szBuf, "\r\n");
	OutputDebugString(szBuf);
#endif
}

int main()
{
	printf("Hello, World!");
	return 0;
}
