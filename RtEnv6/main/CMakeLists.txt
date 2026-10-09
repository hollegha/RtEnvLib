
# ../../app/gyro/GyroControl_main.cpp
# ../../app/gyro

idf_component_register( SRCS PatzDemo1.cpp
                                                                                                 
  INCLUDE_DIRS "."
               "../components/inl_comp" 
               "../components/RtEnvHL/commu"
               "../components/RtEnvHL/core"
               "../components/RtEnvHL/led_strip"

  # target_compile_definitions(${COMPONENT_LIB} PRIVATE USE_UDP=1)
)

