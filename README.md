a benchmark comparing napi, napi-rs and ffast bindings overhead

## requirements

- Linux 6+, macos/darwin x64/arm64 12+
- node.js LTS+
- a C++ compiler capable of compiling node addons
- make
- Rust + Cargo
- npm

## build

```shell
make clean libs bench
```

## run

```shell
make bench
```
