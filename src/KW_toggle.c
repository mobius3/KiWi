#include "KW_toggle.h"
#include "KW_tilerenderer.h"

typedef struct KW_Toggle {
  KW_bool pushed;
  KW_bool over;
} KW_Toggle;

void PaintToggle(KW_Widget * widget);
void DestroyToggle(KW_Widget * widget);
void MouseOver(KW_Widget * widget);
void MouseLeave(KW_Widget * widget);
void MousePress(KW_Widget * widget, int b);
void MouseRelease(KW_Widget * widget, int b);
KW_Toggle * AllocToggle();


KW_Widget * KW_CreateToggle(KW_GUI * gui, KW_Widget * parent, const KW_Rect * geometry) {
  KW_Toggle * tg = AllocToggle();
  KW_Widget * widget = KW_CreateWidget(gui, parent, KW_WIDGETTYPE_TOGGLE, geometry, PaintToggle, DestroyToggle, tg);
  tg->pushed = KW_FALSE;
  KW_AddWidgetMouseOverHandler(widget, MouseOver);
  KW_AddWidgetMouseLeaveHandler(widget, MouseLeave);
  KW_AddWidgetMouseDownHandler(widget, MousePress);
  KW_AddWidgetMouseUpHandler(widget, MouseRelease);
  return widget;
}

KW_bool KW_IsToggleChecked(KW_Widget * widget) {
  KW_Toggle * tg = KW_GetWidgetData(widget, KW_WIDGETTYPE_TOGGLE);
  return tg->pushed;
}

void KW_SetToggleChecked(KW_Widget * widget, KW_bool checked) {
  KW_Toggle * tg = KW_GetWidgetData(widget, KW_WIDGETTYPE_TOGGLE);
  tg->pushed = checked;
}

KW_Toggle * AllocToggle() {
  return calloc(sizeof(KW_Toggle), 1);
}

void PaintToggle(KW_Widget * widget) {
  KW_Toggle * tg = KW_GetWidgetData(widget, KW_WIDGETTYPE_TOGGLE);
  KW_Rect targetgeom;
  int column = 0;
  KW_RenderDriver * renderer = KW_GetWidgetRenderer(widget);
  KW_GetWidgetAbsoluteGeometry(widget, &targetgeom);
  if (tg->pushed) column = 3;
  if (tg->over) column += 6;
  KW_RenderTileFrame(renderer, KW_GetWidgetTilesetTexture(widget), 12, column, &targetgeom, KW_FALSE, KW_FALSE);
}
void DestroyToggle(KW_Widget * widget) {
  KW_Toggle * tg = KW_GetWidgetData(widget, KW_WIDGETTYPE_TOGGLE);
  free(tg);
}
void MouseOver(KW_Widget * widget) {
  KW_Toggle * tg = KW_GetWidgetData(widget, KW_WIDGETTYPE_TOGGLE);
  tg->over = (KW_bool) !tg->over;
}
void MouseLeave(KW_Widget * widget) {
  KW_Toggle * tg = KW_GetWidgetData(widget, KW_WIDGETTYPE_TOGGLE);
  tg->over = (KW_bool) !tg->over;
}
void MousePress(KW_Widget * widget, int b) {
  KW_Toggle * tg = KW_GetWidgetData(widget, KW_WIDGETTYPE_TOGGLE);
}
void MouseRelease(KW_Widget * widget, int b) {
  KW_Toggle * tg = KW_GetWidgetData(widget, KW_WIDGETTYPE_TOGGLE);
  tg->pushed = (KW_bool) !tg->pushed;
}

