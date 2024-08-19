## Termode

Header-only library to easily manage terminal mode (non-blocking I/O, canonical/non-canonical mode)

```c
#define TERMODE_IMPLEMENTATION
#include <termode.h>
```
#### Non-blocking

```c 
// Default
termode_nonblocking(NONBLOCKING_OFF);

// Doesn't interrupt the program, but it still has to wait for the Enter key to process the input
termode_nonblocking(NONBLOCKING_ON);
```
#### Canonical mode

```c
// Default
termode_canonical(CANONICAL_ON);

// Doesn't interrupt the program and don't have to wait for the Enter key to process the input
termode_canonical(CANONICAL_OFF);
```
#### Echo

```c
termode_echo(ECHO_ON);
termode_echo(ECHO_OFF); 

// Basically, if you want the terminal to show characters when you type, use ECHO_ON
// Otherwise, if you want to hide the input from the screen, use ECHO_OFF
```
