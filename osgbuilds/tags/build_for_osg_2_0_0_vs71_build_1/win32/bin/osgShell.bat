@echo off

REM Config section ========================================================
REM Adjust these settings to taste...

set PATH=%OSG_ROOT%\bin;%PATH%

set PRODUCER_CAMERA_CONFIG_FILE=%OSG_ROOT%\data\Producer\1win.cfg

REM set OSG_NOTIFY_LEVEL=ALWAYS
REM set OSG_NOTIFY_LEVEL=FATAL
REM set OSG_NOTIFY_LEVEL=WARN
REM set OSG_NOTIFY_LEVEL=NOTICE
REM set OSG_NOTIFY_LEVEL=DEBUG
REM set OSG_NOTIFY_LEVEL=DEBUG_FP
REM set OSG_NOTIFY_LEVEL=INFO
 
REM Runtime section =======================================================

title osgShell
echo A console configured for OpenSceneGraph:
echo OSG_ROOT = %OSG_ROOT%
echo OSG_FILE_PATH = %OSG_FILE_PATH%
echo PRODUCER_CAMERA_CONFIG_FILE = %PRODUCER_CAMERA_CONFIG_FILE%
echo OSG_NOTIFY_LEVEL = %OSG_NOTIFY_LEVEL%

%COMSPEC% /K
