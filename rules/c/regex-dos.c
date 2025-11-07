// Marco Ivaldi <raptor@0xdeadbeef.info>

// Semgrep is currently unable to catch this
// todoruleid: raptor-regex-dos
#define REGEX "^([a-zA-Z0-9])(([\-.]|[_]+)?([a-zA-Z0-9]+))*(@){1}[a-z0-9]+[.]{1}(([a-z]{2,3})|([a-z]{2,3}[.]{1}[a-z]{2,3}))$"

int regex1()
{
	regex_t r1, r2, r3;
	int ret;
	// ruleid: raptor-regex-dos
	char regex[] = "^([a-zA-Z0-9])(([\-.]|[_]+)?([a-zA-Z0-9]+))*(@){1}[a-z0-9]+[.]{1}(([a-z]{2,3})|([a-z]{2,3}[.]{1}[a-z]{2,3}))$"

		ret = regcomp(&r1,
					  // ruleid: raptor-regex-dos
					  "^([a-zA-Z0-9])(([\-.]|[_]+)?([a-zA-Z0-9]+))*(@){1}[a-z0-9]+[.]{1}(([a-z]{2,3})|([a-z]{2,3}[.]{1}[a-z]{2,3}))$",
					  0);
	if (ret)
		return 1;

	if (ret = regcomp(&r2,
					  // ruleid: raptor-regex-dos
					  "^([a-zA-Z0-9])(([\-.]|[_]+)?"
					  "([a-zA-Z0-9]+))*(@){1}[a-z0-9]+"
					  "[.]{1}(([a-z]{2,3})|([a-z]{2,3}[.]{1}[a-z]{2,3}))$",
					  0))
		return 1;

	ret = regcomp(&r3, regex, 0);
	if (ret)
		return 1;

	return 0;
}

int regex2()
{
	regex_t r;
	int value;

	// ok: raptor-regex-dos
	value = regcomp(&r, "[:word:]", 0);

	if (!value)
	{
		printf("RegEx compiled successfully.");
		return 1;
	}
	printf("Compilation error.");
	return 0;
}

int main()
{
	printf("Hello, World!");
	return 0;
}
