//  OldStream.h
//  ZipPatch
/*
 The MIT License (MIT)
 Copyright (c) 2016-2018 HouSisong
 
 Permission is hereby granted, free of charge, to any person
 obtaining a copy of this software and associated documentation
 files (the "Software"), to deal in the Software without
 restriction, including without limitation the rights to use,
 copy, modify, merge, publish, distribute, sublicense, and/or sell
 copies of the Software, and to permit persons to whom the
 Software is furnished to do so, subject to the following
 conditions:
 
 The above copyright notice and this permission notice shall be
 included in all copies of the Software.
 
 THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES
 OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
 NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT
 HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
 WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
 OTHER DEALINGS IN THE SOFTWARE.
 */
#ifndef ZipPatch_OldStream_h
#define ZipPatch_OldStream_h
#include "../../HDiffPatch/libHDiffPatch/HPatch/patch_types.h"
#include "Zipper.h"

//利用oldZip、refList模拟成一个输入流;
typedef struct OldStream{
    const hpatch_TStreamInput* stream;
//private:
    UnZipper*                   _oldZip;
    const hpatch_TStreamInput*  _input_refBuf;
    hpatch_TStreamInput         _stream;
} OldStream;

void OldStream_init(OldStream* self);
bool OldStream_open(OldStream* self,UnZipper* oldZip,
                    const uint32_t* refList,size_t refCount,
                    const hpatch_TStreamInput* input_refBuf,hpatch_TStreamOutput* output_refBuf);
void OldStream_close(OldStream* self);

#endif //ZipPatch_OldStream_h