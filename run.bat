@echo off
title Contact List Management System - Demo
cls

echo running executable...
if not exist ContactManager.exe (
    echo [System] Executable not found. Compiling now...
    make
)

if %errorlevel% equ 0 (
    echo [System] Launching Application...
    timeout /t 1 >nul
    ContactManager.exe
) else (
    echo.
    echo [Error] Compilation failed! Please ensure GCC and Make are installed.
    pause
)