/*
		Rutina para transmision serial por software con un solo PIN
		Velocidad:	1200 -> 1/1200 = 833 us => tiempo de bit
		Start bit: 	1
		Bits: 		7
		Paridad: 	Par 
		Stop bit: 	1
		Bits totales a transmitir: 10
		Logica Negativa
*/
# define bit_test(D,i) (D & (0x01 << i))

int cont=0;

/*
	Recibe byte bit a bit y lo compone en un char
*/
void TranByte(char cmd){
int i, cont=0;
char temp;
short parity=false;

    DATAPINDIR = false;//	set_tris_e(0b00000000);
	temp=cmd;

	for(i=0;i<7;i++){
		 if(bit_test(temp,i))
			cont++;	 
	}		

	if(cont%2==0)
		parity=true;
	else
		parity=false;

	__delay_us(DELAY);

    DATAPINWRITE=true;    //	output_high(DATAPIN);
	__delay_us(DELAY);

	for(i=0;i<7;i++){
		if(cmd&0x01)
            DATAPINWRITE=false;  //output_bit(DATAPIN,0);
		else
            DATAPINWRITE=true;   //output_bit(DATAPIN,1);	

        cmd>>=1;    //		shift_right(&cmd,1,0);
		__delay_us(DELAY);
	}	
    DATAPINWRITE=parity; //	output_bit(DATAPIN,parity);
	__delay_us(DELAY);
    DATAPINWRITE=false; //	output_low(DATAPIN);
	__delay_us(DELAY);
}

/*
	Toma un string y lo transmite byte a byte
*/
void PutStrSerial(char *string){
	for(;*string!='\0';string++)
			TranByte(*string);
}
/*
	Recibe un byte y lo compone bit a bit, le quita el bit de paridad
	No posee comprobación
*/
char GetStrSerial(void){
unsigned char cmd=0;
unsigned int i;
unsigned int idx = 0;
long int cont=0;

    DATAPINDIR = true;//	set_tris_b(0b01000000);
        //	output_float(DATAPIN);

	memset(Buffer,'\0',MAXBUFFERSIZE);

	while( cmd != 0x0a && idx<MAXBUFFERSIZE) {
	
        if(DATAPINREAD == false){   //if( !input(DATAPIN)){
			for(cont=0;cont<1500;cont++){
				if(DATAPINREAD == true)//if(input(DATAPIN)) 
					break;
				__delay_us(10);
			}
		}
	    
		if( cont < 1500 ) {
	
			__delay_us(DELAY + DELAY/3);
			cmd=0;
				for(i=0;i<7;i++){
                    cmd=!DATAPINWRITE<<i;  //cmd |= !input( DATAPIN ) << i ;
					__delay_us(DELAY);
				}
				__delay_us(DELAY);
		}
		Buffer[ idx++] = cmd;
	}
	return cmd;
}

void MuestraSegundo(int* sec, int* samp){
int i;
char str[4];

	memset(str,'\0',4);

	for(i=0;i<3;i++)
		str[i] = Buffer[i+1];
	
	sec = atoi(str);
	samp =Buffer[4] - '0';
}
