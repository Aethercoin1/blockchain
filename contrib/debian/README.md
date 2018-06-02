
Debian
====================
This directory contains files used to package aethercoind/aethercoin-qt
for Debian-based Linux systems. If you compile aethercoind/aethercoin-qt yourself, there are some useful files here.

## aethercoin: URI support ##


aethercoin-qt.desktop  (Gnome / Open Desktop)
To install:

	sudo desktop-file-install aethercoin-qt.desktop
	sudo update-desktop-database

If you build yourself, you will either need to modify the paths in
the .desktop file or copy or symlink your aethercoin-qt binary to `/usr/bin`
and the `../../share/pixmaps/aethercoin128.png` to `/usr/share/pixmaps`

aethercoin-qt.protocol (KDE)

