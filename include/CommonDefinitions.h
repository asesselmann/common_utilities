//
// Created by bruh on 1/8/16.
//

#ifndef ROBOY_CONTROL_COMMONDEFINITIONS_H
#define ROBOY_CONTROL_COMMONDEFINITIONS_H

enum ControlMode {UNDEFINED_CONTROL = 0, POSITION_CONTROL, VELOCITY_CONTROL, FORCE_CONTROL};

static const char * controlModeStrings[] = { "undefined", "position", "velocity", "force" };

static const char * getControlModeString(ControlMode mode) {
	return controlModeStrings[mode];
}

enum ControllerState {  UNDEFINED = 0,
                        INITIALIZED,
                        PREPROCESS_TRAJECTORY,
                        TRAJECTORY_READY,
                        TRAJECTORY_FAILED,
                        TRAJECTORY_PLAYING,
                        TRAJECTORY_PAUSED,
                        TRAJECTORY_DONE,
                        INITIALIZE_ERROR,
                        STOPPED};



//static const char * statusStrings[] = { "UNDEFINED", "INITIALIZED", "PREPROCESS_TRAJECTORY",
//                                        "TRAJECTORY_READY", "TRAJECTORY_FAILED", "TRAJECTORY_PLAYING",
//                                        "TRAJECTORY_DONE", "INITIALIZE_ERROR" };
//
//const char * getStatusString(int enumVal) {
//    return statusStrings[enumVal];
//}

enum SteeringCommand {STOP_TRAJECTORY=0,PLAY_TRAJECTORY,PAUSE_TRAJECTORY,REWIND_TRAJECTORY};
#endif //ROBOY_CONTROL_COMMONDEFINITIONS_H
