#include "ADSR_Envelope.h"
#include <math.h>
#include <algorithm>


ADSR_Envelope::ADSR_Envelope()
{
    GATE = false;
    STATE = ATTACK;
    Attack = 20000;
    Decay = 1000; //miliseconds
    generateEnvelope(); /* generating envelope based on parameters */
                        /* Note: information is actually being stored */
                        /*       in the envelope arrays               */

    cout << "A_MAX" << ATTACK_MAX << endl;
}

ADSR_Envelope::~ADSR_Envelope()
{
    //dtor
}

float ADSR_Envelope::getAmplitude()
{
    float amp = 0;
    if(GATE){
        switch(STATE){
            case ATTACK:

                amp = pow(10,(float) COUNTER/ (float) (Attack/2.0)) / 100.0;
                COUNTER++;
                if(COUNTER > Attack){
                    COUNTER = 0;
                    STATE = ATTACK;
                    GATE = false;
                }
            break;
            case DECAY:
                amp = DecayTimeline[COUNTER];
                COUNTER++;
                if(COUNTER > Decay){
                    COUNTER = 0;
                    STATE = SUSTAIN;
                }
            break;
            //case SUSTAIN:
            //break;
        }
    }
    return amp;
}

void ADSR_Envelope::printEnvelope()
{
    cout << "Print Attack" << Attack << endl;
    for(int i = 0;i <= Attack;++i){
        cout << " A: " << AttackTimeline[i] << endl;;
    }
    cout << "Print Decay" << Decay << endl;
    for(int i = 0;i <= Decay;++i){
        //cout << " D: " << DecayTimeline[i] << endl;;
    }
}


void ADSR_Envelope::generateEnvelope()
{

    int i = 0;
/*
    //generate attack formula: 100/attack * x
    int i = 0;

    for(i;i <= Attack;++i){
        AttackTimeline[i] = (100.0/ (float) Attack)  * (float) i;
    }

    cout << "i: " << i<< endl;

    for(i;i < ATTACK_MAX;++i){
        AttackTimeline[i] = -1;
    }
    //*******************************************
*/
    //generate decay
    i = 0; //reset i
    int expInterval = Decay/2;

    vector<float> v(Decay+1);

    for(i;i <= Decay;++i){
        v[i] = pow(10,(float)i/ (float) expInterval);
    }
    reverse(v.begin(),v.end());

    i = 0;
    for(i;i <= Decay;++i){
        DecayTimeline[i] = v[i];
    }


    for(i;i < DECAY_MAX;++i){
        DecayTimeline[i] = -1;
    }

    //now we reverse the function so it becomes descending
    //reverse(DecayTimeline.begin(),DecayTimeline.end());
    //**************************************************


}
