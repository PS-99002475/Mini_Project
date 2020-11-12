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
    while (clock() < start_time + milli_seconds); 
}
int main()
{
    FILE *dropen,*dopindir,*dopinval;
    FILE *drshut,*dspindir,*dspinval;
    FILE *sspin,*sspindir,*soulsens;
    int soulval;
/*
    dropen = fopen("/sys/class/gpio/export", "w");
    fseek(dropen,0,SEEK_SET);
    fprintf(dropen,"%d",26);
    fflush(dropen);
*/
    dopindir = fopen("/sys/class/gpio/gpio26/direction", "w");
    fseek(dopindir,0,SEEK_SET);
    fprintf(dopindir,"out");
    fflush(dopindir);
    dopinval = fopen("/sys/class/gpio/gpio26/value", "w");
    fseek(dopinval,0,SEEK_SET);
    
 /*
    drshut = fopen("/sys/class/gpio/export", "w");
    fseek(drshut,0,SEEK_SET);
    fprintf(drshut,"%d",44);
    fflush(drshut);
*/
    dspindir = fopen("/sys/class/gpio/gpio44/direction", "w");
    fseek(dspindir,0,SEEK_SET);
    fprintf(dspindir,"out");
    fflush(dspindir);


    dspinval = fopen("/sys/class/gpio/gpio44/value", "w");
    fseek(dspinval,0,SEEK_SET);



