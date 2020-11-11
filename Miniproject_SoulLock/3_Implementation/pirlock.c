#include <stdio.h>
#include <time.h>

/*
 *gpio_26 - clockwise(open):Relay1:output
 *gpio_44 - anticlockwise(close):Relay2:output
 *gpio_68 - anticlockwise(sense):PIR:Input
*/

int main()
{
    FILE *dropen,*dopindir,*dopinval;
    FILE *drshut,*dspindir,*dspinval;
    FILE *sspin,*sspindir,*soulsens;


    dropen = fopen("/sys/class/gpio/export", "w");
    fseek(dropen,0,SEEK_SET);
    fprintf(dropen,"%d",26);
    fflush(dropen);

    dopindir = fopen("/sys/class/gpio/gpio26/direction", "w");
    fseek(dopindir,0,SEEK_SET);
    fprintf(dopindir,"out");
    fflush(dopindir);

    dopinval = fopen("/sys/class/gpio/gpio26/value", "w");
    fseek(dopinval,0,SEEK_SET);

    drshut = fopen("/sys/class/gpio/export", "w");
    fseek(drshut,0,SEEK_SET);
    fprintf(drshut,"%d",44);
    fflush(drshut);

    dspindir = fopen("/sys/class/gpio/gpio44/direction", "w");
    fseek(dspindir,0,SEEK_SET);
    fprintf(dspindir,"out");
    fflush(dspindir);

    dspinval = fopen("/sys/class/gpio/gpio44/value", "w");
    fseek(dspinval,0,SEEK_SET);

    sspin = fopen("/sys/class/gpio/export", "w");
    fseek(sspin,0,SEEK_SET);
    fprintf(sspin,"%d",68);
    fflush(sspin);

    sspindir = fopen("/sys/class/gpio/gpio68/direction", "w");
    fseek(sspindir,0,SEEK_SET);
    fprintf(sspindir,"in");
    fflush(sspindir);

    soulsens = fopen("/sys/class/gpio/gpio68/value", "w");
    fseek(soulsens,0,SEEK_SET);


    while(1)
    {
        fseek(soulsens,0,SEEK_SET);
        fseek(dopinval,0,SEEK_SET);
        fseek(dspinval,0,SEEK_SET);
        if(&soulsens == 1)
            {
                kprintf("Presense of human detected----Door opening\n");
                fprintf(dopinval,"%d",1);
                fflush(dopinval);
                delay(5);
                fprintf(dopinval,"%d",0);
                fflush(dopinval);
                delay(10);
                fseek(soulsens,0,SEEK_SET);
                if(&soulsens == 0)
                {
                    kprintf("Human assumed to have exited----Door closing\n");
                    fprintf(dspinval,"%d",1);
                    fflush(dspinval);
                    delay(7);
                    fprintf(dspinval,"%d",0);
                    fflush(dspinval);                      
                }
                else
                {
                    fprintf(dspinval,"%d",0);
                    fflush(dspinval);
                }
                

            }
        else
            {
                fprintf(dopinval,"%d",0);
                fflush(dopinval);
            }
        fclose(dropen);
        fclose(dopindir);
        fclose(dopinval);
        fclose(drshut);
        fclose(dspindir);
        fclose(dspinval);
        fclose(sspin);
        fclose(sspindir);
        fclose(soulsens);
        return 0;
    }
}