# Source and Header Directories

## Abstract
So we now want have a good organization and the basiest way to achive is
divide the working space at least in the **source** and **header** directories.

## Introduction
The basic approach consist to create for each directory a `.pro` file with the
relative information to be include into the project. After that a `.pri` should
merge all them to build the project.

## Body
As the section intruduction explain, the two directory `source` and `include`
have been added to store in the first the sources of the project and in other
the header files. To achieve at this I created the `.pri` file in both
directories with the qmake statement to import the necessary file how specify
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

An other important thing is that now to include a header file in necessary use
the form of path: `#include 'include/my_header_file.h'` that is very stupid 
because if we want a unique directory for all header files, it's obviously that
they will be there. The fix to avoid the redundand inclusion is add to the
`INCLUDEPATH`  variable in the `.pro` file the paths in which they are stored:

```
// .pro
INCLUDEPATH += $$PWD/include
```

Now to include for example `game.h` it's enough writing: `#include 'game.h'`.

Perfect, but now the qmake are not knowing the file's location because it see
in the `.pro` file the declaration of the path but there isn't. To say it where
to found the files just include the `.pri` files location in the `.pro`:

```
// .pro
include(source/source.pri)
include(include/include.pri)
```

The image below show how to the final resault appears.

![Tree directory project]
(https://s21.postimg.org/inr7nv65z/creator_tree_project.png)

## Conclusion
We have a clean directory with the header files separte from the source files.

However us approach is **more different** than Qt Creator usally does. You can
create more directories with any topics about the game but you can not separete
their header and sourced files in two directories, because it puts all them
together, writes the relative path into the `.pro` files and then uses the
`HEADER` and `SOURCE` variables making an abstract separation to show in the
editor.

However Qt Creator is not so stupid. In fact to add a class it's enough click
on the virtual directories `Headers` and `Sources`, select the `add new...`
dropdown menu's option, complete the forms and Qt Creator will include in our
`.pri` files the header and source locations respectively.

Personally I prefer to do this instead to have directories with a pile of files
that I can see their separate only when I will use Qt Creator.

## Resources
[Creating an organized project with Qt Creator - QT Forum]
(https://forum.qt.io/topic/6814/solved-file-organization-creating-an-organized-project-with-qt-creator/5)

[How to add include path in Qt Creator? - Stack Overflow]
(http://stackoverflow.com/questions/2752352/how-to-add-include-path-in-qt-creator)

### Inherits
[master](https://github.com/korut94/MakeQtGame)

## History
* **Update the way to add a new class in the `Conclusion` section**
