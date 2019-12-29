cmake_minimum_required(VERSION 3.14)
project(srcs C)

set(CMAKE_C_STANDARD 11)

add_executable(srcs
        add.c
        aff.c
        and.c
        errors.c
        exit_functions.c
        fork.c
        get_args.c
        get_filenames.c
        help_main_alg.c
        help_parser.c
        insert_next.c
        iss.c
        ld.c
        ldi.c
        lfork.c
        live.c
        lld.c
        lldi.c
        main_alg.c
        move_and_do.c
        next_proves.c
        num_args_prove.c
        or.c
        overflow_numbers_prove.c
        parser.c
        previous_prove.c
        print_hex.c
        print_map.c
        prove_blocks.c
        prove_duples.c
        prove_files.c
        prove_nulls.c
        prove_num_position.c
        proves.c
        range_filenames.c
        set_movement.c
        set_timer.c
        st.c
        sti.c
        sub.c
        temp_main.c
        what_arg.c
        xor.c
        zjmp.c)
