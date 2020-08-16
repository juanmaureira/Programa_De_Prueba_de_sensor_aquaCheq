#ifndef SERIALSDI12_H
#define	SERIALSDI12_H
 
#ifndef _XC_H_
  #include <xc.h>
#endif


# include <string.h>

#define	DATAPINREAD     PORTAbits.RA0	
#define DATAPINWRITE    LATAbits.LA0
#define DATAPINDIR      TRISAbits.RA0

void TranByte(char cmd);
void PutStrSerial(char *string);
char GetStrSerial(void);
void MuestraSegundo(int *sec, int *samp);

#endif