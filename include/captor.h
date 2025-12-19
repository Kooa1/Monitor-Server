//
// Created by 66 on 2025/12/18.
//

#ifndef MONITORSERVER_CAPTOR_H
#define MONITORSERVER_CAPTOR_H

extern "C" {
#include <libavutil/log.h>
#include <libavcodec/avcodec.h>
#include <libavformat/avformat.h>
#include <libswscale/swscale.h>
#include <libavutil/imgutils.h>
}

#include <iostream>

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
    const AVInputFormat *av_input_format = nullptr;

};


#endif //MONITORSERVER_CAPTOR_H
