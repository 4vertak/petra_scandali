#!/bin/bash
QT_VERSION=0.1.0
export QT_VERSION
QT_VER=0.1
export QT_VER
QT_VERSION_TAG=010
export QT_VERSION_TAG
QT_INSTALL_DOCS=/opt/homebrew/Cellar/qt@5/5.15.11/doc
export QT_INSTALL_DOCS
BUILDDIR=/Users/yronwooz/Downloads/QtGifImage-master/src/gifimage
export BUILDDIR
exec /opt/homebrew/Cellar/qt@5/5.15.11/bin/qdoc "$@"
