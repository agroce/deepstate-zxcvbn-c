#include <deepstate/DeepState.hpp>

using namespace deepstate;

#include "zxcvbn.h"

#define MAX_PASSWORD 1024
#define MAX_USER_DICT 64
#define MAX_DICT_ENTRY 64

TEST(Zxcvbn, Basic) {
  ASSERT (ZxcvbnInit("zxcvbn.dict")) << "Failed to initalize!";

  const char* pwd = DeepState_CStrUpToLen(MAX_PASSWORD);

  const char* udict[MAX_USER_DICT];
  size_t i = 0;
  for (; i < MAX_USER_DICT-1; i++) {
    if (DeepState_Bool()) {
      break;
    }
    udict[i] = DeepState_CStrUpToLen(MAX_DICT_ENTRY);						       
  }
  udict[i] = NULL;

  ZxcMatch_t *Info;

  double d;

  OneOf(
	[&] {
	  d = ZxcvbnMatch(pwd, udict, &Info);
	},
	[&] {
	  d = ZxcvbnMatch(pwd, udict, 0);
	},
	[&] {
	  d = ZxcvbnMatch(pwd, 0, &Info);
	},
	[&] {
	  d = ZxcvbnMatch(pwd, 0, 0);
	});

  ZxcvbnUnInit();
}
