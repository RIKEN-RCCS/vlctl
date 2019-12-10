# vlctl

vlctl is a utility program for ARMv8-A architecture with Scalable Vector Extension (SVE).
vlctl enables to execute a command with a specified SVE vector length.

## Usage

    vlctl <length> command [ args ... ]

`<length>` is a vector length in bits.
For Fugaku, it can be 128 | 256 | 512.

## Reference

* [Scalable Vector Extension support for AArch64 Linux](https://www.kernel.org/doc/Documentation/arm64/sve.txt)
