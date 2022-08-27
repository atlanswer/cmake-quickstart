# cmake-quickstart

This is a CMake template.

## Usage

### Update submodules

```sh
git submodule update --init --recursive
```

### Configure

```sh
~/package $ cmake -S . -B build --preset <preset>
```

### Build

```sh
~/package $ cmake --build --preset <preset>
```

### Test

```sh
~/package $ ctest --preset <preset>
```

### Install

```sh
~/package $ cmake --install build
```
