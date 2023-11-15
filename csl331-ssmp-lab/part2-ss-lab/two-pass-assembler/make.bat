@echo off
gcc %1.c -o%1 -std=c99 -Wall
%1
@echo on