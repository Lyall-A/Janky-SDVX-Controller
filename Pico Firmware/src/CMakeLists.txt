add_executable(Janky-SDVX-Controller
        Janky-SDVX-Controller.c
        usb_descriptors.c)

target_include_directories(Janky-SDVX-Controller PRIVATE ${CMAKE_CURRENT_LIST_DIR})

pico_generate_pio_header(Janky-SDVX-Controller ${CMAKE_CURRENT_LIST_DIR}/encoders.pio)
# pico_generate_pio_header(Pico_Game_Controller ${CMAKE_CURRENT_LIST_DIR}/ws2812.pio)
target_sources(Janky-SDVX-Controller PRIVATE Janky-SDVX-Controller.c)

target_link_libraries(Janky-SDVX-Controller PRIVATE
        pico_multicore
        pico_stdlib
        tinyusb_device
        tinyusb_board
        hardware_pio
        hardware_dma
        hardware_irq)

pico_add_extra_outputs(Janky-SDVX-Controller)

add_custom_command(TARGET Janky-SDVX-Controller
        POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy ${PROJECT_BINARY_DIR}/src/Janky-SDVX-Controller.uf2 ${PROJECT_SOURCE_DIR}/Janky-SDVX-Controller.uf2
)

add_compile_definitions(
    PICO_XOSC_STARTUP_DELAY_MULTIPLIER=64
)