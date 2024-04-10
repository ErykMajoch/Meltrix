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

![Static Badge](https://img.shields.io/badge/C%2B%2B-17-purple?style=flat-square)
![GitHub License](https://img.shields.io/github/license/ErykMajoch/Meltrix?style=flat-square&label=License&color=purple)
![GitHub code size in bytes](https://img.shields.io/github/languages/code-size/ErykMajoch/Meltrix?style=flat-square&label=Library%20Size&color=purple)
![GitHub Actions Workflow Status](https://img.shields.io/github/actions/workflow/status/ErykMajoch/Meltrix/.github%2Fworkflows%2FCMakeBuild.yml?style=flat-square&label=Build)

</div>

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
meltrix/0.1.3
[generators]
CMakeDeps
CMakeToolchain
[layout]
cmake_layout
```
