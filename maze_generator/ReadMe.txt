========================================================================
    CONSOLE APPLICATION : maze_generator Project Overview
========================================================================

The goal of application is to generate randomized mazes based on various algorithms

The result will be presented as either 
-Graph object (adjacency list) containing all the paths and implicitly walls
-2D array (Matrix) ,a visual representation of maze (ready to be exported to for eg a bitmap file) #TODO to be considered


Maze generation is based on graph representation of the Grid (each Vertex has 4 Edges to 4 adjacent Vertexes) or different structure (for eg A triangle)

AppWizard has created this maze_generator application for you.

This file contains a summary of what you will find in each of the files that
make up your maze_generator application.


maze_generator.vcxproj
    This is the main project file for VC++ projects generated using an Application Wizard.
    It contains information about the version of Visual C++ that generated the file, and
    information about the platforms, configurations, and project features selected with the
    Application Wizard.

maze_generator.vcxproj.filters
    This is the filters file for VC++ projects generated using an Application Wizard. 
    It contains information about the association between the files in your project 
    and the filters. This association is used in the IDE to show grouping of files with
    similar extensions under a specific node (for e.g. ".cpp" files are associated with the
    "Source Files" filter).

maze_generator.cpp
    This is the main application source file.

/////////////////////////////////////////////////////////////////////////////
Other standard files:

StdAfx.h, StdAfx.cpp
    These files are used to build a precompiled header (PCH) file
    named maze_generator.pch and a precompiled types file named StdAfx.obj.

/////////////////////////////////////////////////////////////////////////////
Other notes:

AppWizard uses "TODO:" comments to indicate parts of the source code you
should add to or customize.

/////////////////////////////////////////////////////////////////////////////
