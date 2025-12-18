//
// Created by 66 on 2025/12/18.
//

#ifndef MONITORSERVER_CAPTOR_H
#define MONITORSERVER_CAPTOR_H

#include <iostream>

extern "C" {
#include <libavutil/log.h>
#include <libavcodec/avcodec.h>
#include <libavformat/avformat.h>
#include <libswscale/swscale.h>
#include <libavutil/imgutils.h>
}

#include "ffmpegfactory.h"
#include "av_err2str_cxx.h"

class Captor {
public:
    Captor();

    ~Captor() = default;

private:
    void init_context();

private:
    AVFormatContextPtr av_format_context;
    AVCodecContextPtr av_codec_context;

};


#endif //MONITORSERVER_CAPTOR_H
