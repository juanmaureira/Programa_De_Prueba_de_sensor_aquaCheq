#ifndef SDI12_H
#define	SDI12_H
 
#ifndef _XC_H_
  #include <xc.h>
#endif

# define	MARKING_DELAY	8330
# define	SPACING_DELAY	12000

void Marca(void);
void Espacio(void);
void SeparaD0(void);
void SeparaD1(void);
void WakeUp(void);
void Acknowledge(void);
void SendIdentification(void);
void AddressQueryCommand(void);
void ChangeAddress(char NuevoAddress,char ViejoAddress);
void StartMeasurement(char address);
void SendData(char address);


#endif