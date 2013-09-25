/******************************************/
/*  Fender Rhodes Electric Piano Subclass */
/*  of Algorithm 5 (TX81Z) Subclass of    */ 
/*  4 Operator FM Synth                   */
/*  by Perry R. Cook, 1995-96             */ 
/******************************************/

#include "Rhodey.h"

Rhodey :: Rhodey() : FM4Alg5()
{
  // Concatenate the STK RAWWAVE_PATH to the rawwave file
  char file1[128];
  char file2[128];
  char file3[128];
  char file4[128];
  strcpy(file1, RAWWAVE_PATH);
  strcpy(file2, RAWWAVE_PATH);
  strcpy(file3, RAWWAVE_PATH);
  strcpy(file4, RAWWAVE_PATH);
  this->loadWaves(strcat(file1,"rawwaves/sinewave.raw"),
                  strcat(file2,"rawwaves/sinewave.raw"),
                  strcat(file3,"rawwaves/sinewave.raw"),
                  strcat(file4,"rawwaves/fwavblnk.raw"));
  this->setRatio(0,(MY_FLOAT) 1.0);
  this->setRatio(1,(MY_FLOAT) 0.5);
  this->setRatio(2,(MY_FLOAT) 1.0);
  this->setRatio(3,(MY_FLOAT) 15.0);
  gains[0] = __FM4Op_gains[99];
  gains[1] = __FM4Op_gains[90];
  gains[2] = __FM4Op_gains[99];
  gains[3] = __FM4Op_gains[67];
  adsr[0]->setAllTimes((MY_FLOAT) 0.001,(MY_FLOAT) 1.50,(MY_FLOAT) 0.0,(MY_FLOAT) 0.04);
  adsr[1]->setAllTimes((MY_FLOAT) 0.001,(MY_FLOAT) 1.50,(MY_FLOAT) 0.0,(MY_FLOAT) 0.04);
  adsr[2]->setAllTimes((MY_FLOAT) 0.001,(MY_FLOAT) 1.00,(MY_FLOAT) 0.0,(MY_FLOAT) 0.04);
  adsr[3]->setAllTimes((MY_FLOAT) 0.001,(MY_FLOAT) 0.25,(MY_FLOAT) 0.0,(MY_FLOAT) 0.04);
  twozero->setGain((MY_FLOAT) 1.0);
}  

Rhodey :: ~Rhodey()
{

}

void Rhodey :: setFreq(MY_FLOAT frequency)
{    
  baseFreq = frequency * (MY_FLOAT) 2.0;
  waves[0]->setFreq(baseFreq * ratios[0]);
  waves[1]->setFreq(baseFreq * ratios[1]);
  waves[2]->setFreq(baseFreq * ratios[2]);
  waves[3]->setFreq(baseFreq * ratios[3]);
}

void Rhodey :: noteOn(MY_FLOAT freq, MY_FLOAT amp)
{
  gains[0] = amp * __FM4Op_gains[99];
  gains[1] = amp * __FM4Op_gains[90];
  gains[2] = amp * __FM4Op_gains[99];
  gains[3] = amp * __FM4Op_gains[67];
  this->setFreq(freq);
  this->keyOn();
#if defined(_debug_)        
  printf("Rhodey : NoteOn: Freq=%lf Amp=%lf\n",freq,amp);
#endif    
}

