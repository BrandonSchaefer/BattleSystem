find_package (PkgConfig)

set (BATTLE_SYSTEM_REQUIRED
     sdl2
     SDL2_image
     SDL2_ttf
     sigc++-2.0
    )

pkg_check_modules(BATTLE_SYSTEM REQUIRED ${BATTLE_SYSTEM_REQUIRED})

set (BATTLE_SYSTEM_LOADER_SRC
     BattleGrid.cpp
     Grid.cpp
     PathFinder.cpp
     SDLBackend.cpp
     SDLTimer.cpp
     Tile.cpp
     UnitView.cpp
     main.cpp
    )

set (BATTLE_SYSTEM_LOADER_HDR
     BattleGrid.h
     Grid.h
     PathFinder.h
     SDLBackend.h
     SDLTimer.h
     Tile.h
     UnitView.h
    )

include_directories (${BATTLE_SYSTEM_SOURCE_DIR}/src ${BATTLE_SYSTEM_INCLUDE_DIRS} ${CMAKE_BINARY_DIR})

add_executable (battle_system ${BATTLE_SYSTEM_LOADER_SRC} ${BATTLE_SYSTEM_LOADER_HDR})

target_link_libraries (battle_system battle_system_lib ${BATTLE_SYSTEM_LIBRARIES} ${BATTLE_SYSTEM_LDFLAGS})
