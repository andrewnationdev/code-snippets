// Finite State Machine
enum States {
    IDLE_STATE,
    RUNNING_STATE,
    PAUSED_STATE,
    ERROR_STATE
};

enum Events {
    START_EVENT,
    PAUSE_EVENT,
    RESUME_EVENT,
    ERROR_EVENT,
    RESET_EVENT
};

States current_state = States::IDLE_STATE;

void handle_event(Events event){
    switch(current_state){
        case States::IDLE_STATE:
            if(event == Events::START_EVENT)
                current_state = States::RUNNING_STATE;

            if(event == Events::ERROR_EVENT)
                current_state = States::ERROR_STATE;
            break;
        case States::RUNNING_STATE:
            if(event == Events::PAUSE_EVENT)
                current_state = States::PAUSED_STATE;

            if(event == Events::ERROR_EVENT)
                current_state = States::ERROR_STATE;
            break;
        case States::PAUSED_STATE:
            if(event == Events::RESUME_EVENT)
                current_state = States::RUNNING_STATE;

            if(event == Events::RESET_EVENT)
                current_state = States::IDLE_STATE;
            break;
        case States::ERROR_STATE:
            if(event == Events::RESET_EVENT)
                current_state = States::IDLE_STATE;
            break;
    }
}

int main(){
    return 0;
}