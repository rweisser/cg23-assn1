@echo off
rem Show the output ppm file in the output directory.

if %1 == "" (
    echo usage: show filename
    goto :EOF
)
trace\output\%1
