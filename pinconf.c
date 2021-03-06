
#include "globaldefine.h"
#include "global.h"

void pin_Configuration(void);

void pin_Configuration(void)
{
  // déclaration des structures de configuration
	
	// Manu
	PINSEL_CFG_Type maconfig;
	
	// Rolando
	PINSEL_CFG_Type maconfigRolando;
	PINSEL_CFG_Type maconfig2Rolando;
	
	// Guillaume
	PINSEL_CFG_Type bouton2;
  PINSEL_CFG_Type trigger2;
  PINSEL_CFG_Type echo2;
	NVIC_EnableIRQ(EINT3_IRQn);
	
	
	
	// configuration des GPIOs Manu
	// directement dans les registres
	//LPC_GPIO0->FIODIR &= ~(1<<0);
	//LPC_GPIO0 ->FIOMASK = ~(1<<0);
	// en utilisant une fonction 
	GPIO_SetDir(1,0x200,1);
  GPIO_SetDir(0,0,0);
	
	// configuration des pinsel
	maconfig.Portnum = PINSEL_PORT_1;
	maconfig.Pinnum =PINSEL_PIN_9;
	maconfig.Funcnum = PINSEL_FUNC_0;
	maconfig.Pinmode =PINSEL_PINMODE_PULLDOWN;
	maconfig.OpenDrain = PINSEL_PINMODE_NORMAL;
  PINSEL_ConfigPin(&maconfig);
	
	
	// configuration des GPIOs Rolando

	
	// configuration des pinsel
	maconfigRolando.Portnum = PINSEL_PORT_0; //on utilise le port 0
	maconfigRolando.Pinnum =PINSEL_PIN_10;  //sur la broche 10
	maconfigRolando.Funcnum = PINSEL_FUNC_3;  //au mode 3
	maconfigRolando.Pinmode =PINSEL_PINMODE_PULLDOWN;
	maconfigRolando.OpenDrain = PINSEL_PINMODE_NORMAL;
  PINSEL_ConfigPin(&maconfigRolando);
	
	maconfig2Rolando.Portnum = PINSEL_PORT_0; //on utilise le port 0
	maconfig2Rolando.Pinnum =PINSEL_PIN_5;  //sur la broche 5
	maconfig2Rolando.Funcnum = PINSEL_FUNC_3;  //au mode 3
	maconfig2Rolando.Pinmode =PINSEL_PINMODE_PULLDOWN;
	maconfig2Rolando.OpenDrain = PINSEL_PINMODE_NORMAL;
  PINSEL_ConfigPin(&maconfig2Rolando);
	
	
	// Configuration des GPIOs Guillaume
	
	
	// configuration des pinsel Echo
  echo2.Portnum = PINSEL_PORT_0;
  echo2.Pinnum =PINSEL_PIN_25;
  echo2.Funcnum = PINSEL_FUNC_0;
  echo2.Pinmode =PINSEL_PINMODE_PULLUP;
  echo2.OpenDrain = PINSEL_PINMODE_NORMAL;
  PINSEL_ConfigPin(&echo2);
   
  // configuration des pinsel Trigger
  trigger2.Portnum = PINSEL_PORT_0;
  trigger2.Pinnum =PINSEL_PIN_24;
  trigger2.Funcnum = PINSEL_FUNC_0;
  trigger2.Pinmode =PINSEL_PINMODE_PULLUP;
  trigger2.OpenDrain = PINSEL_PINMODE_NORMAL;
  PINSEL_ConfigPin(&trigger2);
   
  // configuration des pinsel Bouton
  bouton2.Portnum = PINSEL_PORT_0;
  bouton2.Pinnum =PINSEL_PIN_26;
  bouton2.Funcnum = PINSEL_FUNC_0;
  bouton2.Pinmode =PINSEL_PINMODE_PULLUP;
  bouton2.OpenDrain = PINSEL_PINMODE_NORMAL;
  PINSEL_ConfigPin(&bouton2);
	
	GPIO_SetDir(0,(1<<24),1);
	GPIO_SetDir(0,(1<<25),0);
	GPIO_SetDir(0,(1<<26),0);
   
  GPIO_IntCmd(0,(1<<26),1);
	
}
