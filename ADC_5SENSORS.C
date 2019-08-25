#include<pic.h>
#define LCD PORTC
void command();
void data();
void lcd();
void delay(int x);

void main()
{
ANSEL=0XFF;
PORTC=0X00;
TRISC=0X00;
TRISD=0X1C;
PORTD=0X00;
TRISA=0XFF;
ADCON1=0X80;
int d=0;
int arr[10]={'0','1','2','3','4','5','6','7','8','9'};
while(1)
{
int a,b,c,d=0;
lcd();
int Vin=0;
if(RD2==1)
	{
	ADCON0=0X03;   //AN0
	while(GO==1);

	d=(ADRESH<<8) + ADRESL; 

	Vin= d*0.4887;  // ANALOG VALUE
	a= Vin;
	b= Vin/10;
	c= Vin/100;
	d= Vin/1000;

	LCD= arr[d%10];
	data();
	delay(50);

	LCD= arr[c%10];
	data();
	delay(50);

	LCD= arr[b%10];
	data();
	delay(50);

	LCD= arr[a%10];
	data();
	delay(50);

	while(RD2==1);

	}

if(RD3==1)
	{	
	ADCON0=0X07;   //AN1
	while(GO==1);
	d=(ADRESH<<8) + ADRESL; 

	Vin= d*0.4887;  // ANALOG VALUE
	a= Vin;
	b= Vin/10;
	c= Vin/100;
	d= Vin/1000;

	LCD= arr[d%10];
	data();
	delay(50);

	LCD= arr[c%10];
	data();
	delay(50);

	LCD= arr[b%10];
	data();
	delay(50);

	LCD= arr[a%10];
	data();
	delay(50);
	
	while(RD3==1);
	}

if(RD4==1)
	{
	ADCON0=0X0B;   //AN2

	while(GO==1);
	d=(ADRESH<<8) + ADRESL; 

	Vin= d*0.4887;  // ANALOG VALUE
	a= Vin;
	b= Vin/10;
	c= Vin/100;
	d= Vin/1000;

	LCD= arr[d%10];
	data();
	delay(50);

	LCD= arr[c%10];
	data();
	delay(50);

	LCD= arr[b%10];
	data();
	delay(50);

	LCD= arr[a%10];
	data();
	delay(50);
	
	while(RD4==1);
	}
}

}



void delay(int x)
{
while(x--);
}


void command()  
{ 
RD0=0;
RD1=1;
delay(50);
RD1=0;
}

void data()
{
RD0=1;
RD1=1;
delay(50);
RD1=0;
}


void lcd()
{

LCD=0X38;
command();
delay(100);

LCD=0X01;
command();
delay(100);

LCD=0X0C;
command();
delay(100);

LCD=0X80;
command ();
delay(100);
}