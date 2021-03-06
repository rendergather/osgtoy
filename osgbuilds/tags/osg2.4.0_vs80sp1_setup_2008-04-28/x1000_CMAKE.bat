REM launch CMake in noninteractive/batch build mode.
title running cmake...
call SETENV.bat

REM mew's overrides to the default CMake configuration...
set F1=-DCMAKE_CONFIGURATION_TYPES:STRING=%VC_CFG%
set F2=-DCMAKE_INSTALL_PREFIX=%INSTALLDIR% 
set F3=-DBUILD_OSG_EXAMPLES=ON 
set F4=-DBUILD_OSG_WRAPPERS=ON 
set F5=-DBUILD_MFC_EXAMPLE=ON 
set F6=-DWIN32_USE_MP=ON

if not exist %BUILDDIR% mkdir %BUILDDIR%
cd %BUILDDIR%
"%CMAKEDIR%\cmake" %CM_GEN% %F1% %F2% %F3% %F4% %F5% %F6% %SOURCEDIR%
pause
