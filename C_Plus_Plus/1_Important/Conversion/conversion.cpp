#include<iostream>
using namespace std;
unsigned char HexDataPort1;
unsigned char DigitBuff1[255];
char Comm1Buff[1500];
unsigned char BuffCount1;
void ConvertToAscii1(void);
void ConvertAsciiToHex1(void);
int main()
{
	unsigned char localDigi[10];
	HexDataPort1=155;
	// Comm1Buff[1400]=48;   // charcter array store charcter value
	// cout<<"Value="<<Comm1Buff[1400]<<endl;
	// ConvertToAscii1();
	// for(int i=0;i<2;i++)
	// {
	// 	cout<<DigitBuff1[i]<<endl;
	// }
	// Comm1Buff[150]='!';
	ConvertAsciiToHex1();
	
	cout<<"HexData="<<HexDataPort1<<endl;
	return 0;
}

void ConvertToAscii1(void)
{
	if ((HexDataPort1 & 0x0f) < 0x0A)			DigitBuff1[0] = (HexDataPort1 & 0x0f) + 0x30;
	else										DigitBuff1[0] = (HexDataPort1 & 0x0f) + 0x37;

	if (((HexDataPort1 & 0xf0) >> 4) < 0x0A)	DigitBuff1[1] = ((((HexDataPort1 & 0xf0) >> 4) & 0x0f) + 0x30);
	else										DigitBuff1[1] = ((((HexDataPort1 & 0xf0) >> 4) & 0x0f) + 0x37);
}

void ConvertAsciiToHex1(void)
{
	if (Comm1Buff[BuffCount1] > 0x39)	HexDataPort1 = ((Comm1Buff[BuffCount1] - 0x37) << 4) & 0x0F0;
	else 								HexDataPort1 = ((Comm1Buff[BuffCount1] - 0x30) << 4) & 0x0F0;

	BuffCount1++;

	if (Comm1Buff[BuffCount1] > 0x39)	HexDataPort1 |= (Comm1Buff[BuffCount1] - 0x37);
	else 								HexDataPort1 |= (Comm1Buff[BuffCount1] - 0x30);
}