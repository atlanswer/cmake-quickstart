# cmake-quickstart

This is a CMake template.

## Usage

### Update submodules

```sh
git submodule update --init --recursive
```

### Configure

```sh
~/package $ cmake -G Ninja -S . -B build
```

### Build

```sh
~/package $ cmake --build build
```

### Install

```sh
~/package $ cmake --install build
```
