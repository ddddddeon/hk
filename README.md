# hk
A general-purpose C library, providing APIs for logging, strings, bitfields, stacks and OS commands.

*This code was written for my own personal use, and is not guaranteed to be secure, portable, robust or bug-free.*

The Makefile is hardcoded for building on linux-x86_64 platforms. Autotools are not yet leveraged in this project.

## Installation
```
git clone https://github.com/ddddddeon/hk.git
cd hk
make
sudo make install
make tests

```
## Includes

### Logging
`#include <hk/log.h>`

### Strings
`#include <hk/string.h>`

### Bitfields
`#include <hk/bit.h>`

### Stacks
`#include <hk/stack.h>`

### OS
`#include <hk/os.h>`

### Everything
`#include <hk/hk.h>`
