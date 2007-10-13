@echo off
title running cmake...
call SETENV.bat

set F1=-DCMAKE_CONFIGURATION_TYPES:STRING=%VC_CFG%
set F2=-DCMAKE_INSTALL_PREFIX=%INSTALLDIR% 
set F3=-DBUILD_OSG_EXAMPLES=ON 
set F4=-DBUILD_OSG_WRAPPERS=ON 

if not exist %BUILDDIR% mkdir %BUILDDIR%
cd %BUILDDIR%
%CMAKE% %CM_GEN% %F1% %F2% %F3% %F4% %SOURCEDIR%
pause
