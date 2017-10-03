# Data-Structure-Examples
This is a project that includes standard data structures as examples.
As I create these data structures I will update this project, I am starting with a doubly Linked List.

## Build Tools
* QT Creator (I use [QT Creator 5.9](https://download.qt.io/archive/qt/)).
* CMake Compiler (See the link: [CMake](https://cmake.org) is installed on the system.)
* MacOS Terminal (I use [iTerm 2](https://www.iterm2.com) as my preffered Terminal)

## Getting Started

### Building and Running the Project
This project is a C++ CMake project.
You'll notice that there are two CMakeLists.txt files, one on the root level, and one within each sub-project. This allows sub-projects to be easily added and removed from the parent project.

In this project I use QT Creator as my IDE, but this isn't required. You should be able to build and run from the command line / terminal if you wish. This can be accomplished using CMake, I provided a link to download this in the "Build Tools" section.

Below you will see the example QT project layout when opening the root-level CMakeLists.txt file within QT Creator.

![Example QT Project](https://github.com/CodyJLeeApps/Data-Structure-Examples/blob/master/readme_resources/qt_project_layout.png)

Once the project is opened in QT creator, you are able to run the project.
The main routine runs some example methods and outputs to the console.
You should see the output shown below when running the first time:

![Example Output](https://github.com/CodyJLeeApps/Data-Structure-Examples/blob/master/readme_resources/example_output.png)

## Next Steps

The advantage to using CMake in this case is that I can easily add sub-projects to this repository in the future.

I will be frequently updating this repository to include more data structures and algorithms in the future.