@echo off
cl /nologo %1 ws2_32.lib

IF EXIST *.obj (DEL *.obj)
