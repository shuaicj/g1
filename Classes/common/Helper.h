#ifndef _GG_HELPER_H_
#define _GG_HELPER_H_

#include "Common.h"

NAMESPACE_GG_BEGIN

// 用layer调用Director的runWithScene
void RunWithLayer(cc::Layer* layer);

// 用layer调用Director的replaceScene
void ReplaceLayer(cc::Layer* layer);

NAMESPACE_GG_END

#endif // _GG_HELPER_H_
