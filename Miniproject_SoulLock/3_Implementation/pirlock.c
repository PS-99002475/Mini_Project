#include <stdio.h>


int main()
{
    FILE *io,*dooract,*soulsens;

    io = fopen("/sys/class/gpio/export", "w");
    fseek(io,0,SEEK_SET);
    fprintf(io,"%d",39);
    fflush(io);

    dooract = fopen("/sys/class/gpio/gpio39/direction", "w");
    fseek(dooract,0,SEEK_SET);
    fprintf(dooract,"out");
    fflush(dooract);

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
    }

    fclose(io);
    fclose(dooract);
    fclose(soulsens);
    return 0;
}