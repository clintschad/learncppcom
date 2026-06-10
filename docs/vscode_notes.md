# VSCode Notes

## Configuration
* [VSCode Setup for Mac](https://code.visualstudio.com/docs/cpp/config-clang-mac)
* To have VSCode compile all .cpp files in the directory, go to _tasks.json_ and replace `"${file}"` with `"${fileDirname}/**.cpp"`
* Using the extension _C/C++ Runner_ by franneck94 fixes the issue of not being able to step through `cin` statements. It's a bit different to use than the default debugger:
    - While you can use the debug option from the usual top right spot, the extension installs buttons on the bottom left of the window
    - From left to right: project folder, build config (release/debug), build, run, debug. So first, select the project folder containing the main C++ file/s. Select config. Click build. Then can click run or debug.
    - Need to configure its compiler settings (c++ version and compiler flags) because it uses the system default.

## Keyboard Shortcuts
* Run command from top bar: `Shift + Ctrl + P`
* Show/hide terminal: `CMD + tilde`
* Show/hide folder explorer pane: `Shift + Ctrl + E`
* Build and debug program: `F5`
* Build and run program: `CMD + F5`
