# semgrep-rules
[![](https://img.shields.io/github/stars/0xdea/semgrep-rules.svg?color=yellow)](https://github.com/0xdea/semgrep-rules)
[![](https://img.shields.io/github/forks/0xdea/semgrep-rules.svg?color=green)](https://github.com/0xdea/semgrep-rules)
[![](https://img.shields.io/github/watchers/0xdea/semgrep-rules.svg?color=red)](https://github.com/0xdea/semgrep-rules)
[![](https://img.shields.io/badge/twitter-%400xdea-blue.svg)](https://twitter.com/0xdea)
[![](https://img.shields.io/badge/mastodon-%40raptor-purple.svg)](https://infosec.exchange/@raptor)

> "The attack surface is the vulnerability. Finding a bug there is just a detail."
> 
> -- Mark Dowd

> "Some details are more important than others."
> 
> -- Fedor G. Pikus

A collection of my Semgrep rules to facilitate vulnerability research.

Blog posts:  
https://security.humanativaspa.it/semgrep-ruleset-for-c-c-vulnerability-research  
https://security.humanativaspa.it/automating-binary-vulnerability-discovery-with-ghidra-and-semgrep/  
https://security.humanativaspa.it/big-update-to-my-semgrep-c-cpp-ruleset

See also:  
https://semgrep.dev/r

[![Program in C](https://img.youtube.com/vi/tas0O586t80/sddefault.jpg)](https://www.youtube.com/embed/tas0O586t80)

## Setup and usage instructions

1. Install [Semgrep](https://semgrep.dev/docs/getting-started/). 
2. Clone this github repo.
3. To use these rules, run:

```sh
# high priority scan
$ semgrep --severity ERROR --config PATH/TO/RULES PATH/TO/SOURCE
# high and medium priority scan
$ semgrep --severity ERROR --severity WARNING --config PATH/TO/RULES PATH/TO/SOURCE
# full scan
$ semgrep --config PATH/TO/RULES PATH/TO/SOURCE
```

For a better streamlined experience, I recommend saving semgrep scan output in [SARIF](https://sarifweb.azurewebsites.net/) format and using [SARIF Viewer](https://marketplace.visualstudio.com/items?itemName=MS-SarifVSCode.sarif-viewer) in [VS Code](https://code.visualstudio.com/).

## C/C++

### buffer overflows
* [**insecure-api-gets**](https://github.com/0xdea/semgrep-rules/blob/main/c/insecure-api-gets.yaml). Use of the insecure API function gets().
* [**insecure-api-strcpy-stpcpy-strcat**](https://github.com/0xdea/semgrep-rules/blob/main/c/insecure-api-strcpy-stpcpy-strcat.yaml). Use of potentially insecure API functions strcpy(), stpcpy(), strcat().
* [**insecure-api-sprintf-vsprintf**](https://github.com/0xdea/semgrep-rules/blob/main/c/insecure-api-sprintf-vsprintf.yaml). Use of potentially insecure API functions sprintf() and vsprintf().
* [**insecure-api-scanf-etc**](https://github.com/0xdea/semgrep-rules/blob/main/c/insecure-api-scanf-etc.yaml). Use of potentially insecure API functions in the scanf() family.
* [**incorrect-use-of-strncat**](https://github.com/0xdea/semgrep-rules/blob/main/c/incorrect-use-of-strncat.yaml). Wrong size argument passed to strncat().
* [**incorrect-use-of-strncpy-stpncpy-strlcpy**](https://github.com/0xdea/semgrep-rules/blob/main/c/incorrect-use-of-strncpy-stpncpy-strlcpy.yaml). Wrong size argument passed to strncpy(), stpncpy(), strlcpy().
* [**incorrect-use-of-sizeof**](https://github.com/0xdea/semgrep-rules/blob/main/c/incorrect-use-of-sizeof.yaml). Accidental use of the sizeof() operator on a pointer instead of its target.
* [**unterminated-string-strncpy-stpncpy**](https://github.com/0xdea/semgrep-rules/blob/main/c/unterminated-string-strncpy-stpncpy.yaml). Lack of explicit NUL-termination after strncpy() and stpncpy().
* [**off-by-one**](https://github.com/0xdea/semgrep-rules/blob/main/c/off-by-one.yaml). Potential off-by-one error.
* [**pointer-subtraction**](https://github.com/0xdea/semgrep-rules/blob/main/c/pointer-subtraction.yaml). Potential use of pointer subtraction to determine size.
* [**unsafe-ret-snprintf-vsnprintf**](https://github.com/0xdea/semgrep-rules/blob/main/c/unsafe-ret-snprintf-vsnprintf.yaml). Potentially unsafe use of the return value of snprintf() and vsnprintf().
* [**unsafe-ret-strlcpy-strlcat**](https://github.com/0xdea/semgrep-rules/blob/main/c/unsafe-ret-strlcpy-strlcat.yaml). Potentially unsafe use of the return value of strlcpy() and strlcat().
* [**write-into-stack-buffer**](https://github.com/0xdea/semgrep-rules/blob/main/c/write-into-stack-buffer.yaml). Direct write into buffer allocated on the stack.

### integer overflows
* [**incorrect-unsigned-comparison**](https://github.com/0xdea/semgrep-rules/blob/main/c/incorrect-unsigned-comparison.yaml). Checking if an unsigned variable is negative.
* [**signed-unsigned-conversion**](https://github.com/0xdea/semgrep-rules/blob/main/c/signed-unsigned-conversion.yaml). Potential signed/unsigned conversion errors.
* [**integer-truncation**](https://github.com/0xdea/semgrep-rules/blob/main/c/integer-truncation.yaml). Potential integer truncation errors.
* [**unsafe-strlen**](https://github.com/0xdea/semgrep-rules/blob/main/c/unsafe-strlen.yaml). Casting the return value of strlen() to short might be dangerous.
* [**integer-wraparound**](https://github.com/0xdea/semgrep-rules/blob/main/c/integer-wraparound.yaml). Potential integer wraparound errors.

### format strings
* [**format-string-bugs**](https://github.com/0xdea/semgrep-rules/blob/main/c/format-string-bugs.yaml). Potential format string bugs.

### memory management
* [**insecure-api-alloca**](https://github.com/0xdea/semgrep-rules/blob/main/c/insecure-api-alloca.yaml). Use of the potentially insecure API function alloca().
* [**use-after-free**](https://github.com/0xdea/semgrep-rules/blob/main/c/use-after-free.yaml). Potential use after free().
* [**double-free**](https://github.com/0xdea/semgrep-rules/blob/main/c/double-free.yaml). Potential double free().
* [**incorrect-use-of-free**](https://github.com/0xdea/semgrep-rules/blob/main/c/incorrect-use-of-free.yaml). Calling free() on memory not in the heap.
* [**unchecked-ret-malloc-calloc-realloc**](https://github.com/0xdea/semgrep-rules/blob/main/c/unchecked-ret-malloc-calloc-realloc.yaml). Unchecked return code of malloc(), calloc(), realloc().
* [**ret-stack-address**](https://github.com/0xdea/semgrep-rules/blob/main/c/ret-stack-address.yaml). Potential return of the address of a stack-allocated variable.
* [**putenv-stack-var**](https://github.com/0xdea/semgrep-rules/blob/main/c/putenv-stack-var.yaml). Call to putenv() with a stack-allocated variable.
* [**memory-address-exposure**](https://github.com/0xdea/semgrep-rules/blob/main/c/memory-address-exposure.yaml). Potential exposure of underlying memory addresses.
* [**mismatched-memory-management**](https://github.com/0xdea/semgrep-rules/blob/main/c/mismatched-memory-management.yaml). Potentially mismatched C memory management routines.
* [**mismatched-memory-management-cpp**](https://github.com/0xdea/semgrep-rules/blob/main/c/mismatched-memory-management-cpp.yaml). Potentially mismatched C++ memory management routines.

### command injection
* [**command-injection**](https://github.com/0xdea/semgrep-rules/blob/main/c/command-injection.yaml). Potential OS command injection via system() or popen().

### race conditions
* [**insecure-api-access-stat-lstat**](https://github.com/0xdea/semgrep-rules/blob/main/c/insecure-api-access-stat-lstat.yaml). Use of insecure API functions access(), stat(), lstat().
* [**insecure-api-mktemp-tmpnam-tempnam**](https://github.com/0xdea/semgrep-rules/blob/main/c/insecure-api-mktemp-tmpnam-tempnam.yaml). Use of insecure API functions mktemp(), tmpnam(), tempnam().
* [**insecure-api-signal**](https://github.com/0xdea/semgrep-rules/blob/main/c/insecure-api-signal.yaml). Use of insecure API function signal().

### privilege management
* [**incorrect-order-setuid-setgid-etc**](https://github.com/0xdea/semgrep-rules/blob/main/c/incorrect-order-setuid-setgid-etc.yaml). Privilege management functions called in the wrong order.
* [**unchecked-ret-setuid-seteuid**](https://github.com/0xdea/semgrep-rules/blob/main/c/unchecked-ret-setuid-seteuid.yaml). Unchecked return code of setuid() and seteuid().

### miscellaneous
* [**incorrect-use-of-memset**](https://github.com/0xdea/semgrep-rules/blob/main/c/incorrect-use-of-memset.yaml). Wrong order of arguments to memset().
* [**insecure-api-rand-srand**](https://github.com/0xdea/semgrep-rules/blob/main/c/insecure-api-rand-srand.yaml). Use of potentially insecure API functions rand() and srand().
* [**incorrect-use-of-sprintf-snprintf**](https://github.com/0xdea/semgrep-rules/blob/main/c/incorrect-use-of-sprintf-snprintf.yaml). Source and destination overlap in sprintf() and snprintf().
* [**suspicious-assert**](https://github.com/0xdea/semgrep-rules/blob/main/c/suspicious-assert.yaml). Potentially invalid size check due to use of assertion macros.
* [**interesting-api-calls**](https://github.com/0xdea/semgrep-rules/blob/main/c/interesting-api-calls.yaml). Calls to interesting and potentially insecure API functions.
* [**unchecked-ret-scanf-etc**](https://github.com/0xdea/semgrep-rules/blob/main/c/unchecked-ret-scanf-etc.yaml). Unchecked return code of functions in the scanf() family.
* [**insecure-api-atoi-atol-atof**](https://github.com/0xdea/semgrep-rules/blob/main/c/insecure-api-atoi-atol-atof.yaml). Use of potentially insecure API functions atoi(), atol(), atof().
* [**argv-envp-access**](https://github.com/0xdea/semgrep-rules/blob/main/c/argv-envp-access.yaml). Command-line argument or environment variable access.
* [**missing-default-in-switch**](https://github.com/0xdea/semgrep-rules/blob/main/c/missing-default-in-switch.yaml). Missing default case in a switch statement.
* [**missing-break-in-switch**](https://github.com/0xdea/semgrep-rules/blob/main/c/missing-break-in-switch.yaml). Missing break or equivalent in a switch statement.
* [**missing-return**](https://github.com/0xdea/semgrep-rules/blob/main/c/missing-return.yaml). Missing return statement in non-void function.
* [**typos**](https://github.com/0xdea/semgrep-rules/blob/main/c/typos.yaml). Potential typos with security implications.

## Generic

### miscellaneous
* [**bad-words**](https://github.com/0xdea/semgrep-rules/blob/main/generic/bad-words.yaml). Keywords and comments that suggest the presence of bugs.
