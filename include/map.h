#ifndef MAP_H
#define MAP_H

#include "raylib.h"
#include <stdbool.h>

#define MAP_WIDTH 800  
#define MAP_HEIGHT 450 

#define MAP_DIFFUSE 0

// enum para os tipos de bloco
typedef enum {
    NOTHING,
    BREAKABLE,
    HOLE,
    UPPERFLOOR,
    BUMPER,
    SPAWNER,
    UNBREAKABLE
} BlockType;

typedef BlockType MapBlock[MAP_WIDTH][MAP_HEIGHT];

// functions declaration
MapBlock MapGenerator_createMap(int width, int height, bool isHeight, bool isNotClassic);
void MapGenerator_loadMap(int width, int height, MapBlock map, const std::shared_ptr &scene);
void MapGenerator_createElement(Vector3f coords, std::shared_ptr scene, BlockType blockType);
void MapGenerator_generateUnbreakableBlock(int width, int height, std::shared_ptr scene);
void MapGenerator_generateWall(int width, int height, std::shared_ptr scene);
void MapGenerator_generateFloor(MapBlock map, int width, int height, std::shared_ptr scene);
void MapGenerator_createBreakable(Vector3f coords, std::shared_ptr scene);
void MapGenerator_createUnbreakable(Vector3f coords, std::shared_ptr scene);
void MapGenerator_createHole(Vector3f coords, std::shared_ptr scene);
void MapGenerator_createBumper(Vector3f coords, std::shared_ptr scene);
void MapGenerator_createUpperFloor(Vector3f coords, std::shared_ptr scene);
void MapGenerator_generateHeightCollision(MapBlock map, int width, int height, std::shared_ptr scene);
MapBlock MapGenerator_createClassicUnbreakable(MapBlock map, int width, int height);
MapBlock MapGenerator_createLongClassicUnbreakable(MapBlock map, int width, int height);
MapBlock MapGenerator_createSpawner(MapBlock map, int width, int height);
MapBlock MapGenerator_createHeight(MapBlock map, int width, int height);
MapBlock MapGenerator_cleanBreakable(MapBlock map, int width, int height);
bool MapGenerator_isCloseToBlockType(MapBlock map, int x, int y, int z, BlockType blockType);
BlockType MapGenerator_getRandomBlockType(bool hasHeight);

// constants and paths for the resource files
const char* MapGenerator_assetsPath;
const char* MapGenerator_wallAssetsPath;
const char* MapGenerator_imageExtension;
const char* MapGenerator_objExtension;
const char* MapGenerator_unbreakableWallPath;
const char* MapGenerator_outerWallPath;
const char* MapGenerator_breakableWallPath;
const char* MapGenerator_floorPath;
const char* MapGenerator_stairsPath;
const char* MapGenerator_bumperPath;
const char* MapGenerator_secondFloorPath;
const char* MapGenerator_holePath;
const char* MapGenerator_secondFloorHolePath;

#endif
