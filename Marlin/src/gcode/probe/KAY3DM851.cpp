/**
 * Marlin 3D Printer Firmware
 * Copyright (c) 2019 MarlinFirmware [https://github.com/MarlinFirmware/Marlin]
 *
 * Based on Sprinter and grbl.
 * Copyright (c) 2011 Camiel Gubbels / Erik van der Zalm
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
 *
 */

#include "../../inc/MarlinConfig.h"

#if HAS_BED_PROBE

#include "../gcode.h"
#include "../../feature/bedlevel/bedlevel.h"
#include "../../module/probe.h"

#if HAS_SPI_LCD
#include "../../lcd/ultralcd.h"
#endif


extern const char SP_Y_STR[], SP_Z_STR[];
//float mean = 0.0, sigma = 0.0, min = 99999.9, max = -99999.9;


/**
 * M851: Set the nozzle-to-probe offsets in current units
 */
//void GcodeSuite::M851() {
void GcodeSuite::KAY3DM851() {


  // Show usage with no parameters
  if (!parser.seen("XYZ")) {
      #if HAS_PROBE_XY_OFFSET
        #if HAS_SPI_LCD // Display M851 results in the status bar
      ui.status_printf_P(0, PSTR("Probe Offset : X%.02f, Y%.02f, Z%.02f"), float(probe.offset_xy.x), float(probe.offset_xy.y)/*, float(probe.offset_xy.z)*/);
      ui.return_to_status(); //returns to LCD's main status screen

        #else
        ui.status_printf_P(0, MSG_PROBE_OFFSET " X0 Y0 Z");
        #endif //end HAS_SPI_LCD
                        
      #endif
     // , probe_offset.z
    
      //);
    return;
  }
}
#endif // HAS_BED_PROBE
