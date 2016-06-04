#NOTES

##AMPLITUDE ARTIFACTS

It appears the when applying fast attack directly to SFLM's setVolume(), the output is glitched, however sound appears to improve a lot when envelope applied directly to the buffer. I guess sf::Stream is the way to go.

##SOLUTION

Discarded SMFL audio implemntation. Instead ALSA library gives better results, the amplitude decrease sounds smoother and and it allows to update the buffer on a fly. 
