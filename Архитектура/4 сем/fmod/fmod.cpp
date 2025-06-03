#include <iostream>
#include <cstdlib>
#include <cmath>
#include <unistd.h>
#include "include/fmod.hpp"
#include "include/fmod_errors.h"

void ERRCHECK(FMOD_RESULT result) {
    if (result != FMOD_OK) {
        std::cerr << "FMOD error: " << FMOD_ErrorString(result) << std::endl;
        exit(EXIT_FAILURE);
    }
}

int main() {
    FMOD::System* system = nullptr;
    FMOD::Sound* sound = nullptr;
    FMOD::Channel* channel = nullptr;
    FMOD_RESULT result;

    result = FMOD::System_Create(&system);
    ERRCHECK(result);

    result = system->init(32, FMOD_INIT_3D_RIGHTHANDED, nullptr);
    ERRCHECK(result);

    result = system->createSound("sound.mp3", FMOD_3D | FMOD_LOOP_OFF, nullptr, &sound);
    ERRCHECK(result);

    result = system->playSound(sound, nullptr, false, &channel);
    ERRCHECK(result);

    FMOD_VECTOR pos = { 10.0f, 0.0f, 0.0f };
    FMOD_VECTOR vel = { 0.0f, 0.0f, 0.0f };
    result = channel->set3DAttributes(&pos, &vel);
    ERRCHECK(result);

    FMOD_VECTOR listenerPos = { 0.0f, 0.0f, 0.0f };
    FMOD_VECTOR listenerVel = { 0.0f, 0.0f, 0.0f };
    FMOD_VECTOR forward = { 0.0f, 0.0f, 1.0f };
    FMOD_VECTOR up = { 0.0f, 1.0f, 0.0f };
    result = system->set3DListenerAttributes(0, &listenerPos, &listenerVel, &forward, &up);
    ERRCHECK(result);

    FMOD::DSP* dspEcho = nullptr;
    result = system->createDSPByType(FMOD_DSP_TYPE_ECHO, &dspEcho);
    ERRCHECK(result);
    dspEcho->setParameterFloat(FMOD_DSP_ECHO_DELAY, 300.0f);
    dspEcho->setParameterFloat(FMOD_DSP_ECHO_FEEDBACK, 0.7f);

    FMOD::ChannelGroup* masterGroup = nullptr;
    system->getMasterChannelGroup(&masterGroup);
    masterGroup->addDSP(0, dspEcho);

    float angle = 0.0f;
    while (true) {
        pos.x = 10.0f * cos(angle);
        pos.z = 10.0f * sin(angle);
        angle += 0.01f;

        channel->set3DAttributes(&pos, &vel);
        system->update();

        usleep(10000); // 10 ms
    }

    sound->release();
    system->close();
    system->release();

    return 0;
}