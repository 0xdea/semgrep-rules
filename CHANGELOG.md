# Changelog for semgrep-rules

All notable changes to this project are documented in this file.

The format is based on [Keep a Changelog](https://keepachangelog.com/en/1.1.0/),
and this project adheres to [Semantic Versioning](https://semver.org/spec/v2.0.0.html).

## [Unreleased]

### Changed

* Improve documentation.

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

* Historical, battle-tested stable release.

[unreleased]: https://github.com/0xdea/semgrep-rules/compare/v1.1.0...HEAD

[1.1.0]: https://github.com/0xdea/semgrep-rules/compare/v1.0.0...v1.1.0

[1.0.0]: https://github.com/0xdea/semgrep-rules/releases/tag/v1.0.0
