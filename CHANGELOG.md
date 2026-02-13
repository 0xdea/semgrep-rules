# Changelog for semgrep-rules

All notable changes to this project are documented in this file.

The format is based on [Keep a Changelog](https://keepachangelog.com/en/1.1.0/),
and this project adheres to [Semantic Versioning](https://semver.org/spec/v2.0.0.html).

## [Unreleased]

### Added

* Add C++ `this` and function call patterns to `incorrect-use-of-sizeof`.
* Add detections for `confstr`, `ttyname_r/ptsname_r`, `strfind/strrspn/strtrns`, `readlinkat`, `fgetws/fgetws_l`, `*cftime`, `chdir`, `chroot`, `copylist`, `dbminit`, `fattach`, `ftw`, `truncate`, `umask/ulimit`, `cdev_init`, `inet_*`, `utmp*`, `OemToCharW`, `mbs/wcs`, `*spawn*`, `CreateProcess*`, and missing `get*` family functions (`interesting-api-calls`).
* Add detections for some Microsoft-specific functions (`interesting-api-calls`).
* Add detections for missing `str*` family functions (`insecure-api-strcpy-strcat`, `interesting-api-calls`, `overlapping-src-dst`, `write-into-stack-buffer`).
* Add detections for `mempcpy` and `wmempcpy` (`use-of-source-size-in-copy`, `interesting-api-calls`, `overlapping-src-dst`, `signed-unsigned-conversion`, `write-into-stack-buffer`).
* Add detections for `swprintf` and `vswprintf` (`signed-insigned-conversion`, `write-into-stack-buffer`).
* Add detection for `p2open` and `wordexp` (`command-injection`, `interesting-api-calls`).
* Add detections for `faccessat`, `faccessat2`, and `fstatat` (`insecure-api-access-stat`, `interesting-api-calls`).
* Add detections for `rand48` family functions (`insecure-api-rand-srand`, `interesting-api-calls`).
* Add detections for `syslog` and `err/warn` function families (`memory-address-exposure`).
* Add detections for missing `signal` family functions (`insecure-api-signal`, `interesting-api-calls`).
* Add detection for `tmpnam_r` (`insecure-api-mktemp-tmpnam-tempnam`, `interesting-api-calls`).
* Add detection for `VirtualAlloc` (`integer-wraparound`).
* Add some code samples (`command-injection`, `format-string-bugs`, `incorrect-use-of-sizeof`, `insecure-api-access-stat`, `insecure-api-gets`, `insecure-api-scanf`, `insecure-api-sprintf-vsprintf`, `off-by-one`, `unsafe-ret-snprintf-vsnprintf`, `use-of-source-size-in-copy`, `unterminated-string-strncpy`).

### Changed

* Extend `*s*printf` pattern matching (`interesting-api-calls`).
* Improve matching of array creation patterns (`incorrect-use-of-free`, `putenv-stack-var`, `ret-stack-address`, `write-into-stack-buffer`).
* Improve matching of array creation and length calculation (`off-by-one`).
* Exclude string literals as source (`insecure-api-scanf`).
* Add detections for `snprintf` family functions and improve pattern matching (`use-of-source-size-in-copy`).
* Replace the pattern `= $_;` with `= ...;` everywhere.
* Rename `incorrect-order-setuid-setgid-etc` into `incorrect-order-setuid-setgid`.
* Rename `incorrect-use-of-strncpy-memcpy-etc` into `use-of-source-size-in-copy`.
* Rename `insecure-api-scanf-etc` into `insecure-api-scanf`.
* Rename `unchecked-ret-scanf-etc` into `unchecked-ret-scanf`.
* Rename `insecure-api-strcpy-stpcpy-strcat` into `insecure-api-strcpy-strcat`.
* Rename `unterminated-string-strncpy-stpncpy` into `unterminated-string-strncpy`.
* Rename `unchecked-ret-malloc-calloc-realloc` into `unchecked-ret-malloc`.
* Rename `insecure-api-access-stat-lstat` into `insecure-api-access-stat`.
* Improve documentation.
* Update SARIF output example.

## [1.1.0] - 2025-12-03

### Added

* Add `high-entropy-assignment` and `regex-dos` rules that use the new [metavariable-analysis](https://semgrep.dev/docs/writing-rules/metavariable-analysis) feature.
* Add detections for the `__iso99_*scanf` function family (`format-string-bugs`, `insecure-api-scanf`, `unchecked-ret-scanf`).
* Add detections for the `_mb*` and `*_s/*_l` function families (`insecure-api-strcpy-stpcpy-strcat`, `interesting-api-calls`, `unsafe-ret-strlcpy-strlcat`, `unsafe-strlen`, `unterminated-string-strncpy-stpncpy`, `write-into-stack-buffer`).
* Add some code samples (`incorrect-use-of-strncpy-memcpy-etc`, `integer-wraparound`, `overlapping-src-dst`).
* Add SARIF output example as [requested](https://github.com/0xdea/semgrep-rules/issues/10).
* Add GitHub action to automate rule validation and testing.

### Changed

* Rename `incorrect-use-of-strncpy-stpncpy-strlcpy` into `incorrect-use-of-strncpy-memcpy` and add matching of `memcpy` and its main variants.
* Rename `incorrect-use-of-sprintf-snprintf` into `overlapping-src-dst` and add matching of other copy functions.
* Exclude length known at compile time from `memcpy` matches (`interesting-api-calls`).
* Explicitly exclude `$_ = 0` assignments to reduce false positives (`integer-truncation`, `signed-unsigned-conversion`).
* Refactor some rules to include other variants and improve readability and scalability (`unsafe-ret-snprintf-vsnprintf`, `unsafe-ret-strlcpy-strlcat`, `unsafe-strlen`).
* Implement case-insensitive matching (`interesting-api-calls`).
* Reduce false positives (`format-string-bugs`, `putenv-stack-var`, `ret-stack-address`, `unsafe-ret-snprintf-vsnprintf`, `write-into-stack-buffer`).
* Use the new [anonymous metavariables](https://semgrep.dev/products/product-updates/anonymous-metavariables/) feature where suitable.
* Optimize some patterns (`integer-truncation`, `integer-wraparound`, `mismatched-memory-management`, `mismatched-memory-management-cpp`, `off-by-one`, `write-into-stack-buffer`, `missing-return`).
* Change some confidence levels (`integer-truncation`, `integer-wraparound`, `putenv-stack-var`, `ret-stack-address`).
* Move rules into a dedicated folder.
* Improve documentation and code formatting.

### Removed

* Remove non-existent API functions (`insecure-api-strcpy-stpcpy-strcat`, `unterminated-string-strncpy-stpncpy`).

## [1.0.0] - 2025-09-26

Historical, battle-tested stable release.

[unreleased]: https://github.com/0xdea/semgrep-rules/compare/v1.1.0...HEAD

[1.1.0]: https://github.com/0xdea/semgrep-rules/compare/v1.0.0...v1.1.0

[1.0.0]: https://github.com/0xdea/semgrep-rules/releases/tag/v1.0.0
