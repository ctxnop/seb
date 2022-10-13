#!/usr/bin/env sh

qemu-system-x86_64 \
    -accel kvm -cpu host -m 2048 -smp 4 \
    -drive if=pflash,format=raw,file=build/machine/bios/OVMF.fd \
    -drive file=fat:rw:build/machine/esp,format=raw \
    -net none
