#ifndef ADSR_ENVELOPE_H
#define ADSR_ENVELOPE_H

#include <iostream>
#include <array>



//definig 4 states of ADSR
#define ATTACK 0x00
#define DECAY 0x01
#define SUSTAIN 0x02
#define RELEASE 0x03
//************************
#define GATE_ON 0x100
#define GATE_OFF 0x101


#define TIME_PRECISION 1000 //this defines a thousand  of elements in one second, thus milisecond

#define ATTACK_MAX 25000
#define DECAY_MAX 25000
#define RELEASE_MAX 25000


using namespace std;

class ADSR_Envelope
{
    public:
        //memebers
        bool GATE;

        ADSR_Envelope();
        virtual ~ADSR_Envelope();

        //geters
        float getAmplitude();
        bool getGATE();

        //envelope getters
        int getAttack();
        int getDecay();
        int getRelease();

        //setters
        void resetEnvelope(); //occurs when provided gate is off

        void setGATE(bool);

        void setAttack(float);
        void setDecay(float);

        //generators
        void generateEnvelope();


        //debugging
        void printEnvelope();
    protected:
    private:
        //members
        int STATE; //FSM style that siwtches between the states
        int COUNTER; //runs through envelope arrays


        int Attack;
        int Decay;

        //envelope arrays
        array<float,ATTACK_MAX> AttackTimeline;
        array<float,DECAY_MAX> DecayTimeline;


};

#endif // ADSR_ENVELOPE_H
