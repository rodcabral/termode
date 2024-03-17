## Termode

Handle terminal non-blocking I/O and canonical/non-canonical mode more easily (header-only)

The terminal default behavior is blocking I/O and canonical mode. This means that if you have a loop in your program and need user input, your program will stop until the Enter key is pressed.

```c
#include <termode.h>
```
#### Non-blocking

```c 
// Default
termode_nonblocking(NONBLOCKING_OFF);

// It doesn't interrupt the program, but it still has to wait for the Enter key to process the input
termode_nonblocking(NONBLOCKING_ON);
```
#### Canonical mode

```c
// Default
termode_canonical(CANONICAL_ON);

// It doesn't interrupt the program and you don't have to wait for the Enter key to process the input
termode_canonical(CANONICAL_OFF);
```
#### Echo

```c
termode_echo(ECHO_ON);
termode_echo(ECHO_OFF); 

// Basically, if you want the terminal to show characters when you type, use ECHO_ON
// Otherwise, if you want to hide the input from the screen, use ECHO_OFF
```