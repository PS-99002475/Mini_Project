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
    FILE *soulsens,*sspindir,*sspinval;


    dropen = fopen("/sys/class/gpio/export", "w");
    fseek(dropen,0,SEEK_SET);
    fprintf(dropen,"%d",26);
    fflush(dropen);

    dopindir = fopen("/sys/class/gpio/gpio39/direction", "w");
    fseek(dopindir,0,SEEK_SET);
    fprintf(dopindir,"out");
    fflush(dopindir);

    soulsens = fopen("/sys/class/gpio/gpio39/value", "w");
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