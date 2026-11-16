# Security audit: QuantumLeaps/qpc

Date: 2026-11-16 | Auditor: [mutsuumii](https://github.com/mutsuumii)

## Summary

Found 12 issue(s): 8 critical, 4 high.

## Findings

### 1. [CRITICAL] Buffer overflow via unsafe string function

**CWE-120** | `ports/win32/safe_std.h` line 83

strcpy/strcat/sprintf/gets without bounds checking. Stack or heap overflow leads to code execution.

```
strcat(dest_, src_)
```

**Fix:** Use strncpy, strncat, snprintf with explicit size. Null-terminate manually. Prefer strlcpy/strlcat where available.
---

### 2. [CRITICAL] Format string vulnerability

**CWE-134** | `ports/win32/safe_std.h` line 86

User-controlled string passed as printf format argument. Attacker reads stack memory or overwrites return addresses via %n.

```
snprintf(buf_, bufsiz_, format_, __VA_ARGS__)
```

**Fix:** Use a literal format string: printf("%s", user_input). Never pass user data as the format argument.
---

### 3. [CRITICAL] Buffer overflow via unsafe string function

**CWE-120** | `ports/win32-qv/safe_std.h` line 83

strcpy/strcat/sprintf/gets without bounds checking. Stack or heap overflow leads to code execution.

```
strcat(dest_, src_)
```

**Fix:** Use strncpy, strncat, snprintf with explicit size. Null-terminate manually. Prefer strlcpy/strlcat where available.
---

### 4. [CRITICAL] Format string vulnerability

**CWE-134** | `ports/win32-qv/safe_std.h` line 86

User-controlled string passed as printf format argument. Attacker reads stack memory or overwrites return addresses via %n.

```
snprintf(buf_, bufsiz_, format_, __VA_ARGS__)
```

**Fix:** Use a literal format string: printf("%s", user_input). Never pass user data as the format argument.
---

### 5. [HIGH] Missing NULL check after allocation

**CWE-476** | `ports/win32-qv/qwin_gui.c` line 208

Return value of malloc/realloc not checked for NULL. On allocation failure the program dereferences NULL, causing a crash or exploitable condition.

```
me->hSegment = (HWND *)calloc(segmentNum, sizeof(HWND));
```

**Fix:** Always check: ptr = malloc(n); if (!ptr) { handle_error(); return; }
---

### 6. [HIGH] Missing NULL check after allocation

**CWE-476** | `ports/win32-qv/qwin_gui.c` line 213

Return value of malloc/realloc not checked for NULL. On allocation failure the program dereferences NULL, causing a crash or exploitable condition.

```
me->hBitmap = (HBITMAP *)calloc(bitmapNum, sizeof(HBITMAP));
```

**Fix:** Always check: ptr = malloc(n); if (!ptr) { handle_error(); return; }
---

### 7. [CRITICAL] Buffer overflow via unsafe string function

**CWE-120** | `ports/qube/safe_std.h` line 83

strcpy/strcat/sprintf/gets without bounds checking. Stack or heap overflow leads to code execution.

```
strcat(dest_, src_)
```

**Fix:** Use strncpy, strncat, snprintf with explicit size. Null-terminate manually. Prefer strlcpy/strlcat where available.
---

### 8. [CRITICAL] Format string vulnerability

**CWE-134** | `ports/qube/safe_std.h` line 86

User-controlled string passed as printf format argument. Attacker reads stack memory or overwrites return addresses via %n.

```
snprintf(buf_, bufsiz_, format_, __VA_ARGS__)
```

**Fix:** Use a literal format string: printf("%s", user_input). Never pass user data as the format argument.
---

### 9. [HIGH] Missing NULL check after allocation

**CWE-476** | `ports/win32/qwin_gui.c` line 208

Return value of malloc/realloc not checked for NULL. On allocation failure the program dereferences NULL, causing a crash or exploitable condition.

```
me->hSegment = (HWND *)calloc(segmentNum, sizeof(HWND));
```

**Fix:** Always check: ptr = malloc(n); if (!ptr) { handle_error(); return; }
---

### 10. [HIGH] Missing NULL check after allocation

**CWE-476** | `ports/win32/qwin_gui.c` line 213

Return value of malloc/realloc not checked for NULL. On allocation failure the program dereferences NULL, causing a crash or exploitable condition.

```
me->hBitmap = (HBITMAP *)calloc(bitmapNum, sizeof(HBITMAP));
```

**Fix:** Always check: ptr = malloc(n); if (!ptr) { handle_error(); return; }
---

### 11. [CRITICAL] Format string vulnerability

**CWE-134** | `ports/posix/qf_port.c` line 379

User-controlled string passed as printf format argument. Attacker reads stack memory or overwrites return addresses via %n.

```
//printf("param.sched_priority==%d\n", param.sched_priority);
```

**Fix:** Use a literal format string: printf("%s", user_input). Never pass user data as the format argument.
---

### 12. [CRITICAL] Command injection via system()/popen()

**CWE-78** | `ports/qube/qube.c` line 248

system() and popen() invoke /bin/sh. Any unsanitized input in the command string gives full shell access.

```
system("color"); // to support color output
```

**Fix:** Use execve() with explicit argv array. If shell features are needed, whitelist all arguments strictly.
---
