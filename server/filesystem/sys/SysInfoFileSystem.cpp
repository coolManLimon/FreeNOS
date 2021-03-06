/*
 * Copyright (C) 2019 Niek Linnenbank
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <Assert.h>
#include <File.h>
#include <Directory.h>
#include "SysInfoFileSystem.h"
#include "MountsFile.h"
#include "MountWaitFile.h"

SysInfoFileSystem::SysInfoFileSystem(const char *path)
    : FileSystem(path)
{
    Directory *dir = new Directory;
    assert(dir != NULL);
    setRoot(dir);

    MountsFile *mountsFile = new MountsFile;
    assert(mountsFile != NULL);
    registerFile(mountsFile, "mounts");

    MountWaitFile *mountWait = new MountWaitFile;
    assert(mountWait != NULL);
    registerFile(mountWait, "mountwait");
}
