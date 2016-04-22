#include <SFML/Audio.hpp>
#include <cmath>
#include <iostream>
#include <SFML/Graphics.hpp>
#include "Pixel.h"
#include "ADSR_Envelope.h"


using namespace std;

sf::Pixel d;

//sf::Vector2f v(2.0,4.0);

//p.getPosition(v)

int main() {
    const unsigned SAMPLES = 44100 * 10;
    const unsigned SAMPLE_RATE = 44100;
    const unsigned AMPLITUDE = 30000;

    sf::Int16 raw[SAMPLES];


    ADSR_Envelope e;


    const double TWO_PI = 6.28318;
    double increment = 440./44100/2;
    double x = 0;
    for (unsigned i = 0; i < SAMPLES; i++) {
        int amp = .05*i;
        if(amp > 30000){
            amp = 30000;
        }
        raw[i] = AMPLITUDE * sin(x*TWO_PI);
        x += increment;
    }





        sf::SoundBuffer Buffer;
    if (!Buffer.loadFromSamples(raw, SAMPLES, 1, SAMPLE_RATE)) {
        std::cerr << "Loading failed!" << std::endl;
        return 1;
    }




    //e.printEnvelope();

    sf::Sound Sound;
    Sound.setBuffer(Buffer);
    Sound.setLoop(false);
    Sound.setVolume(100);


    sf::Sound Sound2;
    Sound2.setBuffer(Buffer);
    Sound2.setLoop(false);
    Sound2.setVolume(100);



    Sound.play();
    float i = 0;

    //float rate = 1;

    int64_t timer = 0;
    sf::Clock deltaClock;
    e.GATE = true;

    while (1) {

        //e.GATE = true;

        //sf::sleep(sf::milliseconds(1));

        cout << "Status " << Sound.getStatus() << endl;
        if(!Sound.getStatus()){
            Sound2.play();
            sf::sleep(sf::milliseconds(10000));
        }

    /*
        Sound.setVolume(i);

        i += .3;
        //cout << "Vol: " << Sound.getVolume() << endl;
        if(i > 100){
            break;
        }
*/

    }
    return 0;
}
