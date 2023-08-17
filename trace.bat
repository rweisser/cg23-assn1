@echo off
rem Run the trace program and show the output ppm file

if %1 == "" (
    echo usage: trace filename
    goto :eof
)
trace\build\Release\trace.exe %1
if %errorlevel% neq 0 (
    echo Trace failed
    goto :eof
)
copy trace\build\%1 trace\output\%1
show %1
