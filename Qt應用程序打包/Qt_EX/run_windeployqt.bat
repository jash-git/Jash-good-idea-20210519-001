REM 執行環境配置
echo off
echo Setting up environment for Qt usage...
set PATH=C:\Qt\Qt5.4.0\5.4\mingw491_32\bin;C:\Qt\Qt5.4.0\Tools\mingw491_32\bin;%PATH%
cd /D C:\Qt\Qt5.4.0\5.4\mingw491_32
REM pause

REM 切換到工作目錄
cd C:\Users\jashliao\Desktop\Qt\build-Qt5_windeployqt_test-Desktop_Qt_5_4_0_MinGW_32bit-Debug\debug
pause

REM 執行相依性檔案偵測與複製
windeployqt Qt5_windeployqt_test.exe
echo.
echo.
echo Manually delete non-DLL and non-EXE related files
pause

