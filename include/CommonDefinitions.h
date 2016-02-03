//
// Created by bruh on 1/8/16.
//

#ifndef ROBOY_CONTROL_COMMONDEFINITIONS_H
#define ROBOY_CONTROL_COMMONDEFINITIONS_H

enum ControlMode {POSITION_CONTROL, FORCE_CONTROL};

enum STATUS {UNDEFINED=0, INITIALIZED, PREPROCESS_TRAJECTORY, TRAJECTORY_READY,TRAJECTORY_FAILED, TRAJECTORY_PLAYING, TRAJECTORY_DONE, INITIALIZE_ERROR};
enum SteeringCommand {STOP_TRAJECTORY=0,PLAY_TRAJECTORY,PAUSE_TRAJECTORY,REWIND_TRAJECTORY};
#endif //ROBOY_CONTROL_COMMONDEFINITIONS_H
