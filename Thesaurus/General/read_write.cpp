#ifndef C_READ_WRITE
#include "read_write.h"
#endif


namespace RW {
QString enumWToQStr (WriteResult wr)
{
    switch (wr) {
    case WriteResult::OK:
        return "OK";
    case WriteResult::Write:
        return "Write";
    case WriteResult::Open:
        return "Open";
    case WriteResult::Copy:
        return "Copy";
    case WriteResult::DelTmpWhileCopy:
        return "DelTmpWhileCopy";
    case WriteResult::DelSource:
        return "DelSource";
    case WriteResult::DelTmp:
        return "DelTmp";
    case WriteResult::RenameTmp:
        return "RenameTmp";
    default:
        return "Error";
    }
}
QString enumRToQStr (ReadResult rr)
{
    switch (rr) {
    case ReadResult::OK:
        return "OK";
    case ReadResult::DelTmp:
        return "DelTmp";
    case ReadResult::NotFound:
        return "NotFound";
    case ReadResult::Open:
        return "Open";
    case ReadResult::Read:
        return "Read";
    case ReadResult::RenameTmp:
        return "RenameTmp";
    default:
        return "Error";
    }
}
}

