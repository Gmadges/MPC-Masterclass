
# MPC-Masterclass
implementing "Elastic and Plastic Deformations with Rigid Body Dynamics"

## Building
Building should be relatively painfree if you are family with QMAKE

If you want to use the Dark stylesheet, make sure to pull submodules.
```
git pull --recurse-submodules
```
Dependencies:
 * ASSIMP
 * Bullet Physics
 * OpenVDB
 * QT5

Check all include and lib paths point the correct locations. 
I have used the default library install locations for Ubuntu 16.04 for all dependencies.

build and run commands
```
$ qmake
$ make
```

### Building for debug
Include the "debug" flag in CONFIG (There by default).
```
CONFIG += console c++11 debug
```
launch command to run attached in debug with VSC is included.

### Building for release
Remove the "debug" flag from CONFIG
```
CONFIG += console c++11
```

## Running
After building 
```
$ ./a.out
```
Will execute the application.

models used for testing can be found within the models directory.