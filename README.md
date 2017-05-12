# CarND-Controls-PID
Self-Driving Car Engineer Nanodegree Program

In this project we are implementing a simple PID controller to help a car navigate through a simulated environment. The controller receives cross track error(cte) feedback and that is fed into a PID controller. This project is used in conjunction with Udacity drive simulator. (Available from the forked repository downloads)

## PID Parameters

There are two PID controllers that are used in the vehicle motion. The first controller handles the steering angles and the second controls the throttle. The CTE for the steering controller provides the error that needs to be minimized in order to steer within the lanes. The second controller uses the CTE to monitor the speed of the vehicle. If the CTE is large enough, we want to reduce the throttle allowing us to steer through corners faster.

The parameters were selected manually following the following directions [SO Post](https://robotics.stackexchange.com/questions/167/what-are-good-strategies-for-tuning-pid-loops)

Repeated here;

* Set all gains to zero.
* Increase the P gain until the response to a disturbance is steady oscillation.
* Increase the D gain until the the oscillations go away (i.e. it's critically damped).
* Repeat steps 2 and 3 until increasing the D gain does not stop the oscillations.
* Set P and D to the last stable values.
* Increase the I gain until it brings you to the setpoint with the number of oscillations desired (normally zero but a quicker response can be had if you don't mind a couple oscillations of overshoot)

We make the assumption that there is no systematic bias and therefore the Ki = 0 and the last step can be ignored.


## Dependencies

* cmake >= 3.5
 * All OSes: [click here for installation instructions](https://cmake.org/install/)
* make >= 4.1
  * Linux: make is installed by default on most Linux distros
  * Mac: [install Xcode command line tools to get make](https://developer.apple.com/xcode/features/)
  * Windows: [Click here for installation instructions](http://gnuwin32.sourceforge.net/packages/make.htm)
* gcc/g++ >= 5.4
  * Linux: gcc / g++ is installed by default on most Linux distros
  * Mac: same deal as make - [install Xcode command line tools]((https://developer.apple.com/xcode/features/)
  * Windows: recommend using [MinGW](http://www.mingw.org/)
* [uWebSockets](https://github.com/uWebSockets/uWebSockets) == 0.13, but the master branch will probably work just fine
  * Follow the instructions in the [uWebSockets README](https://github.com/uWebSockets/uWebSockets/blob/master/README.md) to get setup for your platform. You can download the zip of the appropriate version from the [releases page](https://github.com/uWebSockets/uWebSockets/releases). Here's a link to the [v0.13 zip](https://github.com/uWebSockets/uWebSockets/archive/v0.13.0.zip).
  * If you run OSX and have homebrew installed you can just run the ./install-mac.sh script to install this
* Simulator. You can download these from the [project intro page](https://github.com/udacity/CarND-PID-Control-Project/releases) in the classroom.

## Basic Build Instructions

1. Clone this repo.
2. Make a build directory: `mkdir build && cd build`
3. Compile: `cmake .. && make`
4. Run it: `./pid`.
