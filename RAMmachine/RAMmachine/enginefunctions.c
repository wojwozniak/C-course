typedef struct engine {
    bool turned_on;
    struct memory_cell *battery;
    unsigned int amount_of_exes;
} engine;

// Create new engine and attach battery to it
engine *create_engine(memory_cell *battery) {
    engine *output = malloc(sizeof(engine));
    if(output != NULL) {
        output->turned_on = false;
        output->battery = battery;
        output->amount_of_exes = 0;
    }
    return output;
}

// Turn on engine
void turn_on_engine(engine *engine) {
    engine->turned_on = true;
}

// Turn off engine
void turn_off_engine(engine *engine) {
    engine->turned_on = false;
}

// Check if engine is turned on
bool is_engine_on(engine *engine) {
    return engine->turned_on;
}

void execute_command(engine *engine, char command[6], char payload[10]) {
    if(strcmp(command, "LOAD") == 0) {
        ram_load(engine, command, payload);
        return;
    }
    if(strcmp(command, "STORE") == 0) {
        ram_store(engine, command, payload);
        return;
    }
    if(strcmp(command, "ADD") == 0) {
        ram_add(engine, command, payload);
        return;
    }
    if(strcmp(command, "SUB") == 0) {
        ram_sub(engine, command, payload);
        return;
    }
    if(strcmp(command, "MULT") == 0) {
        ram_mult(engine, command, payload);
        return;
    }
    if(strcmp(command, "DIV") == 0) {
        ram_div(engine, command, payload);
        return;
    }
    if(strcmp(command, "JUMP") == 0) {
        ram_jump(engine, command, payload);
        return;
    }
    if(strcmp(command, "JZERO") == 0) {
        ram_jzero(engine, command, payload);
        return;
    }
    if(strcmp(command, "JGTZ") == 0) {
        ram_jgtz(engine, command, payload);
        return;
    }
    if(strcmp(command, "READ") == 0) {
        ram_read(engine, command, payload);
        return;
    }
    if(strcmp(command, "WRITE") == 0) {
        ram_write(engine, command, payload);
        return;
    }
    if(strcmp(command, "HALT") == 0) {
        ram_halt(engine, command, payload);
        return;
    }

}

// Run single engine cycle with a tape
void engine_cycle(engine *engine, exe *tape) {
    int current_exe_id = engine->amount_of_exes + 1;
    exe *current_task = find_exe_with_id(tape, current_exe_id);
    char command[6];
    strcpy(command, current_task->command);
    char payload[10];
    strcpy(payload, current_task->payload);
    execute_command(engine, command, payload);
    engine->amount_of_exes+=1;
    return;
}
