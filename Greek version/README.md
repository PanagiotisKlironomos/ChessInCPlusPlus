# ChessInCPlusPlus
Chessboard Developed in C++. University project. A complete chessboard in command line Interface.
Because some specific libraries (`windows.h`) were used, the project can only be compiled in windows.

# How to compile

Inside the project directory

        g++ main.cpp -o main
        main.exe



# How to install gcc in Windows 10? (the easier way) by https://dev.to/


GCC, abbreviation for 'GNU C Compiler' (and not Gulf Cooperation Council, like I'd assumed) is a necessity if you (or your pesky college) is into C Programming.

Almost all Linux distros come pre-installed with it so they are out of the trouble. But for those of you who were constant users of Windows and Command Prompt, and never felt the necessity for a C compiler, GCC seems to come out of the blue and a tough nut to install. 1000 rage-quits later, I present you this article.

This article is written so that the installation process is made easier than most of the trashy articles I had to go through.

## [](#installation)Installation

1.  Go to [MinGW official website](http://www.mingw.org/) and click on 'Downloads' on the left panel. You'll be redirected to the site which hosts the files.
2.  Look for **mingw-get-setup.exe** for downloading. Download it and launch the installer. Accept the terms and move on.
3.  You'll now see that the installer is connecting to the Internet and downloading a lot of tiny and small files. Wait till it ends.
4.  Right when it ends (which won't take long), you'll be presented a window with title **MinGW Installation Manager**. You should be in the 'Basic Setup' tab by default when it launches. If not, click on **Basic Setup**.
5.  Out of the numerous check boxes presented to you on the right side, tick "**mingw32-gcc-g++-bin**". If you are prompted with a menu, click on Mark for Install.
6.  Then on the top left corner click on **Installation > Apply Changes**. And wait while it downloads a billion files and installs them.

[![MinGW Installation Manager](https://res.cloudinary.com/practicaldev/image/fetch/s--rPjjXRTg--/c_limit%2Cf_auto%2Cfl_progressive%2Cq_auto%2Cw_880/https://dev-to-uploads.s3.amazonaws.com/i/buyja9obbjs1x7p8h6cd.png)](https://res.cloudinary.com/practicaldev/image/fetch/s--rPjjXRTg--/c_limit%2Cf_auto%2Cfl_progressive%2Cq_auto%2Cw_880/https://dev-to-uploads.s3.amazonaws.com/i/buyja9obbjs1x7p8h6cd.png)

1.  Now you gotta edit your "Environment Variables" as well, so that gcc works in cmd no matter the file location.
2.  For that go to **Windows Explorer > Right click on This PC > Properties > Advanced system settings > Environment Variables** or you could just search for "Environment Variables" in Windows Search...
3.  At the bottom "System Variables" panel, look for a Variable named "Path" and double click on it. Some systems show a good UI for adding a New Path easily (by clicking New), else you just need to add ; at the end and add the following path  

        C:\MinGW\bin

    ###### [](#this-is-assuming-you-didnt-manually-change-any-installation-paths-and-went-with-just-clicking-next-during-installation)(This is assuming you didn't manually change any installation paths and went with just clicking 'Next' during installation)

4.  Click on OK, and OK and close the other windows. Open a Command Prompt Terminal and try typing `gcc --version` and press Enter.

    If you get something like  

        gcc (MinGW.org GCC Build-2) 9.2.0
        Copyright (C) 2019 Free Software Foundation, Inc.
        This is free software; see the source for copying conditions. 
        There is NO warranty; not even for MERCHANTABILITY or FITNESS
        FOR A PARTICULAR PURPOSE.

    gcc has been successfully installed in your PC. Enjoy!

Cheers and happy coding!

