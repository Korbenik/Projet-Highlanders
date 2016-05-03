// fichier contenant l'importation des variables globales de l'application
// � inclure dans les autres fichiers que le main

#include "globaldefine.h"

extern int toto;
extern char bufferTX[64]; // buffer pour l'affichage sur uart0
extern int n;
extern int TIMER0_VAR100US; // Base de temps de 100 us pour timer0, se reset pour des raisons pratique
extern int TIMER0_VAR100USROLAND; // Sp�cial Roland
extern int TIMER0_TEMPS; // D�finit le temps "absolu" depuis le d�but du timer0 (*100us)
extern int BIP;                // "Bool�en" qui indique si le bip est actif
extern int NB_BIP;
extern int MATCH_BIP;
extern int MATCH_VALUE_FQBIP;
extern int echo;
extern int trigger;