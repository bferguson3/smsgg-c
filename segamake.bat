@ECHO OFF
sdcc -c -mz80 main.c
sdcc -o main.ihx -mz80 --no-std-crt0 --data-loc 0xC000 crt0_sms.rel main.rel SMSlib.lib PSGlib.rel
sdcc -o main_gg.ihx -mz80 --no-std-crt0 --data-loc 0xC000 crt0_sms.rel main.rel SMSlib_GG.lib PSGlib.rel 
ihx2sms main.ihx main.sms 
ihx2sms main_gg.ihx main.gg 
echo DELETING BUILD FILES... 
del *.ihx 
del *.lk 
del *.map 
del *.noi 
del *.lst 
del main.rel
del main.sym 
echo BUILD DONE
@ECHO ON
