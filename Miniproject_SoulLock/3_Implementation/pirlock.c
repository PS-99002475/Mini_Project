#include <stdio.h>
#include <time.h>
#include <stdlib.h>

/*
 *gpio_26 - clockwise(open):Relay1:output
 *gpio_44 - anticlockwise(close):Relay2:output
 *gpio_68 - PIRinputdata(sense):PIR:Input
*/

void delay(int number_of_seconds) 
{ 
    // Converting time into milli_seconds 
    int milli_seconds = 1000 * number_of_seconds; 
  
    // Storing start time 
    clock_t start_time = clock(); 
  
    // looping till required time is not achieved 
    while (clock() < start_time + milli_seconds) 
        ; 
}

int main()
{
    FILE *dropen,*dopindir,*dopinval;
    FILE *drshut,*dspindir,*dspinval;
    FILE *sspin,*sspindir,*soulsens;
    int soulval;

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
    fscanf(soulsens, "%d", &soulval);


    while(1)
    {
        soulsens = fopen("/sys/class/gpio/gpio68/value", "w");
        dopinval = fopen("/sys/class/gpio/gpio26/value", "w");
        dspinval = fopen("/sys/class/gpio/gpio44/value", "w");
        fseek(soulsens,0,SEEK_SET);
        fseek(dopinval,0,SEEK_SET);
        fseek(dspinval,0,SEEK_SET);
        fscanf(soulsens, "%d", &soulval);
        printf("%d",soulval);
        if(soulval == 1)
            {
                printf("Presense of human detected----Door opening\n");
                fprintf(dopinval,"%d",1);
                fflush(dopinval);
                delay(5);
                dopinval = fopen("/sys/class/gpio/gpio26/value", "w");
                fprintf(dopinval,"%d",0);
                fflush(dopinval);
                delay(10);
                fseek(soulsens,0,SEEK_SET);
                fscanf(soulsens, "%d", &soulval);
                if(soulval == 1)
                {
                    printf("Human assumed to have exited----Door closing\n");
                    fprintf(dspinval,"%d",1);
                    fflush(dspinval);
                    delay(7);
                    dspinval = fopen("/sys/class/gpio/gpio44/value", "w");
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