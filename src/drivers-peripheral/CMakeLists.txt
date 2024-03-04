add_library(lp50xx-i2c-driver-intf
    INTERFACE
    )

target_include_directories(lp50xx-i2c-driver-intf
    INTERFACE
    .
    )

target_link_libraries(lp50xx-i2c-driver-intf
    INTERFACE
    hal-intf
    )

add_library(lp50xx-i2c-driver
    OBJECT
    LP50xx-i2c-driver.cpp
    )

target_link_libraries(lp50xx-i2c-driver
    PUBLIC
    lp50xx-i2c-driver-intf
    PRIVATE
    core-conf
    hal-intf
    )