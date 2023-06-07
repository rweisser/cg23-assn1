@echo off
rem Run the trace program and show the output ppm file

trace\build\Release\trace.exe %1
if %errorlevel% neq 0 (
    echo Trace failed
    goto :eof
)
trace\build\trace.ppm
