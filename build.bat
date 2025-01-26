@echo off
cls
make clean
make
rd /s /q Build
pause
py .Release/releasezip.py
pause