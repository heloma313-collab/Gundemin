# Çiftka Min — Unreal Engine 5 Android

This folder contains a native Unreal Engine project scaffold, separate from the earlier browser prototype in the repository root.

## Open the project
1. Install Unreal Engine **5.8** on a Windows development PC.
2. Open `CiftkaMin.uproject` in Unreal Editor.
3. Allow Unreal to generate project files and compile the C++ module.
4. Select **Mobile / Scalable** quality and test with Mobile Preview.

## Current prototype
- Orthographic isometric camera pawn.
- Touch and mouse selection controller.
- Clickable animal actors with simple product counters.
- Clickable crop plots with plant/harvest toggle.
- A basic test farm spawned from Unreal primitive meshes.

## Important limitation
This is a **source project scaffold**, not a finished commercial-quality game or an APK. Current animal/building meshes are temporary primitive placeholders. Village-and-Farm visual quality requires authored/imported 3D animal, building, terrain, foliage, animation, sound and UI assets, plus lighting and mobile optimization. Those binary Unreal assets cannot be produced merely by adding C++ text files to GitHub. The project has not yet been compiled in Unreal Editor.

## Android build
Install Android Studio and the Android SDK/NDK supported by your Unreal version. Configure the Android SDK in Unreal and accept the SDK licenses, then use **Platforms → Android → Package Project**. Epic's current Android requirements and packaging workflow:
- https://dev.epicgames.com/documentation/unreal-engine/android-development-requirements-for-unreal-engine
- https://dev.epicgames.com/documentation/en-us/unreal-engine/packaging-android-projects-in-unreal-engine

## Project structure
```
CiftkaMin.uproject
Config/
Source/CiftkaMin/
  MinFarmPawn.*             # orthographic isometric camera
  MinFarmPlayerController.* # touch/mouse interaction
  MinFarmAnimal.*           # animal actor interactions
  MinFarmPlot.*             # crop plot interaction
  MinFarmGameMode.*         # test farm spawn
```
