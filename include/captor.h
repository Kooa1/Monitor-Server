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
#include <fstream>

#include "ffmpegfactory.h"
#include "av_err2str_cxx.h"

using std::cout;

class Captor {
public:
    Captor();

    ~Captor() = default;

private:
    void avfoundation_devices_list();

    void init_context();

private:
    AVFormatContextPtr av_format_context;
    AVCodecContextPtr av_codec_context;
    AVStreamPtr video_stream;
    SwsContextPtr sws_context;
    const AVInputFormat *av_input_format = nullptr;
    const AVCodec *av_codec = nullptr;
    int video_index;
};


#endif //MONITORSERVER_CAPTOR_H
