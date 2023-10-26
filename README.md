# RetrieveAssetsFromPath for Unreal Engine

## Summary

**RetrieveAssetsFromPath** is a utility plugin for Unreal Engine that provides functionality to load all assets from a specified directory into an array dynamically. The utility searches for assets within a designated folder and returns them as an array of `UObject`s, making them accessible for various in-game uses. It leverages Unreal's file manager for a comprehensive search, and assets are loaded using the `StaticLoadObject` function.

## Reason

Unreal Engine, out of the box, doesn't offer the possibility to dynamically load all assets from a specific directory into an array. Although such functionality can potentially impact performance, there are numerous scenarios where this utility can be invaluable. Particularly, when focusing on artistic projects, virtual production, or any situation that requires dynamic folder content access, this utility shines. Furthermore, it can be beneficial for developers and designers working on video games with a need for dynamic asset loading.

## How to Use

1. **Direct Plugin Installation**:
   - Download the repository.
   - Unzip and place it in the `Plugins` folder of your Unreal project.

2. **Using Releases Tab**:
   - Download the zip folder from the `Releases` tab.
   - Unzip and place it in the `Plugins` folder of your project.

3. **Compatibility**:
   - The plugin was compiled using Unreal 5.1.1.
   - Tested and found working on Unreal 5.2 and 5.3. 
   - When using it with different versions of Unreal, you may be prompted to recompile. Click "Yes" when asked and wait for the compilation to finish.

4. **Usage in Blueprint**:
![Screenshot in Blueprint Editor](https://github.com/kessoning/UE5_RetrieveAssetsFromPath/blob/main/Screenshot.png?raw=true)

## Additional Notes

- It's always a good idea to backup your project before adding or modifying plugins.
- While this utility is powerful, be mindful of potential performance implications, especially when loading a large number of assets.

## License

MIT License

Copyright (c) 2023 - Giovanni Muzio

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.