@echo off

if "%1"=="" (
    echo SystemC 2 Verilog converter
    echo Usage: sc2v ^<Module name without extension^>
) else (
    if exist "%1.cpp" (
        if exist "%1.h" (
            echo Processing %1
            %~dp0\sc2v_step1 < %1.cpp
            echo Processing %1.h
            %~dp0\sc2v_step2 < %1.h > %1.sc2v
            echo Generating verilog file
            %~dp0\sc2v_step3 < %1.sc2v > %1.v
            echo Done
            if exist "*.sc2v" del *.sc2v
            if exist "%~dp1\*.sc2v" del %~dp1\*.sc2v
        ) else (
            echo Can't find %1.h
        )
    ) else (
        echo Can't find %1.cpp
    )
)
