@echo off
title Contact List Management System - Demo
cls

echo [System] Checking for executable...
if not exist ContactManager.exe (
    echo [System] Executable not found. Compiling now...
    gcc -Iinclude -Wall src/main.c src/contacts.c src/ui.c -o ContactManager.exe
)

if exist ContactManager.exe (
    echo [System] Launching Application...
    timeout /t 1 >nul
    ContactManager.exe
) else (
    echo.
    echo [Error] Compilation failed! Please check the code for typos.
    pause
)