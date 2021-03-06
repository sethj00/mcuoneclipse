/*
 * main implementation: use this 'C' sample to create your own application
 *
 */

#include "derivative.h" /* include peripheral declarations */
#include <stdio.h>
#include "ConsoleIO.h"

#define RED         (18)
#define RED_SHIFT   (1<<RED)

#define RED_OFF     (GPIOB_PSOR = RED_SHIFT)
#define RED_ON      (GPIOB_PCOR = RED_SHIFT)
#define RED_TOGGLE  (GPIOB_PTOR = RED_SHIFT)

static void InitLED(void) {
  /* Turn on clock to PortB module */
  SIM_SCGC5 |= SIM_SCGC5_PORTB_MASK;

  /* Set the PTB18 pin multiplexer to GPIO mode */
  PORTB_PCR18 = PORT_PCR_MUX(1);

  /* Set the initial output state to high */
  GPIOB_PSOR |= RED_SHIFT;

  /* Set the pins direction to output */
  GPIOB_PDDR |= RED_SHIFT;
}

static void NegLED(void) {
  RED_TOGGLE;
}

static char buffer[64];

int main(void) {
	int counter = 0;
	
	ConsoleIO_Init();
	InitLED();
  printf("Hello world!\r\n");
	for(;;) {	   
	  counter++;
	  printf("Enter a string:\r\n");
    if (gets(buffer)!=NULL) {
      printf("you entered: %s\r\n", buffer);
    }
	  if ((counter%32)==0) {
      NegLED();
	  }
	}
	
	return 0;
}
