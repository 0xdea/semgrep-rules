# semgrep-rules
[![](https://img.shields.io/github/stars/0xdea/semgrep-rules.svg?color=yellow)](https://github.com/0xdea/semgrep-rules)
[![](https://img.shields.io/github/forks/0xdea/semgrep-rules.svg?color=green)](https://github.com/0xdea/semgrep-rules)
[![](https://img.shields.io/github/watchers/0xdea/semgrep-rules.svg?color=red)](https://github.com/0xdea/semgrep-rules)
[![](https://img.shields.io/badge/license-MIT%20License-red.svg?color=lightgray)](https://opensource.org/licenses/MIT) 
[![](https://img.shields.io/badge/twitter-%400xdea-blue.svg)](https://twitter.com/0xdea)

> "Humans are more suited to recognize food than to keep large graphs in their head." 
> 
> -- @halvarflake

A collection of my Semgrep rules to facilitate vulnerability research.

Blog post: https://security.humanativaspa.it/semgrep-ruleset-for-c-c-vulnerability-research

See also: https://semgrep.dev/r

## C/C++

### buffer overflows
* [**insecure-api-gets**](https://github.com/0xdea/semgrep-rules/blob/main/c/insecure-api-gets.yaml). Use of the insecure API function gets().
* [**insecure-api-strcpy-stpcpy-strcat**](https://github.com/0xdea/semgrep-rules/blob/main/c/insecure-api-strcpy-stpcpy-strcat.yaml). Use of potentially insecure API functions strcpy(), stpcpy(), strcat().
* [**insecure-api-sprintf-vsprintf**](https://github.com/0xdea/semgrep-rules/blob/main/c/insecure-api-sprintf-vsprintf.yaml). Use of potentially insecure API functions sprintf() and vsprintf().
* [**insecure-api-scanf-etc**](https://github.com/0xdea/semgrep-rules/blob/main/c/insecure-api-scanf-etc.yaml). Use of potentially insecure API functions in the scanf() family.
* [**unterminated-string-strncpy-stpncpy**](https://github.com/0xdea/semgrep-rules/blob/main/c/unterminated-string-strncpy-stpncpy.yaml). Lack of explicit null-termination after strncpy() and stpncpy().
* [**incorrect-use-of-sizeof**](https://github.com/0xdea/semgrep-rules/blob/main/c/incorrect-use-of-sizeof.yaml). Accidental use of the sizeof() operator on a pointer instead of its target.
* [**off-by-one**](https://github.com/0xdea/semgrep-rules/blob/main/c/off-by-one.yaml). Potential off-by-one error.
* [**pointer-subtraction**](https://github.com/0xdea/semgrep-rules/blob/main/c/pointer-subtraction.yaml). Potential use of pointer subtraction to determine size.
* [**unsafe-ret-strlcpy-strlcat**](https://github.com/0xdea/semgrep-rules/blob/main/c/unsafe-ret-strlcpy-strlcat.yaml). Potentially unsafe use of the return value of strlcpy() and strlcat().
* [**unsafe-ret-snprintf-vsnprintf**](https://github.com/0xdea/semgrep-rules/blob/main/c/unsafe-ret-snprintf-vsnprintf.yaml). Potentially unsafe use of the return value of snprintf() and vsnprintf().
* [**write-into-stack-buffer**](https://github.com/0xdea/semgrep-rules/blob/main/c/write-into-stack-buffer.yaml). Direct writes into buffers allocated on the stack.

### integer overflows
* [**incorrect-unsigned-comparison**](https://github.com/0xdea/semgrep-rules/blob/main/c/incorrect-unsigned-comparison.yaml). Checking if an unsigned variable is negative.
* [**signed-unsigned-conversion**](https://github.com/0xdea/semgrep-rules/blob/main/c/signed-unsigned-conversion.yaml). Potential signed/unsigned conversion errors.
* [**integer-truncation**](https://github.com/0xdea/semgrep-rules/blob/main/c/integer-truncation.yaml). Potential integer truncation errors.
* [**integer-wraparound**](https://github.com/0xdea/semgrep-rules/blob/main/c/integer-wraparound.yaml). Potential integer wraparound errors.
* [**unsafe-strlen**](https://github.com/0xdea/semgrep-rules/blob/main/c/unsafe-strlen.yaml). Casting the return value of strlen() to short might be dangerous.

### format strings
* [**format-string-bugs**](https://github.com/0xdea/semgrep-rules/blob/main/c/format-string-bugs.yaml). Potential format string bugs.

### memory management
* [**insecure-api-alloca**](https://github.com/0xdea/semgrep-rules/blob/main/c/insecure-api-alloca.yaml). Use of the potentially insecure API function alloca().
* [**use-after-free**](https://github.com/0xdea/semgrep-rules/blob/main/c/use-after-free.yaml). Potential use after free().
* [**double-free**](https://github.com/0xdea/semgrep-rules/blob/main/c/double-free.yaml). Potential double free().
* [**unchecked-ret-malloc-calloc-realloc**](https://github.com/0xdea/semgrep-rules/blob/main/c/unchecked-ret-malloc-calloc-realloc.yaml). Unchecked return code of malloc(), calloc(), realloc().
* [**ret-stack-address**](https://github.com/0xdea/semgrep-rules/blob/main/c/ret-stack-address.yaml). Potential return of the address of a stack variable.
* [**memory-address-exposure**](https://github.com/0xdea/semgrep-rules/blob/main/c/memory-address-exposure.yaml). Potential exposure of underlying memory addresses.
* [**mismatched-memory-management**](https://github.com/0xdea/semgrep-rules/blob/main/c/mismatched-memory-management.yaml). Potentially mismatched C memory management routines.
* [**mismatched-memory-management-cpp**](https://github.com/0xdea/semgrep-rules/blob/main/c/mismatched-memory-management-cpp.yaml). Potentially mismatched C++ memory management routines.

### command injection
* [**command-injection**](https://github.com/0xdea/semgrep-rules/blob/main/c/command-injection.yaml). Potential OS command injection via system() or popen().

### race conditions
* [**insecure-api-access-stat-lstat**](https://github.com/0xdea/semgrep-rules/blob/main/c/insecure-api-access-stat-lstat.yaml). Use of insecure API functions access(), stat(), lstat().
* [**insecure-api-mktemp-tmpnam-tempnam**](https://github.com/0xdea/semgrep-rules/blob/main/c/insecure-api-mktemp-tmpnam-tempnam.yaml). Use of insecure API functions mktemp(), tmpnam(), tempnam().

### privilege management
* [**incorrect-order-setuid-setgid-etc**](https://github.com/0xdea/semgrep-rules/blob/main/c/incorrect-order-setuid-setgid-etc.yaml). Privilege management functions called in the wrong order.
* [**unchecked-ret-setuid-seteuid**](https://github.com/0xdea/semgrep-rules/blob/main/c/unchecked-ret-setuid-seteuid.yaml). Unchecked return code of setuid() and seteuid().

### miscellaneous
* [**interesting-api-calls**](https://github.com/0xdea/semgrep-rules/blob/main/c/interesting-api-calls.yaml). Calls to interesting and potentially insecure API functions.
* [**typos**](https://github.com/0xdea/semgrep-rules/blob/main/c/typos.yaml). Potential typos with security implications.

## Generic

### miscellaneous
* [**bad-words**](https://github.com/0xdea/semgrep-rules/blob/main/generic/bad-words.yaml). Keywords and comments that suggest the presence of bugs.
