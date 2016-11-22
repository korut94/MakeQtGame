# Source and Header Directories

## Abstract
So now we want have a good organization and the basiest way to achive it is
divided the working space at least in two directories: **source** and **header**.
The `source` directory keeps all source files (*.c* and *.cpp*) whereas the `header` all
header files (*.h*).

## Introduction
The basic approach consist in the creation of a `.pro` file on the project's root with
the relative information on how to build project. Inside there, two `include`
declarations points at the `.pri` files (one for the `source` directory and an other for
`header` directory) that maintains the track all of files have to include during the
compilation time.

## Body
Like the section *Intruduction* explains, the two directory `source` and `include`
have been added to store in the first the sources of the project and in the second
the header files. To achieve at this I created the `.pri` file in both
directories with the qmake statements to import the necessary files, as specify
below:

```
// source.pri
SOURCES += source/game.cpp \
           source/main.cpp
```

```
// include.pri
HEADERS += include/game.h \
```

Perfect, but now qmake are not knowing the file's location because it see in the `.pro` file
and it doesn't find anything informations about the position of the files to compile. To say it
where to search just add into the `.pro` file the qmake's include declaration with the `.pri`
files' position:

```
// .pro
include(source/source.pri)
include(include/include.pri)
```

However if I only do this, I will bump into an unpleasant surprise: to include a
header declaration I should use the form `#include "include/my_header_file.h"`
that is a very redundant way because if we want a unique directory for all header files,
it's obviously that all header files start from the `include` directory. 
To avoid the borigin problem is necessary add still in the `.pro` file the `INCLUDEPATH`
statement with the `include` directory's path:

```
// .pro
INCLUDEPATH += $$PWD/include
```

Now for example to include `game.h` just writing: `#include "game.h"`.

The image below show how to the final resault appears.

![Tree directory project]
(https://s21.postimg.org/inr7nv65z/creator_tree_project.png)

## Conclusion
Finally, we have a clean project with the header files separte from the source files.

However us approach is **more different** than Qt Creator usally does. You can
create many sub-directories but when you want create a new class it always tries to put its
header and source file in the same directory.

However Qt Creator is not so stupid. In fact it allows you to add at the directory 
a header or source file where a `.pri` file resides and then it will write their path automatically
into the directory's `.pri` file chosed as destination. In this way it's more confortable than
to put the files **singularly and manually**!!  

Personally I prefer to do this instead to have directories with a pile of files
that I can see the header and source files separated only when I use Qt Creator.

## Resources
[Creating an organized project with Qt Creator - QT Forum]
(https://forum.qt.io/topic/6814/solved-file-organization-creating-an-organized-project-with-qt-creator/5)

[How to add include path in Qt Creator? - Stack Overflow]
(http://stackoverflow.com/questions/2752352/how-to-add-include-path-in-qt-creator)

### Inherits
[master](https://github.com/korut94/MakeQtGame)

## History
* **Update the way to add a new class in the `Conclusion` section** - 2016-11-16
