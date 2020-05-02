:loop
random.exe > data.txt
vjR(2).exe < data.txt > vjR(2).txt
vjR.exe < data.txt > vjR.txt
fc vjR.txt vjR(2).txt
if %errorlevel%==0 goto loop
pause