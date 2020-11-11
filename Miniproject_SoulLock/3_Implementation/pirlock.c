#include <stdio.h>

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
    fseek(dispinval,0,SEEK_SET);

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
        fprintf(soulsens,"%d",1);
        fflush(soulsens);
        sleep(1);
        fprintf(soulsens,"%d",0);
        fflush(soulsens);
        sleep(1);

        {
fseek(pirin,0,SEEK_SET);
fseek(bzrout,0,SEEK_SET);
fscanf(pirin,"%d",&pir_val);
printf("pir val = %d",pir_val);
if(PIR_FLAG==1)
{
fprintf(bzrout,"%d",1);
fflush(bzrout);
delay(5);
fprintf(bzrout,"%d",0);
fflush(bzrout);
PIR_FLAG=0;
}
if(PIR_FLAG==0 && pir_val=1)
{
PIR_FLAG=1;
}
    }

    fclose(dropen);
    fclose(dopindir);
    fclose(soulsens);
    return 0;
}