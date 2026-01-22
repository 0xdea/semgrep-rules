void f() {
    char src[512];
    char dest[256];

    // `sizeof(dest)` is wrong but will be caught by another rule
    // ok: snprintf-source-size
    snprintf(dest, sizeof(dest), "value=%s\n", src);
    // ok: snprintf-source-size
    snprintf(dest, sizeof(dest), "value=%s\n", src);
}

void f() {
    char src[512];
    char dest[256];

    // ruleid: snprintf-source-size
    snprintf(dest, sizeof(src), src);

    // ruleid: snprintf-source-size
    snprintf(dest, sizeof(src), "value=%s\n", src);

    // ruleid: snprintf-source-size
    snprintf(dest, sizeof(src), "value%s%s\n", "=", src);

    // ruleid: snprintf-source-size
    snprintf(dest, sizeof(src), "value%s%s%s", "=", src, "\n");
}

void f() {
    char src[512];
    char dest[256];

    // ok: snprintf-source-size
    snprintf(dest, sizeof(dest), src);

    // ok: snprintf-source-size
    snprintf(dest, sizeof(dest), "value=%s\n", src);

    // ok: snprintf-source-size
    snprintf(dest, sizeof(dest), "value%s%s\n", "=", src);

    // ok: snprintf-source-size
    snprintf(dest, sizeof(dest), "value%s%s%s", "=", src, "\n");
}

void f() {
    char src[512];
    char dest[256];

    // ruleid: snprintf-source-size
    snprintf(dest, sizeof(src) - 1, "value=%s\n", src);
}

void f() {
    char src[512];
    char dest[256];

    // ruleid: snprintf-source-size
    snprintf(dest, sizeof(src) - 1, src);

    // ruleid: snprintf-source-size
    snprintf(dest, sizeof(src) - 1, "value=%s\n", src);

    // ruleid: snprintf-source-size
    snprintf(dest, sizeof(src) - 1, "value%s%s\n", "=", src);

    // ruleid: snprintf-source-size
    snprintf(dest, sizeof(src) - 1, "value%s%s%s", "=", src, "\n");
}

void f() {
    char src[16];
    char dest[256];

    // `sizeof(src)` is less than `sizeof(dest)` so this is safe
    // todook: snprintf-source-size
    snprintf(dest, sizeof(src), "value = %s\n", src);
}

