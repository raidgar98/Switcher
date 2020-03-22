# Switcher
### 	Nice, easy to learn game in WinCRT

## How to import as project

0.	Make sure you have installed `Visual Studio 2019` with installed:
	- English Language Package
	- `C++` Development Pack
	- `UWP` Development Pack

1.	First of all install [`vcpkg`](https://github.com/microsoft/vcpkg) to install boost, or do it by yourself ( if so, you have to then add paths to cloned project, and you can skip this and next point ).

2.	To install and configure `boost` via `vcpkg` type following commands in PS in `vcpkg` directory

>		./vcpkg.exe integrate powershell
>		./vcpkg.exe install boost
>		./vcpkg.exe integrate install

3.	Now in another directory where you want this repo to store, type following commands in Git Bash (or alternative software):

>		git clone git@github.com:raidgar98/Switcher.git -b <version_release>
>		cd Switcher
>		git submodule update --init --recursive

4. After that you can open `sln` file and start to configure enviroment:

	- Set solution configuration to `Debug` or `Release` and select your architecture `x86` or `x64`. Tested on both;

	- Select `Engine` and `Tests` sub-project, right click on them and in project properties: `General > C++ Language Standard` select `ISO C++ 17`;

	- Right-click on `GUI` sub-project, choose project properties, then: `C/C++ > Language > C++ Language Standard` select `ISO C++ 17`;

	- Again right-click on `GUI` sub-project and click: `Set as Startup Project`;

5. When enviroment is ready just click `Ctrl + Shift + B` to compile, then `Ctrl + F5` to run.

6. To run tests it is good to go to `Test` tab and select `Run All Tests`. In new window, all tests appear, with status


In 3'rd point there is `<version_release>` tag currently theese are avaiable:

		24_tile_version_release
		15_tile_version_release

