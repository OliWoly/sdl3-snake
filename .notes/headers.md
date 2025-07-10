# Highlights and autocomplete.
*This is a VScode specific issue. Other IDE's will require different solutions.*
problem lies within the;
```
c_cpp_properties.json
```
file.

```json
{
  "configurations": [
    {
      "name": "macos-clang-arm64",
      "includePath": [
        "${workspaceFolder}/**",
        "/opt/homebrew",
        "/opt/homebrew/include",
        "/opt/homebrew/include/SDL3"
      ],
      "compilerPath": "/usr/bin/clang",
      "cStandard": "${default}",
      "cppStandard": "${default}",
      "intelliSenseMode": "macos-clang-arm64",
      "compilerArgs": [
        ""
      ]
    }
  ],
  "version": 4
}
```
Need to add the same path as listed in the cmakelists.txt include path in this file. This file tells VScode where to look for C++ libraries.