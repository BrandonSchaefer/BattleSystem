#find_package (PkgConfig)

#set (BATTLE_SYSTEM_REQUIRED
#    )

#pkg_check_modules(BATTLE_SYSTEM REQUIRED ${BATTLE_SYSTEM_REQUIRED})

set (BATTLE_SYSTEM_LOADER_SRC
     items/Armor.cpp
     items/Item.cpp
     items/Shield.cpp
     items/Weapon.cpp
     BattleSystem.cpp
     Character.cpp
     Charisma.cpp
     Class.cpp
     Constitution.cpp
     Dexterity.cpp
     Dice.cpp
     DiceFactory.cpp
     Direction.cpp
     Equipment.cpp
     Fighter.cpp
     Intelligence.cpp
     Inventory.cpp
     Human.cpp
     Race.cpp
     RandomNumberGenerator.cpp
     Strength.cpp
     MoneyPouch.cpp
     Monster.cpp
     Point.cpp
     UnitGroup.cpp
     Wisdom.cpp
     main.cpp
    )

set (BATTLE_SYSTEM_LOADER_HDR
     items/Armor.h
     items/Item.h
     items/Shield.h
     items/Weapon.h
     items/WeaponBreed.h
     BattleSystem.h
     Character.h
     CharacterStats.h
     Charisma.h
     Class.cpp
     Constitution.h
     Dexterity.h
     Dice.h
     DiceFactory.h
     Direction.h
     Equipment.h
     Fighter.h
     Intelligence.h
     Inventory.h
     Human.h
     MoneyPouch.h
     Monster.h
     Point.h
     Race.h
     RandomNumberGenerator.h
     Strength.h
     Unit.h
     UnitGroup.h
     Wisdom.h
    )

include_directories (${BATTLE_SYSTEM_INCLUDE_DIRS} ${CMAKE_BINARY_DIR})

add_library (battle_system_lib ${BATTLE_SYSTEM_LOADER_SRC} ${BATTLE_SYSTEM_LOADER_HDR})
#add_executable (battle_system ${BATTLE_SYSTEM_LOADER_SRC} ${BATTLE_SYSTEM_LOADER_HDR})

#target_link_libraries (battle_system ${BATTLE_SYSTEM_LIBRARIES} ${BATTLE_SYSTEM_LDFLAGS})
