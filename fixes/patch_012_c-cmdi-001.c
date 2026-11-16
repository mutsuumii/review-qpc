# Command injection via system()/popen()
# CWE-78 | Severity: CRITICAL
# File: ports/qube/qube.c line 248

**Risk:** system() and popen() invoke /bin/sh. Any unsanitized input in the command string gives full shell access.

**Fix:** Use execve() with explicit argv array. If shell features are needed, whitelist all arguments strictly.
