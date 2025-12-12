# semgrep-rules

[![](https://img.shields.io/github/stars/0xdea/semgrep-rules.svg?style=flat&color=yellow)](https://github.com/0xdea/semgrep-rules)
[![](https://img.shields.io/github/forks/0xdea/semgrep-rules.svg?style=flat&color=green)](https://github.com/0xdea/semgrep-rules)
[![](https://img.shields.io/github/watchers/0xdea/semgrep-rules.svg?style=flat&color=red)](https://github.com/0xdea/semgrep-rules)
[![](https://img.shields.io/badge/twitter-%400xdea-blue.svg)](https://twitter.com/0xdea)
[![](https://img.shields.io/badge/mastodon-%40raptor-purple.svg)](https://infosec.exchange/@raptor)
[![test](https://github.com/0xdea/semgrep-rules/actions/workflows/test.yml/badge.svg)](https://github.com/0xdea/semgrep-rules/actions/workflows/test.yml)

> "The attack surface is the vulnerability. Finding a bug there is just a detail."
>
> -- Mark Dowd

> "Some details are more important than others."
>
> -- Fedor G. Pikus

A collection of my Semgrep rules to facilitate vulnerability research.

[![Program in C](https://img.youtube.com/vi/tas0O586t80/maxresdefault.jpg)](https://www.youtube.com/embed/tas0O586t80)

## Blog posts

* <https://hnsecurity.it/blog/semgrep-ruleset-for-c-c-vulnerability-research>
* <https://hnsecurity.it/blog/automating-binary-vulnerability-discovery-with-ghidra-and-semgrep>
* <https://hnsecurity.it/blog/big-update-to-my-semgrep-c-cpp-ruleset>
* <https://hnsecurity.it/blog/streamlining-vulnerability-research-with-the-idalib-rust-bindings-for-ida-9-2/>

## See also

* <https://semgrep.dev/r>

## Setup and usage instructions

1. Install [Semgrep](https://semgrep.dev/docs/getting-started/).
2. Clone this GitHub repo.
3. To use these rules, run:

```sh
# high priority scan (quick wins)
semgrep --severity ERROR --config semgrep-rules/rules /path/to/source
# high and medium priority scan (recommended)
semgrep --severity ERROR --severity WARNING --config semgrep-rules/rules /path/to/source
# full scan (might include marginal findings and more false positives)
semgrep --config semgrep-rules/rules /path/to/source
```

*Note: Specify the `--no-git-ignore` switch to scan files regardless of git tracking status or `.gitignore` rules.*

For a better streamlined experience, I recommend saving Semgrep scan output in [SARIF](https://sarifweb.azurewebsites.net/) format and using [SARIF Explorer](https://marketplace.visualstudio.com/items?itemName=trailofbits.sarif-explorer) in [VS code](https://code.visualstudio.com/):

```sh
semgrep --sarif --sarif-output=/path/to/source/SEMGREP.sarif --config semgrep-rules/rules /path/to/source
code /path/to/source # then open the SEMGREP.sarif file in VS code with SARIF Explorer 
```

See also the included SARIF output [example](sarif-example).

## Compatibility

* Tested with Semgrep CLI 1.145.0

## Rules

### C/C++

#### buffer overflows

* [**insecure-api-gets**](rules/c/insecure-api-gets.yaml). Use of the insecure API function `gets`.
* [**insecure-api-strcpy-stpcpy-strcat**](rules/c/insecure-api-strcpy-stpcpy-strcat.yaml). Use of potentially insecure API functions `strcpy`, `stpcpy`, `strcat`.
* [**insecure-api-sprintf-vsprintf**](rules/c/insecure-api-sprintf-vsprintf.yaml). Use of potentially insecure API functions `sprintf` and `vsprintf`.
* [**insecure-api-scanf-etc**](rules/c/insecure-api-scanf-etc.yaml). Use of potentially insecure API functions in the `scanf` family.
* [**incorrect-use-of-strncat**](rules/c/incorrect-use-of-strncat.yaml). Wrong size argument passed to `strncat`.
* [**incorrect-use-of-strncpy-memcpy-etc**](rules/c/incorrect-use-of-strncpy-memcpy-etc.yaml). Wrong size argument passed to `strncpy`, `memcpy`, and variants.
* [**incorrect-use-of-sizeof**](rules/c/incorrect-use-of-sizeof.yaml). Accidental use of the `sizeof` operator on a pointer instead of its target.
* [**unterminated-string-strncpy-stpncpy**](rules/c/unterminated-string-strncpy-stpncpy.yaml). Lack of explicit NUL-termination after `strncpy` and `stpncpy`.
* [**off-by-one**](rules/c/off-by-one.yaml). Potential off-by-one error.
* [**pointer-subtraction**](rules/c/pointer-subtraction.yaml). Potential use of pointer subtraction to determine size.
* [**unsafe-ret-snprintf-vsnprintf**](rules/c/unsafe-ret-snprintf-vsnprintf.yaml). Potentially unsafe use of the return value of `snprintf` and `vsnprintf`.
* [**unsafe-ret-strlcpy-strlcat**](rules/c/unsafe-ret-strlcpy-strlcat.yaml). Potentially unsafe use of the return value of `strlcpy` and `strlcat`.
* [**write-into-stack-buffer**](rules/c/write-into-stack-buffer.yaml). Direct write into buffer allocated on the stack.

#### integer overflows

* [**incorrect-unsigned-comparison**](rules/c/incorrect-unsigned-comparison.yaml). Checking if an unsigned variable is negative.
* [**unsafe-strlen**](rules/c/unsafe-strlen.yaml). Casting the return value of `strlen` to short might be dangerous.
* [**integer-wraparound**](rules/c/integer-wraparound.yaml). Potential integer wraparound errors.
* [**integer-truncation**](rules/c/integer-truncation.yaml). Potential integer truncation errors.
* [**signed-unsigned-conversion**](rules/c/signed-unsigned-conversion.yaml). Potential signed/unsigned conversion errors.

#### format strings

* [**format-string-bugs**](rules/c/format-string-bugs.yaml). Potential format string bugs.

#### memory management

* [**insecure-api-alloca**](rules/c/insecure-api-alloca.yaml). Use of the potentially insecure API function `alloca`.
* [**use-after-free**](rules/c/use-after-free.yaml). Potential use after `free`.
* [**double-free**](rules/c/double-free.yaml). Potential double `free`.
* [**incorrect-use-of-free**](rules/c/incorrect-use-of-free.yaml). Calling `free` on memory not in the heap.
* [**unchecked-ret-malloc-calloc-realloc**](rules/c/unchecked-ret-malloc-calloc-realloc.yaml). Unchecked return code of `malloc`, `calloc`, `realloc`.
* [**ret-stack-address**](rules/c/ret-stack-address.yaml). Potential return of the address of a stack-allocated variable.
* [**putenv-stack-var**](rules/c/putenv-stack-var.yaml). Call to `putenv` with a stack-allocated variable.
* [**memory-address-exposure**](rules/c/memory-address-exposure.yaml). Potential exposure of underlying memory addresses.
* [**mismatched-memory-management**](rules/c/mismatched-memory-management.yaml). Potentially mismatched C memory management routines.
* [**mismatched-memory-management-cpp**](rules/c/mismatched-memory-management-cpp.yaml). Potentially mismatched C++ memory management routines.

#### command injection

* [**command-injection**](rules/c/command-injection.yaml). Potential OS command injection via `system` or `popen`.

#### race conditions

* [**insecure-api-access-stat-lstat**](rules/c/insecure-api-access-stat-lstat.yaml). Use of insecure API functions `access`, `stat`, `lstat`.
* [**insecure-api-mktemp-tmpnam-tempnam**](rules/c/insecure-api-mktemp-tmpnam-tempnam.yaml). Use of insecure API functions `mktemp`, `tmpnam`, `tempnam`.
* [**insecure-api-signal**](rules/c/insecure-api-signal.yaml). Use of insecure API function `signal`.

#### privilege management

* [**incorrect-order-setuid-setgid-etc**](rules/c/incorrect-order-setuid-setgid-etc.yaml). Privilege management functions called in the wrong order.
* [**unchecked-ret-setuid-seteuid**](rules/c/unchecked-ret-setuid-seteuid.yaml). Unchecked return code of `setuid` and `seteuid`.

#### denial of service

* [**regex-dos**](rules/c/regex-dos.yaml). Regular expression that may exhibit exponential runtime and lead to ReDoS.

#### miscellaneous

* [**incorrect-use-of-memset**](rules/c/incorrect-use-of-memset.yaml). Wrong order of arguments to `memset`.
* [**insecure-api-rand-srand**](rules/c/insecure-api-rand-srand.yaml). Use of potentially insecure API functions `rand` and `srand`.
* [**overlapping-src-dst**](rules/c/overlapping-src-dst.yaml). Source and destination overlap in copy functions.
* [**suspicious-assert**](rules/c/suspicious-assert.yaml). Potentially invalid size check due to use of assertion macros.
* [**interesting-api-calls**](rules/c/interesting-api-calls.yaml). Calls to interesting and potentially insecure API functions.
* [**unchecked-ret-scanf-etc**](rules/c/unchecked-ret-scanf-etc.yaml). Unchecked return code of functions in the `scanf` family.
* [**insecure-api-atoi-atol-atof**](rules/c/insecure-api-atoi-atol-atof.yaml). Use of potentially insecure API functions `atoi`, `atol`, `atof`.
* [**high-entropy-assignment**](rules/c/high-entropy-assignment.yaml). Assignment of a high-entropy value that might be a secret.
* [**argv-envp-access**](rules/c/argv-envp-access.yaml). Command-line argument or environment variable access.
* [**missing-default-in-switch**](rules/c/missing-default-in-switch.yaml). Missing default case in a switch statement.
* [**missing-break-in-switch**](rules/c/missing-break-in-switch.yaml). Missing break or equivalent in a switch statement.
* [**missing-return**](rules/c/missing-return.yaml). Missing return statement in non-void function.
* [**typos**](rules/c/typos.yaml). Potential typos with security implications.

### Generic

#### miscellaneous

* [**bad-words**](rules/generic/bad-words.yaml). Keywords and comments that suggest the presence of bugs.

## Changelog

* [CHANGELOG.md](CHANGELOG.md)

## TODO

* Improve overall **accuracy** and reduce false positives, without missing potential hot spots in code.
* Add **new checks** to the existing rules and add new rules where needed.
* Additional `--time` **benchmarking** against real-world code to spot slow rules in need of optimization.
* Move **noisy rules** (e.g., `high-entropy-assignment`) to a specific folder to simplify publishing to the Semgrep registry.
* Extensive **testing** before release v1.2.0 (or even v2.0.0) and publishing to the official **Semgrep registry**.
* Add scripts to clean up pseudocode generated by [common decompilers](https://github.com/0xdea/semgrep-rules/issues/12) to improve Semgrep parsing.
* Port the rules to the [Semgrep pro engine](https://semgrep.dev/docs/semgrep-code/semgrep-pro-engine-intro), which allows for **inter-file** and **inter-function** analysis.
* Implement [taint mode](https://semgrep.dev/docs/writing-rules/data-flow/taint-mode/overview) where suitable to improve rules with **dataflow analysis**.
* Investigate [symbolic propagation](https://semgrep.dev/docs/writing-rules/experiments/symbolic-propagation) that might be useful to reduce some **false positives**.
* Implement a Semgrep **wrapper and post-processor** as described in [this research](https://parsiya.net/blog/semgrep-fun/).
* Implement dedicated **kernel rules** (Linux, BSD, macOS, etc.).
* Implement dedicated C++ rules and move them in another folder separated from the one for C rules.
