/**
  ******************************************************************************
  * This file is part of the TouchGFX 4.16.0 distribution.
  *
  * <h2><center>&copy; Copyright (c) 2020 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under Ultimate Liberty license
  * SLA0044, the "License"; You may not use this file except in compliance with
  * the License. You may obtain a copy of the License at:
  *                             www.st.com/SLA0044
  *
  ******************************************************************************
  */

#include <platform/driver/lcd/LCD2bpp.hpp>
#include <touchgfx/Color.hpp>
#include <touchgfx/widgets/canvas/AbstractPainterGRAY2.hpp>

namespace touchgfx
{
void AbstractPainterGRAY2::render(uint8_t* ptr,
                                  int x,
                                  int xAdjust,
                                  int y,
                                  unsigned count,
                                  const uint8_t* covers)
{
    currentX = x + areaOffsetX;
    currentY = y + areaOffsetY;
    x += xAdjust;
    if (renderInit())
    {
        do
        {
            uint8_t gray, alpha;
            if (renderNext(gray, alpha))
            {
                const uint8_t combinedAlpha = LCD::div255((*covers) * LCD::div255(alpha * widgetAlpha));

                if (combinedAlpha == 0xFF) // max alpha=0xFF on "*covers" and max alpha=0xFF on "widgetAlpha"
                {
                    // Render a solid pixel
                    renderPixel(ptr, x, gray);
                }
                else
                {
                    const uint8_t p_gray = LCD2bpp::getPixel(ptr, x) * 0x55;
                    const uint8_t ialpha = 0xFF - combinedAlpha;
                    renderPixel(ptr, x, LCD::div255((gray * combinedAlpha + p_gray * ialpha) * 0x55) >> 6);
                }
            }
            covers++;
            x++;
            currentX++;
        } while (--count != 0);
    }
}

void AbstractPainterGRAY2::renderPixel(uint8_t* p, uint16_t offset, uint8_t gray)
{
    LCD2bpp::setPixel(p, offset, gray);
}
} // namespace touchgfx
