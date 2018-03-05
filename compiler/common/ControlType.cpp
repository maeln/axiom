#include "ControlType.h"

#include <cassert>

using namespace MaximCommon;

std::string MaximCommon::controlType2String(ControlType type) {
    switch (type) {
        case ControlType::NUMBER:
            return "num";
        case ControlType::GRAPH:
            return "graph";
        case ControlType::MIDI:
            return "midi";
        case ControlType::ROLL:
            return "roll";
        case ControlType::NUM_EXTRACT:
            return "num[]";
        case ControlType::MIDI_EXTRACT:
            return "midi[]";
        default:
            assert(false);
            throw;
    }
}
