# Switcher
### 	Nice, easy to learn game in WinCRT

## How to import as project

0.	Make sure you have installed `Visual Studio 2019` with `English Language Package` installed.

1.	First of all install [`vcpkg`](https://github.com/microsoft/vcpkg) to install boost, or do it by yourself ( if so, you have to then add paths to project, and you can skip next point ).

2.	To install and configure `boost` via `vcpkg` type following commands in PS in `vcpkg` directory

		./vcpkg.exe integrate powershell
		./vcpkg.exe install boost
		./vcpkg.exe integrate install

3.	Now in another directory `git clone` this repo. After clone, open this project with `Visual Studio 2019`.

4. You should see 2 projects, first is core project, second one posses tests, which should be run after every successfull compile.
