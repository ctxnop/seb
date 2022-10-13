# Simple EFI Bootloader

A simple EFI bootloader written in C++ and `cmake`.

## Motivations

Provides a scaffolding for an EFI bootloader. All examples found so far are
written in C and use basic `Makefile`, this is why this project do things
differently.

## Prerequisites

This project currently needs:

- `clang`: GCC may be supported later, but for now, only `clang` is supported.
- `gnu-efi`: It actually doesn't requires it, but only the efi headers, which
are provided by it or by other means.

## Compilation

```sh
[user@host ~/]$ git clone git@github.com:ctxnop/seb.git
[user@host ~/]$ CXX=clang++ cmake -S seb -B seb/build
[user@host ~/]$ cmake --build seb/build
```

To also build a qemu's virtual machine, you also can type

```sh
[user@host ~/]$ cmake --build seb/build --target machine
```

Use the `start-qemu.sh` script to launch it:
```sh
[user@host ~/seb]$ ./start-qemu.sh
```
