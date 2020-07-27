#ifndef KW_BUTTON_INTERNAL_H
#define KW_BUTTON_INTERNAL_H

#include "kiwi/core/widget.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct KW_Button {
  KW_Widget * labelwidget; /* the label inside the button frame */
  KW_OldTexture * normal;
  KW_OldTexture * over;
} KW_Button;

#ifdef __cplusplus
}
#endif

#endif
