@echo off
del BottomBackground.hpp
del TopBackground.hpp
bin2c.exe /custvar "BottomBackground" /infile "BottomBackground.bmp" /outfile "BottomBackground.hpp"
bin2c.exe /custvar "TopBackground" /infile "TopBackground.bmp" /outfile "TopBackground.hpp"
pause