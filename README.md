LineCalculator
==============

To build this project with Visual Studio 2012:

- Install the Qt VS Addin
    - http://qt-project.org/downloads (Visual Studio Add-in 1.2.3 for Qt5)
    - Set version to 5.X+
- Download and install MPIR
    - http://www.mpir.org/ (2.6.0)
    - Extract the files and open the .sln (mpir-2.6.0/build.vc10/mpir.sln)
    - Switch to release mode
    - Set dll_mpir_gc as startup project
    - Build -> Build dll_mpir_gc
    - Go to mpir-2.6.0/dll/Win32/Release/ and check if files have been generated
- Set line calculator project settings
    - Properties -> Configuration properties -> VC++ Directories
    - Add the mpir location to include, reference and library directories (yourpath/mpir-2.6.0/dll/Win32/Release/)
    - Move to Properties -> Configuration properties -> Linker
    - Add "mpir.lib" as an Additional Dependency
