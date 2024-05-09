@echo off
set /p port=Enter port: 
set /p baudRate=Enter Baud Rate: 

"./Serial-To-HID.exe" %port% %baudRate%