
char Medicion1[10];
char Medicion2[10];
char Medicion3[10];
char Medicion4[10];
char Medicion5[10];
char Medicion6[10];

float Medicion[6];

char Ack[3]="0!";
char Id[4]="0I!";
char AQuery[3]="?!";

void Marca(void){
    TRISA=false;
    DATAPINWRITE=0;
}

void Espacio(void){
    TRISA=false;
    DATAPINWRITE=1;
}

void SeparaD0(void){
int i;
	for(i=0;i<9;i++)
		Medicion1[i]=Buffer[i+1];
	for(i=0;i<9;i++)
		Medicion2[i]=Buffer[i+10];
	for(i=0;i<9;i++)
		Medicion3[i]=Buffer[i+19];

	Medicion[0]=atof(Medicion1);
	Medicion[1]=atof(Medicion2);
	Medicion[2]=atof(Medicion3);

//	for(i=0;i<3;i++)	
//		printf("Medicion[%i]=%4.4f\r\n",i,Medicion[i]);
}

void SeparaD1(void){
int i;
	for(i=0;i<9;i++)
		Medicion4[i]=Buffer[i+1];
	for(i=0;i<9;i++)
		Medicion5[i]=Buffer[i+10];
	for(i=0;i<9;i++)
		Medicion6[i]=Buffer[i+19];

	Medicion[3]=atof(Medicion4);
	Medicion[4]=atof(Medicion5);
	Medicion[5]=atof(Medicion6);

//	for(i=0;i<3;i++)	
//		printf("Medicion[%i]=%4.4f\r\n",i+3,Medicion[i+3]);
}

void WakeUp(void){
	Espacio();
	__delay_us(SPACING_DELAY);
	Marca();	
	__delay_us(MARKING_DELAY);
}

void Acknowledge(void){
	WakeUp();
	PutStrSerial(Ack);
	GetStrSerial();
}

void SendIdentification(void){
	WakeUp();
	PutStrSerial(Id);
	GetStrSerial();
//	printf("%s\r\n",buffer);
}

void AddressQueryCommand(void){
	WakeUp();
	PutStrSerial(AQuery);
	GetStrSerial();
//	printf("%s\r\n",buffer);
}

void ChangeAddress(char NuevoAddress,char ViejoAddress){
	WakeUp();
	TranByte(ViejoAddress);
	TranByte('A');
	TranByte(NuevoAddress);
	TranByte('!');
}

void StartMeasurement(char address){
	WakeUp();
	TranByte(address);
	TranByte('M');
	TranByte('!');
	GetStrSerial();	
//	printf("%s\r\n",buffer);	
}

void SendData(char address){
	WakeUp();
	TranByte(address);
	TranByte('D');
	TranByte('0');	
	TranByte('!');	
	GetStrSerial();
	SeparaD0();
	TranByte(address);
	TranByte('D');
	TranByte('1');	
	TranByte('!');	
	GetStrSerial();	
	SeparaD1();	
}
