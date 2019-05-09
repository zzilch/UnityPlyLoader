UnityPlyLoader
===

[![license](http://img.shields.io/badge/license-MIT-blue.svg)](https://github.com/warmtrue/WDataTable/LICENSE)
[![release](https://img.shields.io/badge/release-v1.0.0-blue.svg)](https://github.com/warmtrue/WDataTable/releases)
[![PRs Welcome](https://img.shields.io/badge/PRs-welcome-blue.svg)](https://github.com/warmtrue/WDataTable/pulls)


Load ply mesh file in Unity 3D use vcglib.


## Feature
* use [vcglib](https://github.com/cnr-isti-vclab/vcglib)
* support per face uv (change to per vertex uv)
* easy expand to other format (asc,ctm,dae,fbx,field,gts,nvm,obj,off,out,ptx,raw,smf,stl,vmi)
* **cross platform**


## Environment
* Unity 2018.3+
* CMake 2.8+
* g++ 5.4+

## Usage
1. Build the plyloder dynamic library
```shell
cd CppNativePlugin
mkdir build
cd build
cmake ..
make -j
```
2. Copy the `libPlyLoader.so` to `UnityProject/Assets/PlyLoader/PlyLoader.so` (or `PlyLoader.dll` in Windows)

## License
MIT

## Author
[warmtrue](http://www.warmtrue.com)