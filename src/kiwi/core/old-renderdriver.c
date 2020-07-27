#include "kiwi/core/old-renderdriver.h"

void KW_BlitSurface(KW_OldRenderDriver * driver, KW_Surface * src, const KW_Rect * srcRect, KW_Surface * dst, const KW_Rect * dstRect) {
    driver->blitSurface(driver, src, srcRect, dst, dstRect);
}

KW_Surface * KW_CreateSurface(KW_OldRenderDriver * driver, unsigned width, unsigned height) {
    return driver->createSurface(driver, width, height);
}

void KW_GetSurfaceExtents(KW_OldRenderDriver * driver, const KW_Surface * surface, unsigned * width, unsigned * height) {
    driver->getSurfaceExtents(driver, surface, width, height);
}

void KW_GetTextureExtents(KW_OldRenderDriver * driver, KW_OldTexture * texture, unsigned * width, unsigned * height) {
    driver->getTextureExtents(driver, texture, width, height);
}

void KW_RenderCopy(KW_OldRenderDriver * driver, KW_OldTexture * src, const KW_Rect * clip, const KW_Rect * dstRect) {
    driver->renderCopy(driver, src, clip, dstRect);
}

KW_OldTexture * KW_RenderText(KW_OldRenderDriver * driver, KW_OldFont * font, const char * text, KW_Color color,
                              KW_RenderDriver_TextStyle style) {
    return driver->renderText(driver, font, text, color, style);
}

KW_OldTexture * KW_RenderTextWrapped(KW_OldRenderDriver * driver, KW_OldFont * font, const char * text, KW_Color color,
                                     KW_RenderDriver_TextStyle style, int wrapwidth) {
    return driver->renderTextWrapped(driver, font, text, color, style, wrapwidth);
}

void KW_RenderRect(KW_OldRenderDriver * driver, KW_Rect * rect, KW_Color color) {
    driver->renderRect(driver, rect, color);
}

KW_OldFont * KW_LoadFont(KW_OldRenderDriver * driver, const char * fontFile, unsigned ptSize) {
    return driver->loadFont(driver, fontFile, ptSize);
}

KW_OldFont * KW_LoadFontFromMemory(KW_OldRenderDriver * driver, const void * fontMemory, unsigned long memSize, unsigned ptSize) {
    return driver->loadFontFromMemory(driver, fontMemory, memSize, ptSize);
}

KW_OldTexture * KW_CreateTexture(KW_OldRenderDriver * driver, KW_Surface * surface) {
    return driver->createTexture(driver, surface);
}

KW_OldTexture * KW_LoadTexture(KW_OldRenderDriver * driver, const char * file) {
    return driver->loadTexture(driver, file);
}

KW_Surface * KW_LoadSurface(KW_OldRenderDriver * driver, const char * file) {
    return driver->loadSurface(driver, file);
}

KW_Surface * KW_LoadSurfaceFromMemory(KW_OldRenderDriver * driver, const char * file) {
  return driver->loadSurface(driver, file);
}

void KW_ReleaseTexture(KW_OldRenderDriver * driver, KW_OldTexture * texture) {
    driver->releaseTexture(driver, texture);
}

void KW_ReleaseSurface(KW_OldRenderDriver * driver, KW_Surface * surface) {
    driver->releaseSurface(driver, surface);
}

void KW_ReleaseFont(KW_OldRenderDriver * driver, KW_OldFont * font) {
    driver->releaseFont(driver, font);
}

void KW_SetClipRect(KW_OldRenderDriver * driver, const KW_Rect * clip, int force) {
  driver->setClipRect(driver, clip, force);
}
KW_bool KW_GetClipRect(KW_OldRenderDriver * driver, KW_Rect * clip) {
  return driver->getClipRect(driver, clip);
}
void KW_ReleaseRenderDriver(KW_OldRenderDriver * driver) {
    driver->release(driver);
}

void KW_UTF8TextSize(KW_OldRenderDriver * driver, KW_OldFont * font, const char * text, unsigned * width, unsigned * height) {
    driver->utf8TextSize(driver, font, text, width, height);
}

unsigned KW_GetPixel(KW_OldRenderDriver * driver, KW_Surface * surface, unsigned px, unsigned py) {
   return driver->getPixel(driver, surface, px, py);
}


static int imax(int i, int j) {
  return (i < j) ? j : i;
}

static int imin(int i, int j) {
  return (i < j) ? i : j;
}

KW_Color KW_MultiplyColor(KW_Color color, float amount) {
  KW_Color r;
  r.r = (unsigned char) imin(imax((int)(color.r * amount), 255), 0);
  r.g = (unsigned char) imin(imax((int)(color.g * amount), 255), 0);
  r.b = (unsigned char) imin(imax((int)(color.b * amount), 255), 0);
  r.a = color.a;
  return r;
}

void KW_GetViewportSize(KW_OldRenderDriver * driver, KW_Rect * rect) {
    driver->getViewportSize(driver, rect);
}
