<div align="center">
<pre>
███╗   ███╗███████╗██╗  ████████╗██████╗ ██╗██╗  ██╗
████╗ ████║██╔════╝██║  ╚══██╔══╝██╔══██╗██║╚██╗██╔╝
██╔████╔██║█████╗  ██║     ██║   ██████╔╝██║ ╚███╔╝ 
██║╚██╔╝██║██╔══╝  ██║     ██║   ██╔══██╗██║ ██╔██╗ 
██║ ╚═╝ ██║███████╗███████╗██║   ██║  ██║██║██╔╝ ██╗
╚═╝     ╚═╝╚══════╝╚══════╝╚═╝   ╚═╝  ╚═╝╚═╝╚═╝  ╚═╝
---
A simple and templated C++ Matrix library 
</pre>

![Static Badge](https://img.shields.io/badge/Language-C%2B%2B%2017-purple)
![GitHub](https://img.shields.io/github/license/ErykMajoch/Meltrix?style=flat&label=License&color=purple) ![GitHub code size in bytes](https://img.shields.io/github/languages/code-size/ErykMajoch/Meltrix?label=Library%20Size&color=purple)

[//]: # (![GitHub Workflow Status &#40;with event&#41;]&#40;https://img.shields.io/github/actions/workflow/status/ErykMajoch/Meltrix/cmake-multi-platform.yml?label=Build&#41;)

</div>

## Introduction

Meltrix is a library written in C++ that provides tools for matrix operations. It is designed to be easy to use and to
provide a wide range of functionalities, with the ability to extend it as the user pleases.

## Code Examples

> TODO!

## Installation

### Locally

1. Clone the repository

```bash
git clone https://github.com/ErykMajoch/Meltrix.git
```

2. Install the library using Conan

```bash
cd Meltrix/
conan install .
```

3. Include the library in your projects `conanfile.txt`:

```cfg
[requires]
meltrix/0.0.0
[generators]
CMakeDeps
CMakeToolchain
[layout]
cmake_layout
```
