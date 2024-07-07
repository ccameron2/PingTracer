/**
 * This file was generated by bin2cpp v3.0.0
 * Copyright (C) 2013-2021 end2endzone.com. All rights reserved.
 * bin2cpp is open source software, see http://github.com/end2endzone/bin2cpp
 * Source code for file 'Icon.png', last modified 1720258424.
 * Do not modify this file.
 */
#ifndef ICON_H
#define ICON_H

#include <stddef.h>

namespace bin2cpp
{
  #ifndef BIN2CPP_EMBEDDEDFILE_CLASS
  #define BIN2CPP_EMBEDDEDFILE_CLASS
  class File
  {
  public:
    virtual size_t getSize() const = 0;
    /* DEPRECATED */ virtual inline const char * getFilename() const { return getFileName(); }
    virtual const char * getFileName() const = 0;
    virtual const char * getFilePath() const = 0;
    virtual const char * getBuffer() const = 0;
    virtual bool save(const char * filename) const = 0;
  };
  #endif //BIN2CPP_EMBEDDEDFILE_CLASS
  const File & getIconPngFile();
}; //bin2cpp

#endif //ICON_H
