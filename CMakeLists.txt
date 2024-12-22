cmake_minimum_required(VERSION 3.16)

project(projectlibrarymanagement LANGUAGES C)

add_executable(projectlibrarymanagement main.c
    admin.h
    admin.c
    book.h
    book.c
    borrowedbook.h
    borrowedbook.c
    main1.h
    main1.c
    returnedbook.h
    returnedbook.c
    sortbybookname.h
    sortbybookname.c
    sortbyauthor.h
    sortbyauthor.c
    staff.h
    staff.c
    student.h
    student.c
    filehanding.h
    filehanding.c)

include(GNUInstallDirs)
install(TARGETS projectlibrarymanagement
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
