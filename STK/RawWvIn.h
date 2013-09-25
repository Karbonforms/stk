/*******************************************/
/*  RawWvIn Input Class,                   */
/*  by Gary P. Scavone, 1999               */
/*                                         */
/*  This object inherits from WvIn and is  */
/*  used to open raw 16-bit data (signed   */
/*  integer) files for playback.           */
/*                                         */
/*  STK RawWave files are assumed to be    */
/*  big-endian.                            */
/*******************************************/

#if !defined(__RawWvIn_h)
#define __RawWvIn_h

#include "Object.h"
#include "WvIn.h"

class RawWvIn : public WvIn
{
  public:
    RawWvIn(char *fileName, char *mode);
    ~RawWvIn();
};

#endif
