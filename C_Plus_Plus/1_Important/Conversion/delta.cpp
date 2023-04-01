
/* Delta Plc Modbus Ascii Protocol Driver for Com1 */

#include"EXTDRV.h"
#include"HEADER.h"
#include"CPU.h"
#include"DRVCPU.h"
#include"EXT.h"
#include"SerHrd.h"
#include"PLC1DRV.H"
#include"SERDRV.h"
#include"Start.h"
#include"plc.h"

void Plc1RdHeap(void);
void Plc1WrHeap(void);
void EvalRegTyp1(void);
void CheckPlc1WrResp(void);
void ConvertToAscii1(void);
void ConvertAsciiToHex1(void);
unsigned char Bcc_Calculate1(unsigned char* resp, unsigned char Bcc_End);
unsigned char ConvertASCIItoHex1(unsigned char* Var1, unsigned char* Var2);
void ReceiveModbusDelay1(void);
void ModbusSlaveTxDelay1(void);
void DriverDelayHandlerCom1(void);
extern unsigned short usThreeHalfRec1;
extern unsigned volatile short usThreeHalfAfterRec1;
extern volatile unsigned char ucThreeHalfAfterRecFlag1;
extern void InitComPort(unsigned char Port, unsigned char BoudRate, unsigned char Parity, unsigned char NoOfBits, unsigned char StopBit, unsigned char iin);

ucharx			PlcReg4Port1, PlcReg3Port1, PlcReg2Port1, PlcReg1Port1, PlcReg0Port1, PlcRegTypPort1,  RegLenPort1;
unsigned char 	RetValPort1, Node1Address;
extern unsigned char BlockSizeDummy1[32][2];
unsigned char	AddrCount1, HexDataPort1;
unsigned char 	RegAddr1_Hi, RegAddr1_Lo, BitData1, TempBlockSizePort1;
unsigned int	RegAddr1;
unsigned char	Broadcast1, TempFrameLength1;

extern xstruct CommandQueue
{
	uchar R_W;
	uchar DataUpdate;
	uchar ValidEntry;
	uchar Port;
	uchar Node;
	uchar Length;
	uchar Tag[9];
	uchar NoOfBytes;
	uint  LoWord[16];
	uint  HiWord;
}CMDQ1[1], CMDQ2[1];

extern struct BGCommandQ
{
	uint  LoWord[100];
}BGCMDQ1[1], BGCMDQ2[1];

extern struct BGCommandQ_RECIPE
{
	uint  LoWord[100];
}BGCMDQ1_Rec[1], BGCMDQ2_Rec[1];

void StartCommPlc1(void)
{
	PlcCommIni1();
	PowerOnAttach1 = 1;

	for (NodeAddCount1 = 0; NodeAddCount1 < NodesForPort1; NodeAddCount1++)
	{
		GetResponse1 = 0;
		SendCnt1 = 0;
		FrameEnd1 = 0;
		DummyComm1 = 1;
		Response1Completed = 1;

		if ((Port1NodeAddr[NodeAddCount1] == 0) && (NodeAddCount1 == (NodesForPort1 - 1)) && (BroadCastEnable1 == 1)) break;
		else if (Port1NodeAddr[NodeAddCount1] == 0) NodeAddCount1++;

		CurrNodeAddress1 = Port1NodeAddr[NodeAddCount1];
		DummyHeapPort1(Port1NodeAddr[NodeAddCount1]);
		CopyCurrentFrame1();

		GetCommPar1();
		Drv1Del1S = TimeOut1;

		if (InterFrameDelay1 == 0)
			InterFrameDelay1 = ThreeHalfDel1;

		ByteToBeSend1 = Comm1Buff[SendCnt1];
		Com1Timespan = InterFrameDelay1;
		Com1Delay = 1;

		TimeOutCount = 0x02;
		TimeOutFlag = 1;

		while (1)
		{
			ToggleWdi();
			if (!TimeOutFlag) break;
			if (GetResponse1 == 1) break;
		}

		if (GetResponse1 == 1)
		{
			GetPrevFrame1();
			CopyCurrentFrame1();
			UpdateNodeStatus1();
		}
	}

	CheckIfIBMonPort1();
	PowerOnAttach1 = 0;
	UpdateNodeStatusPort1 = 1;
	PlcAttachDone1 = 1;

	if (RetryCount1 == 0)
		RetryCount1 = 2;
}

void PlcCommIni1(void)
{
	Drv1Del1S = TimeOut1;
	FrameEnd1 = 0;
	WriteError1 = 0;
	Length1Received = 0;
	counter = 0;
	EndOfFrame1 = 1;
	Plc1Present = 0;

	MSG[20] = "DELTA:ASCII:Master:Port1";
	MSG[21] = "Ver.: 44.00I";

	InitComPort(1, BaudRate1, Parity1, NoOfBits1, StopBit1, 1);

	switch (BaudRate1)
	{
		case 0:			ThreeHalfDel1 = 72;			break;
		case 1:			ThreeHalfDel1 = 36;			break;
		case 2:			ThreeHalfDel1 = 18;			break;
		case 3:			ThreeHalfDel1 = 10;			break;
		case 4:			ThreeHalfDel1 = 6;			break;
		case 5:			ThreeHalfDel1 = 4;			break;
		default:		ThreeHalfDel1 = 4;			break;
	}
}

void ServPlc1RdHeap(void)
{
//	BitOperationPort1 = 0;
	EvalRegTyp1();
	Plc1RdHeap();
	CopyCurrentFrame1();
	Broadcast1 = 0;
	SendCnt1 = 0;
	FrameEnd1 = 0;
	DummyComm1 = 0;
	EndOfFrame1 = 1;
	Response1Completed = 1;
	GetCommPar1();

	if (InterFrameDelay1 == 0)
		InterFrameDelay1 = ThreeHalfDel1;

	ByteToBeSend1 = Comm1Buff[SendCnt1];
	Com1Timespan = InterFrameDelay1;
	Com1Delay = 1;
}

void ServPlc1WrHeap(void)
{
//	BitOperationPort1 = 0;
	Plc1WrHeap();
	if ((NodeIntrPort1 == 0) && (BroadCastEnable1 == 1))
	{
		Broadcast1 = 1;
	}
	CopyCurrentFrame1();
	SendCnt1 = 0;
	FrameEnd1 = 0;
	DummyComm1 = 0;
	Response1Completed = 1;
	EndOfFrame1 = 1;
	GetCommPar1();

	if (InterFrameDelay1 == 0)
		InterFrameDelay1 = ThreeHalfDel1;

	ByteToBeSend1 = Comm1Buff[SendCnt1];
	Com1Timespan = InterFrameDelay1;
	Com1Delay = 1;
}

void Driver1Retry(void)
{
	BitOperationPort1 = 0;
	GetPrevFrame1();
	SendCnt1 = 0;
	FrameEnd1 = 0;
	counter = 0;
	DummyComm1 = 1;
	Response1Completed = 1;

	ByteToBeSend1 = Comm1Buff[SendCnt1];
	SetDirectionPort1();
	KickStart1();
}

void DummyCommunication1(void)
{
	Broadcast1 = 0;
	DummyComm1 = 1;
	Response1Completed = 1;
	DummyHeapPort1(Port1NodeAddr[NodeAddCount1]);
	CopyCurrentFrame1();
	SendCnt1 = 0;
	FrameEnd1 = 0;
	GetCommPar1();

	if (InterFrameDelay1 == 0)
		InterFrameDelay1 = ThreeHalfDel1;

	ByteToBeSend1 = Comm1Buff[SendCnt1];
	Com1Timespan = InterFrameDelay1;
	Com1Delay = 1;
}

void MonitorMode1(void)
{
}

void SendNextAttachFrame1(void)
{
}

void GetNextByteInResponse1(void)
{
}

void SendFirstAttachFrame1(unsigned char NodeAddress1)
{
}

void SendCpuId1(void)
{
}

void Plc1WrHeap(void)
{
	Bcc1 = 0;
	BuffCount1 = 0;
	EvalRegTyp1();

	Comm1Buff[BuffCount1] = ':';					BuffCount1++;

	HexDataPort1 = NodeIntrPort1;
	Bcc1 += HexDataPort1;
	ConvertToAscii1();
	Comm1Buff[BuffCount1] = DigitBuff1[1];			BuffCount1++;
	Comm1Buff[BuffCount1] = DigitBuff1[0];			BuffCount1++;

	if (BitOperationPort1)	HexDataPort1 = 0x05;
	else					HexDataPort1 = 0x10;

	Bcc1 += HexDataPort1;
	ConvertToAscii1();
	Comm1Buff[BuffCount1] = DigitBuff1[1];				BuffCount1++;
	Comm1Buff[BuffCount1] = DigitBuff1[0];				BuffCount1++;

	HexDataPort1 = (unsigned char)(RegAddr1 >> 8);
	Bcc1 += HexDataPort1;
	ConvertToAscii1();
	Comm1Buff[BuffCount1] = DigitBuff1[1];				BuffCount1++;
	Comm1Buff[BuffCount1] = DigitBuff1[0];				BuffCount1++;

	HexDataPort1 = (unsigned char)(RegAddr1);
	Bcc1 += HexDataPort1;
	ConvertToAscii1();
	Comm1Buff[BuffCount1] = DigitBuff1[1];				BuffCount1++;
	Comm1Buff[BuffCount1] = DigitBuff1[0];				BuffCount1++;

	if ((NumOfBytesPort1 == 4) || (NumOfBytesPort1 == 8) || (ReadWrite1 == 'B'))
	{
		HexDataPort1 = 0;
		Bcc1 += HexDataPort1;
		ConvertToAscii1();
		Comm1Buff[BuffCount1] = DigitBuff1[1];			BuffCount1++;
		Comm1Buff[BuffCount1] = DigitBuff1[0];			BuffCount1++;

		HexDataPort1 = BlockSizePort1;
		Bcc1 += HexDataPort1;
		ConvertToAscii1();
		Comm1Buff[BuffCount1] = DigitBuff1[1];			BuffCount1++;
		Comm1Buff[BuffCount1] = DigitBuff1[0];			BuffCount1++;

		HexDataPort1 = BlockSizePort1 * 2;
		Bcc1 += HexDataPort1;
		ConvertToAscii1();
		Comm1Buff[BuffCount1] = DigitBuff1[1];			BuffCount1++;
		Comm1Buff[BuffCount1] = DigitBuff1[0];			BuffCount1++;
	}
	if (StartingAddrPort1[0] == '0')
	{
		if (Plc1Dat1Lo == 1)
		{
			HexDataPort1 = 0xff;
			Bcc1 += HexDataPort1;
			ConvertToAscii1();
			Comm1Buff[BuffCount1] = DigitBuff1[1];		BuffCount1++;
			Comm1Buff[BuffCount1] = DigitBuff1[0];		BuffCount1++;
			Comm1Buff[BuffCount1] = 0x30;				BuffCount1++;
			Comm1Buff[BuffCount1] = 0x30;				BuffCount1++;
		}
		else
		{
			Comm1Buff[BuffCount1] = 0x30;	BuffCount1++;
			Comm1Buff[BuffCount1] = 0x30;	BuffCount1++;
			Comm1Buff[BuffCount1] = 0x30;	BuffCount1++;
			Comm1Buff[BuffCount1] = 0x30;	BuffCount1++;
			Bcc1 += 0;
		}
	}
	else
	{
		if (ReadWrite1 == 'B')
		{
			for (i = 0; i < (NumOfBytesPort1 / 2); i++)
			{
				HexDataPort1 = BGCMDQ1_Rec[0].LoWord[i] >> 8;
				Bcc1 += HexDataPort1;
				ConvertToAscii1();
				Comm1Buff[BuffCount1] = DigitBuff1[1];		BuffCount1++;
				Comm1Buff[BuffCount1] = DigitBuff1[0];		BuffCount1++;

				HexDataPort1 = BGCMDQ1_Rec[0].LoWord[i];
				Bcc1 += HexDataPort1;
				ConvertToAscii1();
				Comm1Buff[BuffCount1] = DigitBuff1[1];		BuffCount1++;
				Comm1Buff[BuffCount1] = DigitBuff1[0];		BuffCount1++;
			}
		}
		else
		{
			HexDataPort1 = Plc1Dat1Hi;
			Bcc1 += HexDataPort1;
			ConvertToAscii1();
			Comm1Buff[BuffCount1] = DigitBuff1[1];		BuffCount1++;
			Comm1Buff[BuffCount1] = DigitBuff1[0];		BuffCount1++;

			HexDataPort1 = Plc1Dat1Lo;
			Bcc1 += HexDataPort1;
			ConvertToAscii1();
			Comm1Buff[BuffCount1] = DigitBuff1[1];		BuffCount1++;
			Comm1Buff[BuffCount1] = DigitBuff1[0];		BuffCount1++;

			if (NumOfBytesPort1 == 4)
			{
				HexDataPort1 = Plc1Dat2Hi;
				Bcc1 += HexDataPort1;
				ConvertToAscii1();
				Comm1Buff[BuffCount1] = DigitBuff1[1];		BuffCount1++;
				Comm1Buff[BuffCount1] = DigitBuff1[0];		BuffCount1++;

				HexDataPort1 = Plc1Dat2Lo;
				Bcc1 += HexDataPort1;
				ConvertToAscii1();
				Comm1Buff[BuffCount1] = DigitBuff1[1];		BuffCount1++;
				Comm1Buff[BuffCount1] = DigitBuff1[0];		BuffCount1++;
			}
		}
	}

	HexDataPort1 = ~(Bcc1) + 1;
	ConvertToAscii1();
	Comm1Buff[BuffCount1] = DigitBuff1[1];		BuffCount1++;
	Comm1Buff[BuffCount1] = DigitBuff1[0];		BuffCount1++;

	Comm1Buff[BuffCount1] = 0x0D;				BuffCount1++;
	Comm1Buff[BuffCount1] = 0x0A;

	TempFrameLength1 = BuffCount1;
	FrameLength1 = TempFrameLength1;
	RecFrameLength1 = 0x0A;
}

void Plc1RdHeap(void)
{
	Bcc1 = 0;
	BuffCount1 = 0;
	EvalRegTyp1();

	Comm1Buff[BuffCount1] = ':';				BuffCount1++;

	HexDataPort1 = NodeIntrPort1;
	Bcc1 += HexDataPort1;
	ConvertToAscii1();
	Comm1Buff[BuffCount1] = DigitBuff1[1];		BuffCount1++;
	Comm1Buff[BuffCount1] = DigitBuff1[0];		BuffCount1++;

	if (BitOperationPort1)		HexDataPort1 = 0x02;
	else						HexDataPort1 = 0x03;

	Bcc1 += HexDataPort1;
	ConvertToAscii1();
	Comm1Buff[BuffCount1] = DigitBuff1[1];		BuffCount1++;
	Comm1Buff[BuffCount1] = DigitBuff1[0];		BuffCount1++;

	HexDataPort1 = (unsigned char)(RegAddr1 >> 8);
	Bcc1 += HexDataPort1;
	ConvertToAscii1();
	Comm1Buff[BuffCount1] = DigitBuff1[1];		BuffCount1++;
	Comm1Buff[BuffCount1] = DigitBuff1[0];		BuffCount1++;

	HexDataPort1 = (unsigned char)(RegAddr1);
	Bcc1 += HexDataPort1;
	ConvertToAscii1();
	Comm1Buff[BuffCount1] = DigitBuff1[1];		BuffCount1++;
	Comm1Buff[BuffCount1] = DigitBuff1[0];		BuffCount1++;

	HexDataPort1 = 0;
	Bcc1 += HexDataPort1;
	ConvertToAscii1();
	Comm1Buff[BuffCount1] = DigitBuff1[1];		BuffCount1++;
	Comm1Buff[BuffCount1] = DigitBuff1[0];		BuffCount1++;

	if ((StartingAddrPort1[0] == '0') || (StartingAddrPort1[0] == '1'))
		HexDataPort1 = 0x01;
	else
		HexDataPort1 = BlockSizePort1;

	Bcc1 += HexDataPort1;
	ConvertToAscii1();
	Comm1Buff[BuffCount1] = DigitBuff1[1];		BuffCount1++;
	Comm1Buff[BuffCount1] = DigitBuff1[0];		BuffCount1++;

	HexDataPort1 = (~Bcc1) + 1;
	ConvertToAscii1();
	Comm1Buff[BuffCount1] = DigitBuff1[1];		BuffCount1++;
	Comm1Buff[BuffCount1] = DigitBuff1[0];		BuffCount1++;

	Comm1Buff[BuffCount1] = 0x0D;				BuffCount1++;
	Comm1Buff[BuffCount1] = 0x0A;

	TempFrameLength1 = BuffCount1;
	FrameLength1 = TempFrameLength1;
	RecFrameLength1 = 0x0A;
}

void DummyHeapPort1(unsigned char NodeAddr1)
{
	volatile unsigned char i = 0;
	unsigned char NodeBlockSize1 = 0;
	unsigned char TempType;

	Bcc1 = 0;
	BuffCount1 = 0;

	Comm1Buff[BuffCount1] = ':';				BuffCount1++;

	HexDataPort1 = NodeAddr1;
	Bcc1 += HexDataPort1;
	ConvertToAscii1();
	Comm1Buff[BuffCount1] = DigitBuff1[1];		BuffCount1++;
	Comm1Buff[BuffCount1] = DigitBuff1[0];		BuffCount1++;

	TempType = Port1ModbusFirstRegType[NodeAddCount1];

	if (TempType == 1)			HexDataPort1 = 0x01;
	else if (TempType == 2)		HexDataPort1 = 0x02;
	else if (TempType == 3)		HexDataPort1 = 0x04;
	else 						HexDataPort1 = 0x03;

	Bcc1 += HexDataPort1;
	ConvertToAscii1();
	Comm1Buff[BuffCount1] = DigitBuff1[1];		BuffCount1++;
	Comm1Buff[BuffCount1] = DigitBuff1[0];		BuffCount1++;

	HexDataPort1 = Port1ModbusFirstAddr[NodeAddCount1] >> 8;
	Bcc1 += HexDataPort1;
	ConvertToAscii1();
	Comm1Buff[BuffCount1] = DigitBuff1[1];		BuffCount1++;
	Comm1Buff[BuffCount1] = DigitBuff1[0];		BuffCount1++;

	HexDataPort1 = Port1ModbusFirstAddr[NodeAddCount1];
	Bcc1 += HexDataPort1;
	ConvertToAscii1();
	Comm1Buff[BuffCount1] = DigitBuff1[1];		BuffCount1++;
	Comm1Buff[BuffCount1] = DigitBuff1[0];		BuffCount1++;

	HexDataPort1 = 0;
	Bcc1 += HexDataPort1;
	ConvertToAscii1();
	Comm1Buff[BuffCount1] = DigitBuff1[1];		BuffCount1++;
	Comm1Buff[BuffCount1] = DigitBuff1[0];		BuffCount1++;

	for (i = 0; i < 32; i++)
	{
		if (BlockSizeDummy1[i][0] == NodeAddr1)
		{
			NodeBlockSize1 = BlockSizeDummy1[i][1];
			break;
		}
	}

	if ((Port1ModbusFirstRegType[NodeAddCount1] == 2) || (Port1ModbusFirstRegType[NodeAddCount1] == 1))
		NodeBlockSize1 = 0;

	if (NodeBlockSize1 == 0)
		NodeBlockSize1 = 0x01;

	HexDataPort1 = NodeBlockSize1;
	Bcc1 += HexDataPort1;
	ConvertToAscii1();
	Comm1Buff[BuffCount1] = DigitBuff1[1];		BuffCount1++;
	Comm1Buff[BuffCount1] = DigitBuff1[0];		BuffCount1++;

	HexDataPort1 = ~(Bcc1) + 1;
	ConvertToAscii1();
	Comm1Buff[BuffCount1] = DigitBuff1[1];		BuffCount1++;
	Comm1Buff[BuffCount1] = DigitBuff1[0];		BuffCount1++;

	Comm1Buff[BuffCount1] = 0x0D;				BuffCount1++;
	Comm1Buff[BuffCount1] = 0x0A;

	TempFrameLength1 = BuffCount1;
	FrameLength1 = TempFrameLength1;
	RecFrameLength1 = 0x0A;
}

void GetPrevFrame1(void)
{
	unsigned char cnt1, TempCnt1;
	FrameLength1 = PrevFrameLength1;
	RecFrameLength1 = PrevRecFrameLength1;
	BlockSizePort1 = PrevBlockSizePort1;

	TempCnt1 = 128;
	for (cnt1 = 0; cnt1 <= TempFrameLength1; cnt1++)
	{
		Comm1Buff[cnt1] = Comm1Buff[TempCnt1];
		TempCnt1++;
	}
}

void CopyCurrentFrame1(void)
{
	unsigned char cnt1, TempCnt1;
	PrevFrameLength1 = FrameLength1;
	PrevRecFrameLength1 = RecFrameLength1;
	PrevBlockSizePort1 = BlockSizePort1;

	TempCnt1 = 128;
	for (cnt1 = 0; cnt1 <= TempFrameLength1; cnt1++)
	{
		Comm1Buff[TempCnt1] = Comm1Buff[cnt1];
		TempCnt1++;
	}
}

void CheckDummyHeapResponse1(void)
{
	CheckResponse1();
	GetResponse1 = 1;
	Plc1Present = 1;
}

unsigned char CheckResponse1(void)
{
	unsigned char ErrorReply1;
	unsigned char CalculatedBcc1, ResponseBcc1;

	ResponseBcc1 = CalculatedBcc1 = 0;

	BuffCount1 = ReceiveBuffLength1 - 3;
	ConvertAsciiToHex1();
	ResponseBcc1 = HexDataPort1;

	for (BuffCount1 = 1; BuffCount1 < (ReceiveBuffLength1 - 3); BuffCount1++)
	{
		ConvertAsciiToHex1();
		CalculatedBcc1 += HexDataPort1;
	}
	CalculatedBcc1 = ~CalculatedBcc1 + 1;

	if (ResponseBcc1 != CalculatedBcc1) ErrorReply1 = 1;
	else 								ErrorReply1 = 0;

	if ((Comm1Buff[3] & 0x38) == 0x38 || (ErrorReply1))
		TagErrorFlag1 = 1;
	else
		TagErrorFlag1 = 0;

	if (TagErrorFlag1 == 1)
		return 1;
	else
		return 0;
}

void UpdateTag1Data(void)
{
	Plc1Present = 1;

	if ((Comm1Buff[4] == '1') || (Comm1Buff[4] == '2'))
		BitOperationPort1 = 1;
	else
		BitOperationPort1 = 0;

	TempCountPort1 = BlockSizePort1;
	if (CurrBlockPort1 == 0)
	{
		CurrTagPtrPort1 = 0;
	}

	UpdateNodeStatus1();
	UpdateTagStatus1();

	if (!BitOperationPort1)
	{
		BuffCount1 = 7;
		while (TempCountPort1)
		{
			UpdateTagError1();
			BuffCount1 += 2;
			ConvertAsciiToHex1();
			TagTable1[CurrTagPtrPort1] = HexDataPort1;
			CurrTagPtrPort1++;
			BuffCount1 -= 3;
			ConvertAsciiToHex1();
			TagTable1[CurrTagPtrPort1] = HexDataPort1;
			CurrTagPtrPort1++;
			TempCountPort1--;
			BuffCount1 += 3;
		}
	}
	else
	{
		UpdateTagError1();
		BuffCount1 = 8;
		if (Comm1Buff[BuffCount1] == '0')
			TagTable1[CurrTagPtrPort1] = 0x00;
		else
			TagTable1[CurrTagPtrPort1] = 0x01;

		CurrTagPtrPort1++;
		TagTable1[CurrTagPtrPort1] = 0x00;
		CurrTagPtrPort1++;
	}
}

void UpdateRecipeData1(void)
{
	unsigned int i = 0;

	Plc1Present = 1;
	if (CheckResponse1() == 1)
	{
		TaskIgnore = 1;
	#ifdef STM32F730_Processor
		TaskIgnore1 = 1;
	#endif
		return;
	}

	if ((Comm1Buff[4] == '1') || (Comm1Buff[4] == '2'))
		BitOperationPort1 = 1;
	else
		BitOperationPort1 = 0;

	if (BitOperationPort1)
	{
		BuffCount1 = 8;
		BGCMDQ1[0].LoWord[0] = 0x0000;
		if (Comm1Buff[BuffCount1] == '1')
			BGCMDQ1[0].LoWord[0] |= 0x0001;
	}
	else
	{
		BuffCount1 = 7;
		TempCountPort1 = BlockSizePort1;
		for (i = 0; i < TempCountPort1; i++)
		{
			ConvertAsciiToHex1();
			BGCMDQ1[0].LoWord[i] = HexDataPort1;
			BGCMDQ1[0].LoWord[i] = BGCMDQ1[0].LoWord[i] << 8;
			BuffCount1++;
			ConvertAsciiToHex1();
			BGCMDQ1[0].LoWord[i] |= HexDataPort1;
			BuffCount1++;
		}
	}
}

void UpdateReadCommandQ1(void)
{
	unsigned int i = 0;
	
	Plc1Present = 1;
	if (CheckResponse1() == 1)
	{
		TaskIgnore = 1;
	#ifdef STM32F730_Processor
		TaskIgnore1 = 1;
	#endif
		return;
	}

	if ((Comm1Buff[4] == '1') || (Comm1Buff[4] == '2'))
		BitOperationPort1 = 1;
	else
		BitOperationPort1 = 0;

	if (BitOperationPort1)
	{
		BuffCount1 = 8;
		CMDQ1[0].LoWord[0] = 0x00;
		if (Comm1Buff[BuffCount1] == '1')
			CMDQ1[0].LoWord[0] |= 0x01;
	}
	else
	{
		BuffCount1 = 7;
		TempCountPort1 = BlockSizePort1;
		for (i = 0; i < TempCountPort1; i++)
		{
			ConvertAsciiToHex1();
			CMDQ1[0].LoWord[i] = HexDataPort1;
			CMDQ1[0].LoWord[i] = CMDQ1[0].LoWord[i] << 8;
			BuffCount1++;
			ConvertAsciiToHex1();
			CMDQ1[0].LoWord[i] |= HexDataPort1;
			BuffCount1++;
		}
	}
	CMDQ1[0].DataUpdate = 0;
}

void CheckPlc1WrResp(void)
{
	//unsigned char cal_BCC = 0, Res_BCC = 0, Bcc_Loc = 0;

	//Bcc_Loc = ReceiveBuffLength1 - 3;
	//Res_BCC = ConvertASCIItoHex1(&Comm1Buff[Bcc_Loc], &Comm1Buff[Bcc_Loc + 1]);
	//cal_BCC = Bcc_Calculate1(Comm1Buff, Bcc_Loc);

	//if (cal_BCC != Res_BCC)
	//	WriteError1 = 1;
	//else
		WriteError1 = CheckResponse1();
}

void ConvertToAscii1(void)
{
	if ((HexDataPort1 & 0x0f) < 0x0A)			DigitBuff1[0] = (HexDataPort1 & 0x0f) + 0x30;
	else										DigitBuff1[0] = (HexDataPort1 & 0x0f) + 0x37;

	if (((HexDataPort1 & 0xf0) >> 4) < 0x0A)	DigitBuff1[1] = ((((HexDataPort1 & 0xf0) >> 4) & 0x0f) + 0x30);
	else										DigitBuff1[1] = ((((HexDataPort1 & 0xf0) >> 4) & 0x0f) + 0x37);
}

//unsigned char Bcc_Calculate1(unsigned char* resp, unsigned char Bcc_End)
//{
//	unsigned char i, BCC = 0;
//	for (i = 1; i < Bcc_End; )
//	{
//		BCC += ConvertASCIItoHex1(&resp[i], &resp[i + 1]);
//		i += 2;
//	}
//
//	BCC = ~BCC + 1;
//	return(BCC);
//}
//
//unsigned char ConvertASCIItoHex1(unsigned char* Var1, unsigned char* Var2)
//{
//	unsigned char HexData;
//
//	if (*Var1 > 0x39)		HexData = ((*Var1 - 0x37) << 4) & 0x0F0;
//	else					HexData = ((*Var1 - 0x30) << 4) & 0x0F0;
//
//	if (*Var2 > 0x39)		HexData |= (*Var2 - 0x37);
//	else					HexData |= (*Var2 - 0x30);
//
//	return(HexData);
//}

void ConvertAsciiToHex1(void)
{
	if (Comm1Buff[BuffCount1] > 0x39)	HexDataPort1 = ((Comm1Buff[BuffCount1] - 0x37) << 4) & 0x0F0;
	else 								HexDataPort1 = ((Comm1Buff[BuffCount1] - 0x30) << 4) & 0x0F0;

	BuffCount1++;

	if (Comm1Buff[BuffCount1] > 0x39)	HexDataPort1 |= (Comm1Buff[BuffCount1] - 0x37);
	else 								HexDataPort1 |= (Comm1Buff[BuffCount1] - 0x30);
}

void EvalRegTyp1(void)
{
	RegLenPort1 = Port1Plc[2] - 0x30;
	RegLenPort1--;
	PlcReg0Port1 = StartingAddrPort1[RegLenPort1--];
	PlcReg1Port1 = StartingAddrPort1[RegLenPort1--];
	PlcReg2Port1 = StartingAddrPort1[RegLenPort1--];
	PlcReg3Port1 = StartingAddrPort1[RegLenPort1--];
	PlcRegTypPort1 = StartingAddrPort1[RegLenPort1];

	if ((PlcRegTypPort1 == 'X') || (PlcRegTypPort1 == 'Y'))
	{
		RegAddr1 = ((PlcReg3Port1 - 0x30) * 512) + ((PlcReg2Port1 - 0x30) * 64) + ((PlcReg1Port1 - 0x30) * 8) + (PlcReg0Port1 - 0x30);
	}
	else
	{
		RegAddr1 = ((PlcReg3Port1 - 0x30) * 1000) + ((PlcReg2Port1 - 0x30) * 100) + ((PlcReg1Port1 - 0x30) * 10) + (PlcReg0Port1 - 0x30);
	}

	BitOperationPort1 = 0;

	switch (PlcRegTypPort1)
	{
		case 'M':
			RegAddr1 = RegAddr1 + 0x800;
			BitOperationPort1 = 1;
			break;

		case 'Y':
			RegAddr1 = RegAddr1 + 0x500;
			BitOperationPort1 = 1;
			break;

		case 'X':
			RegAddr1 = RegAddr1 + 0x400;
			BitOperationPort1 = 1;
			break;

		case 'D':
			if (PlcReg3Port1 == '1')
			{
				RegAddr1 = RegAddr1 - 1000;
				RegAddr1 = RegAddr1 + 0x13E8;
			}
			else
			{
				RegAddr1 = RegAddr1 + 0x1000;
			}
			break;

		case 'T':
			RegAddr1 = RegAddr1 + 0x600;
			break;

		case 'C':
			RegAddr1 = RegAddr1 + 0xE00;
			break;
	}
}

void Com1DelayTask(void)
{
	Com1Delay = 0;
	SetDirectionPort1();
	KickStart1();
}

void ReceiveModbusDelay1(void)
{
	if (usThreeHalfRec1)		usThreeHalfRec1--;
	if (usThreeHalfRec1 == 0)	counter = 0;
}

void ModbusSlaveTxDelay1(void)
{
	if (ucThreeHalfAfterRecFlag1)
	{
		if (usThreeHalfAfterRec1)	usThreeHalfAfterRec1--;
		if (usThreeHalfAfterRec1 == 0)
		{
			ucThreeHalfAfterRecFlag1 = 0;
			SetDirectionPort1();
			KickStart1();
		}
	}
}

void DriverDelayHandlerCom1(void)
{
	ReceiveModbusDelay1();
	ModbusSlaveTxDelay1();
}