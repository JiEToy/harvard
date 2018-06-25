# Questions

## What's `stdint.h`?

The library in which the different integer types are defined

## What's the point of using `uint8_t`, `uint32_t`, `int32_t`, and `uint16_t` in a program?

These types are an exact size, which means the programm doesn't need to figure out how long each instance is, because they are always the same length.

## How many bytes is a `BYTE`, a `DWORD`, a `LONG`, and a `WORD`, respectively?

BYTE is exactly 1 byte (8 bits), DWORD and LONG are 4 bytes (32 bits), WORD is 2 bytes (16 bits)

## What (in ASCII, decimal, or hexadecimal) must the first two bytes of any BMP file be? Leading bytes used to identify file formats (with high probability) are generally called "magic numbers."

BM in ASCII or 424D in hexadecimal

## What's the difference between `bfSize` and `biSize`?

BfSize tells how large the file is, while biSize tells how large the image is.

## What does it mean if `biHeight` is negative?

biHeight tells us how high the image is in pixels, but counted from row 0. So if positive, every row it counts stacks on top, while a negative value of biHeight means the rows are added in below 0. Therefore, the image starts in the
top left corner when biHeight is negative, instead of in the bottom left corner.

## What field in `BITMAPINFOHEADER` specifies the BMP's color depth (i.e., bits per pixel)?

biBitCount

## Why might `fopen` return `NULL` in lines 24 and 32 of `copy.c`?

Line 24: If no file can be found that matches the input
Line 32: If the output file cannot be found for some reason

## Why is the third argument to `fread` always `1` in our code?

Because there is only 1 element we want to read each time

## What value does line 63 of `copy.c` assign to `padding` if `bi.biWidth` is `3`?

3

## What does `fseek` do?

It finds a position in a file, and basically moves the cursor there.

## What is `SEEK_CUR`?

The position of the cursor, in this case used as the starting point from where to move 'padding' number of bytes forward
