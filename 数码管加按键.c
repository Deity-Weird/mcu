#include "reg52.h"
typedef unsigned char uchar;
typedef unsigned int uint;
sbit we=P2^7;
sbit du=P2^6;
sbit Key=P3^0;
uchar num_1=0;
uchar num_2=0;
uchar code smg[16] = {0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,
		      0x7f,0x6f,0x77,0x7c,0x39,0x5e,0x79,0x71};	
uchar code1[8] = {0xfe,0xfd,0xfb,0xf7,0xef,0xdf,0xbf,0x7f};
void Delay(uint z)  
 {
   uint i,j;
   for(j=z;j>0;j--)
   for(i=112;i>0;i--);
}
void Display()
{
	
    du=1;
    P0=smg[num_1];
    du=0;
	P0=0xff;
   	we=1;
    P0=code1[num_2];
    we=0;
}
void Key_()
{
    if (Key==0)
    {
        Delay(10);
        if(Key==0)
        {
            while(!Key);
            num_1++;
        }
        /* code */
    }
    
}
void main()
{	
    while(1)
    {
    
              Display();
        Key_();
		// num_2++;
		if(num_1==10)
		num_1=0;
		Delay(10);
        // if(num_2==8)
        // num_2=0;
    }
}