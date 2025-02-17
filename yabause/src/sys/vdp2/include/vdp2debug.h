/*  Copyright 2005-2008 Theo Berkau

    This file is part of Yabause.

    Yabause is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License, or
    (at your option) any later version.

    Yabause is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with Yabause; if not, write to the Free Software
    Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301  USA
*/

#ifndef VDP2DEBUG_H
#define VDP2DEBUG_H

#define VDP2_DEBUG_STRING_SIZE 2048

#ifdef __cplusplus
extern "C" {
#endif

void Vdp2DebugStatsRBG0(char *outstring, int *isenabled);
void Vdp2DebugStatsRBG1(char *outstring, int *isenabled);
void Vdp2DebugStatsNBG0(char *outstring, int *isenabled);
void Vdp2DebugStatsNBG1(char *outstring, int *isenabled);
void Vdp2DebugStatsNBG2(char *outstring, int *isenabled);
void Vdp2DebugStatsNBG3(char *outstring, int *isenabled);
void Vdp2DebugStatsSprite(char *outstring, int *isenabled);
void Vdp2DebugStatsGeneral(char *outstring, int *isenabled);
pixel_t *Vdp2DebugTexture(u32 screen, int * w, int * h);

#ifdef __cplusplus
}
#endif

#endif
