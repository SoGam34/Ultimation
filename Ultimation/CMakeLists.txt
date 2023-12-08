# Fügen Sie der ausführbaren Datei dieses Projekts eine Quelle hinzu.
add_executable ("Ultimation" "main.cpp")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET Ultimation PROPERTY CXX_STANDARD 20)
endif()