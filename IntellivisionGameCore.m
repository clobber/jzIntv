/*
 Copyright (c) 2013, OpenEmu Team


 Redistribution and use in source and binary forms, with or without
 modification, are permitted provided that the following conditions are met:
     * Redistributions of source code must retain the above copyright
       notice, this list of conditions and the following disclaimer.
     * Redistributions in binary form must reproduce the above copyright
       notice, this list of conditions and the following disclaimer in the
       documentation and/or other materials provided with the distribution.
     * Neither the name of the OpenEmu Team nor the
       names of its contributors may be used to endorse or promote products
       derived from this software without specific prior written permission.

 THIS SOFTWARE IS PROVIDED BY OpenEmu Team ''AS IS'' AND ANY
 EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 DISCLAIMED. IN NO EVENT SHALL OpenEmu Team BE LIABLE FOR ANY
 DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
  LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
 ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#import "IntellivisionGameCore.h"
#import "OEIntellivisionSystemResponderClient.h"

#import <OpenEmuBase/OERingBuffer.h>
#import <OpenGL/gl.h>

#include "config.h"
#include "plat/plat.h"
#include "file/file.h"
#include "periph/periph.h"
#include "cp1600/cp1600.h"
#include "mem/mem.h"
#include "icart/icart.h"
#include "bincfg/bincfg.h"
#include "bincfg/legacy.h"
#include "pads/pads.h"
#include "pads/pads_cgc.h"
#include "pads/pads_intv2pc.h"
#include "gfx/gfx.h"
#include "snd/snd.h"
#include "ay8910/ay8910.h"
#include "demo/demo.h"
#include "stic/stic.h"
#include "speed/speed.h"
#include "debug/debug_.h"
#include "event/event.h"
#include "ivoice/ivoice.h"
#include "jlp/jlp.h"
#include "cfg/mapping.h"
#include "cfg/cfg.h"

@interface IntellivisionGameCore () <OEIntellivisionSystemResponderClient>
{
    uint32_t *videoBuffer;
}
@end

IntellivisionGameCore *current;
@implementation IntellivisionGameCore

- (id)init
{
    if((self = [super init]))
    {
        videoBuffer = (uint32_t *)malloc(160 * 200 * 4);
        current = self;
    }
    
    return self;
}

- (void)dealloc
{
    free(videoBuffer);
}

#pragma mark Execution

- (BOOL)loadFileAtPath:(NSString *)path
{
    int argc = 3;
    char *argv[] = {
        "./jzintv",
        (char *)[[NSString stringWithFormat:@"%@%@", @"--rom-path=", [self biosDirectoryPath]] UTF8String],
        (char *)[path UTF8String]
    };
    
    //plat_init();
    cfg_init(&intv, argc, argv);
    //NSLog(@"*****game: %s", intv.fn_game);
    init_disp_width(0);
    //jzp_flush();
    
    return YES;
}

- (void)executeFrame
{
    [self executeFrameSkippingFrame:NO];
}

- (void)executeFrameSkippingFrame:(BOOL)skip
{
	periph_tick((periph_p)(intv.intv), 5); // ?
}

- (void)resetEmulation
{
    
}

#pragma mark Video

- (OEIntRect)screenRect
{
    return OEIntRectMake(0, 0, 320, 240);
}

- (OEIntSize)bufferSize
{
    return OEIntSizeMake(320, 240);
}

- (const void *)videoBuffer
{
    return NULL;
}

- (GLenum)pixelFormat
{
    return GL_BGRA;
}

- (GLenum)pixelType
{
    return GL_UNSIGNED_INT_8_8_8_8_REV;
}

- (GLenum)internalPixelFormat
{
    return GL_RGB8;
}

- (NSTimeInterval)frameInterval
{
    return 59.92;
}

#pragma mark Audio

- (NSUInteger)channelCount
{
    return 1;
}

- (double)audioSampleRate
{
    return 48000;
}

#pragma mark Input

- (oneway void)didPushIntellivisionButton:(OEIntellivisionButton)button forPlayer:(NSUInteger)player;
{
    
}

- (oneway void)didReleaseIntellivisionButton:(OEIntellivisionButton)button forPlayer:(NSUInteger)player;
{
    
}

- (BOOL)saveStateToFileAtPath:(NSString *)fileName
{
    return NO;
}

- (BOOL)loadStateFromFileAtPath:(NSString *)fileName
{
    return NO;
}

@end
