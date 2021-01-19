
#include "SMSlib.h"
#include "PSGlib.h"

#define true 1
//#define TARGET_GG 1
void GameLoop(void);
void Draw(void);

SMS_EMBED_SEGA_ROM_HEADER(0, 0);

int z = 0;

void main(void) {
    SMS_autoSetUpTextRenderer();
    //volatile int* vdp_ctrl = 0xbf;
    //volatile int* vdp_data = 0xbe;
    
    //for(int f = 0; f < 255; f++){
    //    *vdp_ctrl = (0x3800 + (f*2)) | 0x4000;
    //    *vdp_data = 'A';
   // }
   /*
    __asm
        ld hl,#0x3910
        ld a,l 
        out (0xbf),a 
        ld a,h 
        or #0x40
        out (0xbf),a 
        ld a, #'Z'
        out (0xbe),a
        out (0xbe),a
    __endasm;
    */
    while(true){
        GameLoop();
        SMS_waitForVBlank();       
        Draw();
    }
}

void GameLoop()
{
    z++;
    return;
}

void Draw()
{
    SMS_setNextTileatXY(z, z);
    SMS_setTile(z);
}