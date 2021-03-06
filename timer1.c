#include "globaldefine.h"
#include "global.h"

//===========================================================//
// But: Init Timer1  pour generer 1 signal � 1MHz (1�sms) en interruption
//===========================================================//

// D�clarations variables externes

void T1_Init(void)
{
	TIM_TIMERCFG_Type		Timer_Config_Structure; // structures pour passer les valeurs d'initialisation d'un timer
  TIM_MATCHCFG_Type		Timer_MatchConfig_Structure2;
	
	// Timer1  Initialization
	Timer_Config_Structure.PrescaleOption = TIM_PRESCALE_USVAL;						// Timer en Mode us
	Timer_Config_Structure.PrescaleValue	= 1;						// TC increment� de 1 chaque 1us

	TIM_Init(LPC_TIM1, TIM_TIMER_MODE,&Timer_Config_Structure);
	

	// Configuration of Match channels
	Timer_MatchConfig_Structure2.MatchChannel = 0;													// Use channel 1, MR0 for both Timers
	Timer_MatchConfig_Structure2.IntOnMatch   = TRUE;											// En Timer IT			 qd MR0 = TC Register
	Timer_MatchConfig_Structure2.ResetOnMatch = TRUE;											// En Timer RST			 qd MR0 = TC Register
	Timer_MatchConfig_Structure2.StopOnMatch  = FALSE;											// No Stop Timer     qd MR0 = TC Register
	Timer_MatchConfig_Structure2.ExtMatchOutputType = TIM_EXTMATCH_NOTHING;	// Toggle MATx.y pin qd MR0 = TC Register
	
	Timer_MatchConfig_Structure2.MatchValue = 1;		// Match Value Timer1
	TIM_ConfigMatch(LPC_TIM1,&Timer_MatchConfig_Structure2);								// Config Timer1
	
	
	TIM_Cmd(LPC_TIM1,ENABLE);																							// Start Timer1
	NVIC_EnableIRQ(TIMER1_IRQn);																					// Autoriser interruption
}

/* Code de l'interruption. Est d�clench�e si TC = MR, c'est-�-dire toutes les 1�s pour timer 1 */
void TIMER1_IRQHandler(void){
	trigger++; // cf ultrason
	echo++;
	if (trigger == 1 && modeUS == 1) { //boucle it�rative de 250 envois de triggers
		GPIO_SetValue(0, (1<<24));
	} else if (trigger == 5 && modeUS == 1) {
		GPIO_ClearValue(0, (1<<24));
		nbr++; //On incr�mente un nombre d'envoi de triggers
		echo = 0;
		GPIO_IntCmd(0,(1<<25),1);
	}
		
	
	
	
	if (trigger>40000) {
		trigger = 0;
	}
	if(nbr == 250) {
		modeUS = 0;
		nbr = 0;
	}
	
TIM_ClearIntPending(LPC_TIM1,TIM_MR0_INT);
}
