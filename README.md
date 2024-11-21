APT2090 Lab Practical 5 & 6
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>INSTALLATIONS</title>
</head>
<body>
    <h1>A.1 INSTALLING THE LIBRARIES AND DEVELOPMENT ENVIRONMENT</h1>
    
    <h3>Installing the Development Environment</h3>
    <p>Download and install Visual Studio 2022 on your machine. Make sure to select the C++ for desktop during installation.</p>

    <h3>Preparing GLFW</h3>
    <p>
        <ol>
            <li>Download the GLFW source code (<a href="http://www.glfw.org">www.glfw.org</a>). Unzip and move the folder to a suitable location. You can create “OpenGL_library_installation” under “Documents” (you can choose a different location if you prefer). Create also the subfolders “download” and “build.” Copy the unzipped GLFW folder into the “Download” folder.</li>
            <li>Download and install CMAKE (<a href="https://cmake.org">https://cmake.org</a>). During the installation, check the box that says “add to system path.”</li>
            <li>Run CMAKE and enter the GLFW source location and the desired build destination folder.
                <ul>
                    <li>Specify the source code as the downloaded GLFW folder.</li>
                    <li>Specify the build folder as the “build” folder you created in Step 1 (above).</li>
                </ul>
            </li>
            <li>Click “configure.” If you had properly installed Visual Studio, it should use that by default. If some of the options are highlighted in red, click “configure” again.</li>
            <li>Click “generate.”</li>
        </ol>
    </p>

    <p>CMAKE produces several files in the “build” folder. One of the files in that folder is named “GLFW.sln.” This is a Visual Studio project file. Open it (using Visual Studio), and compile (build) GLFW as a 64-bit application. If this is the first time running Visual Studio on this machine, it might be necessary to choose the “C++” configuration. The box at the top should say “x64.” Then choose “Build Solution” under the “Build” menu.</p>
    <p>The resulting build produces two items that you will need:
        <ul>
            <li>the glfw3.lib file, which is found in the src ► debug folder</li>
            <li>the “GLFW” folder, which is found in the original GLFW downloaded source code under the “include” folder. It contains two header files that you will use.</li>
        </ul>
    </p>


    <h3>Preparing GLM</h3>
    <p>A math library. Visit <a href="http://github.com/g-truc/glm">github.com/g-truc/glm</a> [GM23] and download the latest version that includes the release notes. The download folder, after being unzipped, consists of a folder named “glm.” Inside that folder is another folder also named “glm.” That folder (and its contents) is the item that you will need to use.</p>

    <h2>DEVELOPING AND DEPLOYING OPENGL PROJECTS IN VISUAL STUDIO</h2>

    <h3>Creating a Visual Studio Custom Project Template</h3>
    <p>Start Visual Studio (assuming it is the 2022 “Community” version). Create a new, empty C++ project (the name and location for this project do not matter – the default location is fine). At the top center, under the menu bar, there are two pull-down menus next to each other:
        <ul>
            <li>The one on the right allows you to specify “x86” or “x64” – choose “x64.”</li>
            <li>The one on the left allows you to specify whether compilation is to be done in “debug” mode or “release” mode. Several steps need to be done for BOTH modes. That is, they should be done in “debug” mode, and then repeated in “release” mode.</li>
        </ul>
    </p>
    <p>In “debug” mode (and then afterward in “release” mode), go into “project properties” and make the following changes:
        <ul>
            <li>Under “VC++ Directories” (it may alternatively say “C/C++”), then under “General,” and then under “Include Directories,” add the “include” folder you created previously.</li>
            <li>Under “linker,” there are two changes to make:
                <ul>
                    <li>Click on “General,” then under “Additional Library Directories,” add the “lib” folder you created previously.</li>
                    <li>Click on “Input,” then under “Additional Dependencies,” add the following four filenames: glfw3.lib, glew32.lib, soil2-debug.lib, and opengl32.lib (this last one should already be available as part of the standard Windows SDK). Separate the four file names with semicolons.</li>
                </ul>
            </li>
        </ul>
    </p>
    <p>After making the previous changes to the project properties, for both the “debug” and “release” modes, you are ready to create the template. This is done by going into the “Project” menu and selecting “Export template.” Choose that this is a “project” template, and give the template a useful name, such as “OpenGL project.” After doing this, you can close Visual Studio.</p>

    <h3>Using the Custom Project Template</h3>
    <p>Once the libraries are installed and the custom template is in place, creating a new OpenGL C++ project is straightforward:
        <ol>
            <li>Start Visual Studio, and click “Create a new project.”</li>
            <li>Choose your OpenGL template, then click “Next.” Note – The very first time that you try to use the template, you may need to search for it using the provided search tool.</li>
            <li>Give your project a name, select a location for the project, then click “Create.”</li>
            <li>Switch from “x86” to “x64” (if necessary) using the dropdown box at the top.</li>
            <li>Back in Windows, navigate to the folder that Visual Studio created that matches the name of your newly-created project.</li>
            <li>Copy any files that comprise your application into the subfolder. This includes any .cpp source files, .h header files, .glsl shader files, texture image files, and .obj 3D model files that your application uses. It is not necessary to specify any header files that were already built into the template.</li>
            <li>In the solution explorer (it could be on the left or the right), right-click on “Source Files” and choose Add►Existing item to load your main.cpp file. Repeat this process for other .cpp files.</li>
            <li>Also in the solution explorer, right-click on “Header Files” and choose Add►Existing item to load any header (.h) files in your application.</li>
            <li>You are now ready to build and execute your program.</li>
        </ol>
    </p>
</body>
</html>
